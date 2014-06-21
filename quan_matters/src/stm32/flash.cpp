#include <quan/stm32/flash.hpp>
#include <quan/stm32/detail/flash.hpp>
#include <cstring>
#include <quan/error.hpp>



int32_t quan::stm32::flash::get_write_count()
{
   uint8_t* page = nullptr;
   uint8_t* page0 = reinterpret_cast<uint8_t*>(quan::stm32::flash::detail::get_page_address(1));
   uint8_t* page1 = reinterpret_cast<uint8_t*>(quan::stm32::flash::detail::get_page_address(2));

   if (page0[0] == 0xFF) {
      if (page1[0] == 0xFF) { // nothing written yet
         return 0;
      } else {
         page = page1;
      }
   } else {
      page = page0;
   }

    // page corrupted fail!
   if (page[0] != 0) {
      quan::error(
         quan::detail::stm32_flash_get_write_count,
         quan::detail::stm32_flash_page_corrupted
      );
      return -1;
   }
   union {
      uint8_t ar[4];
      int32_t val;
   } u;
   u.ar[3] = 0;
   for (uint8_t i = 0; i < 3; ++i) {
      u.ar[i] = page[i+1];
   }
   return u.val;
}

/*
Flash memory
two separate pages of Flash are used. If there is space,
 a symbol that is changed is written to an unused location in the current pge
The first 1 byte of the page structure is 0xFF if the page is not in use.
If the page iis in use The first byte is 0
bytes 1,2,3 hold the number of writes so each page has been written that number /2
Then it should be assumed to have been erased. the next 3 bytes are intended to be used
to hold the number of times the pages have been erased so bumped each time(not implemented yet here)
After the first 4 bytes are the symbol records
Each record is 4 bytes. The first 2 bytes are the index of the symbol in the symtab (below)
The second two bytes are the offset of the symbol data value from the start of the current page.
As each symbol is rewritten then a new record is made. There may be multiple values for a symbol on the page
The most recent will be the later record.

The data is written starting from the end of the Flash page. (Each data type has a constant size)
Each successive value is written to lower locations in the page
However there must be available two unused locs between the records
and the data which canb be read as 0xFF. They are used to indicate the end of records
They are found by reading through the records from the start of the page.

To find a symbol
read through from start of currently used flash page
until find an 0xffff.
Go back 4 from there, which the record for the last symbo, to be updated.
Next read back from there in steps of 4 bytes until find id of required symbol.
The next 2 byes after id is an index to its last storage loc. (There may be other records for thsi symbol
but they are effectively out of date now. Only the nearest to end of records is valid.)

To write a symbol
read through from start of currently used flash page
until find an 0xffff. Read the last 2 record (before the 0xFFFF, to tell you where the offset of last symbol value is.
Work out if there is space to write the value. If not then copy all latest values of symbols to alternate page

if index is going to overwrite then will need to copy all symbols to new page and erase current one
*/
namespace{ 
int32_t ll_flash_get_symtab_index (quan::stm32::flash::symbol_table const & symtab,const char* name);
 

bool ll_flash_write_symbol (quan::stm32::flash::symbol_table const & symtab,uint16_t symidx,  const uint8_t* buf,
                            int32_t write_page_num);
                            
bool ll_flash_swap_pages (quan::stm32::flash::symbol_table const & symtab,int32_t old_page_num, int32_t new_page_num);

bool ll_flash_get_sym_ptr (quan::stm32::flash::symbol_table const & symtab,
                           uint16_t symidx,uint8_t const volatile * & data_ptr_out, uint32_t & data_len_out);
                           
int32_t ll_flash_find_end_records (int32_t page_num);

}// ~namespace 
 

bool quan::stm32::flash::write_symbol (
      quan::stm32::flash::symbol_table const & symtab,
      uint16_t symidx, 
      quan::dynarray<uint8_t> const & buffer)
{
   if (buffer.get_num_elements() != symtab.get_symbol_storage_size (symidx)) {
        quan::error(
            quan::detail::stm32_flash_write_symbol,
            quan::detail::invalid_storage_size
      );
      return false;
   }
   return ll_flash_write_symbol (symtab,symidx,buffer.get(), -1);
}
 
/*
read the rep from flash into a buffer
*/

bool quan::stm32::flash::read_symbol (
      quan::stm32::flash::symbol_table const & symtab,
      uint16_t symidx, 
      quan::dynarray<uint8_t> & buffer)
{
 
   uint8_t const volatile* data_ptr = nullptr;
   uint32_t data_len = 0;
   if (ll_flash_get_sym_ptr (symtab,symidx,data_ptr,data_len)) {
      if (! buffer.realloc (data_len)) {
            quan::error(
               quan::detail::stm32_flash_read_symbol,
               quan::detail::out_of_heap_memory
            );
            return false;
      }
      quan::stm32::flash::detail::read (buffer.get(),data_ptr,data_len);
      return true;
   } else {
      quan::error(
         quan::detail::stm32_flash_read_symbol,
         quan::detail::stm32_flash_symbol_not_found
      );
      return false;
   }
}

bool quan::stm32::flash::have_symbol(quan::stm32::flash::symbol_table const & symtab,uint16_t symidx)
{
    uint8_t const volatile* data_ptr = nullptr;
         uint32_t data_len = 0;
   return ll_flash_get_sym_ptr (symtab,symidx,data_ptr,data_len);
}
  
namespace {
 
   // if write page is -1 just defaults to current used page
   // (write_page is only really used when need to swap pages)

   bool ll_flash_write_symbol (quan::stm32::flash::symbol_table const & symtab,
                               uint16_t symidx,  const uint8_t* buf, int32_t write_page_num)
   {
      
      //1 reentry to the function is acceptable, but not more than that
      static uint8_t recursion_level = 0;
      if (++recursion_level > 2) {
         quan::error(
            quan::detail::stm32_flash_write_symbol,
            quan::detail::recursion_too_deep
         );
         recursion_level = 1;
         return false;
      }

      uint16_t const new_data_size = symtab.get_symbol_storage_size (symidx);
      
      // the page to write to
      uint8_t const volatile * page = nullptr;
      uint8_t* page0 = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (1));
      uint8_t* page1 = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (2));
      int32_t page_num = write_page_num;
      // write page_num == -1 then all in current page
      if (page_num == -1) {
         uint8_t const volatile* prev_sym_data_ptr = nullptr;
         uint32_t prev_sym_data_len = 0;
         //check to see if data is the same, in which case no need to write
         if (ll_flash_get_sym_ptr (symtab,symidx,prev_sym_data_ptr,prev_sym_data_len)  &&
            (memcmp ( (uint8_t const*) prev_sym_data_ptr,buf,prev_sym_data_len) == 0) ) {
               --recursion_level;
               return true;
         }
         if (page0[0] != 0xFF) { // currently writing page0
            page = page0;
            page_num = 1;
         } else {
            if (page1[0] != 0xFF) { // currently writing page1
               page = page1;
               page_num = 2;
            } else { // both unwritten yet so start with page0
               page = page0;
               page_num = 1;
               // page written 1 time
               uint8_t buf[3] = {1,0,0};
               quan::stm32::flash::detail::write (page+1,buf,3);
            }
         }
      } else { // caller wants specific page in fact swapping pages
         page = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (page_num));
      }
      
      if (page[0] == 0xFF) { // if page empty then put symbol in as first entry
         // could get and bump count
         // std::cout << "writing new page\n";
         quan::stm32::flash::detail::write (page,0);
         quan::stm32::flash::detail::write (page + 4,static_cast<uint8_t> (symidx & 0xff));
         quan::stm32::flash::detail::write (page +5, static_cast<uint8_t> ( (symidx & 0xff00) >> 8));
         uint32_t page_size = quan::stm32::flash::detail::get_page_size (page_num);
         uint16_t const new_data_offset = page_size - new_data_size;
         quan::stm32::flash::detail::write (page+6,static_cast<uint8_t> (new_data_offset & 0xff));
         quan::stm32::flash::detail::write (page+7,static_cast<uint8_t> ( (new_data_offset & 0xff00) >> 8));
         // check ee mem is big enough!
         if ( (new_data_offset + new_data_size) > page_size) {
            quan::error( quan::detail::stm32_flash_write_symbol, quan::detail::out_of_flash_memory);
            --recursion_level;
            return false;
         }
         // do the write
         quan::stm32::flash::detail::write (page + new_data_offset,buf,new_data_size);
         --recursion_level;
         return true;
      } else { // page in use
      
         int32_t const raw_end_records = ll_flash_find_end_records (page_num);
         if (raw_end_records == -1) {
            // may happen if flash was written to 0 by firmware load etc
            quan::error( quan::detail::stm32_flash_write_symbol, quan::detail::stm32_flash_page_corrupted);
            --recursion_level;
            return false;
         }
         uint16_t const end_records = static_cast<uint16_t> (raw_end_records);
         if (end_records ==0) {
             // my be a virgin flash all written to 0
              quan::error( quan::detail::stm32_flash_write_symbol, quan::detail::stm32_flash_page_corrupted);
            --recursion_level;
            return false;
         } else {
            uint8_t const volatile *const last_idx_ptr = page + (end_records -4);
            // get start address of the data for sym there
            // n.b type of last record is not relevant
            union {
               uint8_t ar[2];
               uint16_t ui;
            } u;
            u.ar[0] = last_idx_ptr[2];
            u.ar[1]= last_idx_ptr[3];
            uint32_t const last_data_offset = u.ui;

            // data grows down. Find where to start writing new data
            uint16_t const new_data_offset = last_data_offset - new_data_size ;
            uint8_t const volatile * const new_data_ptr = page + new_data_offset;
            // Is there room in current page? // 4 for new record, 4 for old ,2 bytes should be 0xFFFF
            if (new_data_ptr > last_idx_ptr + 10) {
               uint8_t record[4] = {
                  static_cast<uint8_t> (symidx & 0xFF)
                  ,static_cast<uint8_t> ( (symidx & 0xFF00) >> 8)
                  ,static_cast<uint8_t> (new_data_offset & 0xFF)
                  ,static_cast<uint8_t> ( (new_data_offset & 0xFF00) >> 8)
               };
               quan::stm32::flash::detail::write (last_idx_ptr + 4,record,4);
               quan::stm32::flash::detail::write (new_data_ptr,buf,new_data_size);
               --recursion_level;
               return true;
            } else {
               // no room, swap pages,copy data to other page and then erase the current one
               uint8_t const volatile * const new_page = page == page0?page1:page0;
               int32_t new_page_num = (page_num == 1) ?2:1;
               if (! ll_flash_swap_pages (symtab,page_num,new_page_num)) {
                  // reported in lower level fun
                  --recursion_level;
                  return false;
               }
               // get the page count here
               // in bytes 1,2,3
               union {
                  uint8_t ar[3];
                  uint32_t ui;
               } u;
               for (uint32_t i= 0; i < 3; ++i) {
                  u.ar[i] = page[i+1];
               }
               ++u.ui; // inc page count
               
               quan::stm32::flash::detail::write (new_page + 1,u.ar,3);
               quan::stm32::flash::detail::erase (page_num);
               //now sym we want to write automatically goes in new page
               bool result = ll_flash_write_symbol (symtab,symidx, buf,-1);
               --recursion_level;
               return result;
            }
         }
      }
   }

   bool ll_flash_swap_pages (quan::stm32::flash::symbol_table const & symtab,int32_t old_page_num, int32_t new_page_num)
   {
      // get end of records
      // cycle back through records
      // for each id found record whether a later version of it has been copied
      // if not copy it
      
      int32_t const raw_end_old_records = ll_flash_find_end_records (old_page_num);
      
      if (raw_end_old_records == -1) {
         quan::error(quan::detail::stm32_flash_write_symbol, 
                           quan::detail::stm32_flash_page_corrupted);
         return false;
      }
      uint16_t const end_old_records = static_cast<uint16_t> (raw_end_old_records);
      uint32_t const num_records = symtab.get_symtable_size();
      
      quan::dynarray<bool> record_done{num_records,
            []()->void { 
               quan::error(quan::detail::stm32_flash_write_symbol, 
                           quan::detail::out_of_heap_memory);
            }
      };

      if( !record_done.good()){
         // reported in ctor
         return false;
      }
      //init flags
      for (size_t i = 0; i < num_records; ++i) {
         record_done.get()[i] = false;
      }
      uint8_t * old_page = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (old_page_num));
      // cycle through the records from the end. If a record hasnt been moved then move it to the new page
      for (uint8_t const volatile * ptr = old_page + (end_old_records - 4); ptr > old_page; ptr-=4) {
         // get id
         union {
            uint8_t ar[2];
            uint16_t ui;
         } u;
         u.ar[0] = ptr[0];
         u.ar[1] = ptr[1];
         uint32_t const sym_idx = u.ui;
         
         if (sym_idx >= num_records) {
             quan::error(quan::detail::stm32_flash_write_symbol, 
                           quan::detail::stm32_flash_invalid_symbol_index);
            return false;
         }
         if (record_done.get()[sym_idx] == false) {
            // get offset to data
            u.ar[0] = ptr[2];
            u.ar[1] = ptr[3];
            uint32_t const data_offset = u.ui;
            uint8_t const volatile * const data_ptr = old_page + data_offset ;
            ll_flash_write_symbol (symtab,sym_idx, (const uint8_t*) data_ptr,new_page_num);
            record_done.get()[sym_idx] = true;
         }
      }
      return true;
   }
    
   bool ll_flash_get_sym_ptr (quan::stm32::flash::symbol_table const & symtab,
                              uint16_t symidx,uint8_t const volatile * & data_ptr_out, uint32_t & data_len_out)
   {
    
      // the page to write to
      uint8_t const volatile* page = nullptr;
      int32_t page_num = -1;
      uint8_t* page0 = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (1));
      uint8_t* page1 = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (2));
      
      if (page0[0] != 0xFF) { // currently writing page0
         page = page0;
         page_num = 1;
      } else {
         if (page1[0] != 0xFF) { // currently writing page1
            page = page1;
            page_num = 2;
         } else { // both unwritten so no data
            return false;
         }
      }
      int32_t const raw_end_records = ll_flash_find_end_records (page_num);
      if (raw_end_records == -1) {
          quan::error(quan::detail::stm32_ll_flash_get_sym_ptr,quan::detail::stm32_flash_page_corrupted);
         return false;
      }
      
      uint16_t const end_records = static_cast<uint16_t> (raw_end_records);
      uint8_t const volatile* ptr = page + end_records - 4;
      while (ptr > page) {
         union {
            uint8_t ar[2];
            uint16_t ui;
         } u;
         u.ar[0] = ptr[0];
         u.ar[1]= ptr[1];
         uint16_t const id = u.ui;
         if (id == symidx) {
            // get the offset to the data
            u.ar[0] = ptr[2];
            u.ar[1]= ptr[3];
            uint32_t const data_offset = u.ui;
            data_ptr_out = page + data_offset ;
            data_len_out = symtab.get_symbol_storage_size(symidx);
            return true;
         } else {
            ptr -= 4;
            continue;
         }
      }
      return false;
   }
    
   int32_t ll_flash_find_end_records (int32_t page_num)
   {
      uint32_t page_size = quan::stm32::flash::detail::get_page_size (page_num);
      uint8_t * page = reinterpret_cast<uint8_t*> (quan::stm32::flash::detail::get_page_address (page_num));
      if ((page_size == 0) || ( page == nullptr)) {
         quan::error(
            quan::detail::stm32_ll_flash_find_end_records,
            quan::detail::stm32_invalid_flash_page
         );
         return -1;
      }

      for (uint32_t i = 0; i < page_size ; i += 4) {
         union {
            uint8_t ar[2];
            uint16_t ui;
         } u;
         u.ar[0] = page[i];
         u.ar[1] = page[i+1];
         if (u.ui == 0xFFFF) {
            return  i;
         }
      }
        quan::error(quan::detail::stm32_ll_flash_find_end_records,quan::detail::stm32_flash_page_corrupted);
      return -1;
   }
 
} //namespace

