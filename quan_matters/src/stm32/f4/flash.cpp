// flash routines for stm32f4

#include <stm32f4xx.h>
#include <quan/stm32/detail/flash.hpp>
#include <cstring>

namespace {
  constexpr uint32_t page_address_array[]
  ={
     0x8000000
    ,0x8004000
    ,0x8008000
    ,0x800C000
    ,0x8010000
    ,0x8020000
    ,0x8040000
    ,0x8060000
    ,0x8080000
    ,0x80A0000
    ,0x80C0000
    ,0x80E0000
  };
  constexpr uint32_t num_flash_pages 
      = (sizeof(page_address_array)/sizeof(uint32_t));
}

void* quan::stm32::flash::detail::get_page_address (int32_t page_id)
{
  return (void*) page_address_array[page_id];
}

int32_t quan::stm32::flash::detail::get_page_num (void * address_in)
{
   uint32_t address = (uint32_t) address_in;

   if (address < page_address_array[0]){
    return -1;
   }
   for ( uint32_t i = 1; i < num_flash_pages; ++i){
      if (address < page_address_array[i]){
         return i-1;
      }
   }
   return -1;
}

//n.b out of range returns 0
uint32_t quan::stm32::flash::detail::get_page_size (int32_t page_num)
{
   if ((page_num < 0 ) || (page_num >= static_cast<int32_t>(num_flash_pages))){
     return 0;
   }else{
      if (page_num < 4){
         return 0x4000;
      }else{
         if(page_num != 4){
          return 0x20000;
         }else{
           return 0x10000; 
         }
      }
   }
   return 0;
}
/*
 everything suspended while this takes place
*/
bool quan::stm32::flash::detail::erase (int32_t page_num)
{
   while (FLASH->SR & FLASH_SR_BSY) {
      ;
   }
   //2) unlock
   if (FLASH->CR & FLASH_CR_LOCK) {
      FLASH->KEYR = 0x45670123;
      FLASH->KEYR = 0xCDEF89AB;
   }
   
//clear flags ( by writing 1)
   FLASH->SR  = (FLASH_SR_WRPERR | FLASH_SR_PGAERR | FLASH_SR_PGPERR
                 | FLASH_SR_PGSERR | FLASH_SR_SOP | FLASH_SR_EOP);
   // 8 bit erase
   FLASH->CR &= ~ (0b11 << 8U);
   //sector mask Sector1
   FLASH->CR &= ~ (0xF << 3U);
   FLASH->CR |= (page_num << 3U);
   FLASH->CR &= ~FLASH_CR_PG;
   // no mass erase
   FLASH->CR &= ~ FLASH_CR_MER;  // no MER
   // yes sector erase
   FLASH->CR |= FLASH_CR_SER; // want SER
   // start the erase
   FLASH->CR |= FLASH_CR_STRT;
   
   while (FLASH->SR & FLASH_SR_BSY) {
      ;
   }
   //erase done
   FLASH->CR &= ~ FLASH_CR_SER;
   //clear sector reg
   FLASH->CR &= ~ ( (0xF) << 3U);
   FLASH->CR |= FLASH_CR_LOCK;
   if (FLASH->SR & FLASH_SR_PGSERR) {
      return false;
   }
   if (FLASH->SR & FLASH_SR_PGPERR) {
      return false;
   }
   if (FLASH->SR & FLASH_SR_PGAERR) {
      return false;
   }
   if (FLASH->SR & FLASH_SR_WRPERR) {
      return false;
   }
   return true;
}


// dest points to somewhere in Flash
bool quan::stm32::flash::detail::write 
(const volatile uint8_t* dest, const uint8_t* buf, int32_t bytes)
{
   while (FLASH->SR & FLASH_SR_BSY) {
      ;
   }
   
//2) unlock
   if (FLASH->CR & FLASH_CR_LOCK) {
      FLASH->KEYR = 0x45670123;
      FLASH->KEYR = 0xCDEF89AB;
   }
// should now be unlocked
   if (FLASH->CR & FLASH_CR_LOCK) {
      return false;
   }
   
//clear flags ( by writing 1)
   FLASH->SR  = (FLASH_SR_WRPERR | FLASH_SR_PGAERR | FLASH_SR_PGPERR
                 | FLASH_SR_PGSERR | FLASH_SR_SOP | FLASH_SR_EOP);
                 
// set correct PSIZE  8 bits write at a time
   FLASH->CR &= ~ (0b11 << 8U);
   
// write the data
   FLASH->CR |= FLASH_CR_PG;
   for (int32_t i = 0; i < bytes; ++i) {
      * ( ( (volatile uint8_t*) (dest)) +i) = buf[i];
      while (FLASH->SR & FLASH_SR_BSY) {
         ;// delay (1000);
      }
   }
   FLASH->CR &= ~FLASH_CR_PG;
   // lock
   FLASH->CR |= FLASH_CR_LOCK;
   
   if (FLASH->SR & (1U<<7U)) {
      //serial::port::write ("pgserr");
      return false;
   }
   if (FLASH->SR & (1U <<6U)) {
      //serial::port::write ("pgperr");
      return false;
   }
   if (FLASH->SR & (1U <<5U)) {
      //serial::port::write ("pgaerr");
      return false;
   }
   if (FLASH->SR & (1U <<4U)) {
      // serial::port::write ("wrperr");
      return false;
   }
   return true;
}

bool quan::stm32::flash::detail::read 
   (uint8_t* buf,const volatile uint8_t * src, int32_t bytes)
{
  memcpy (buf, (uint8_t const *) src,bytes);
   return true;
}
 



