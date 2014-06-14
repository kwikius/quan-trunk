#include <quan/stm32/flash.hpp>
#include <quan/stm32/detail/flash.hpp>

namespace {
   int32_t ll_flash_find_end_records (uint32_t page_num);
}

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

