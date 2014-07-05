#ifndef QUAN_DETAIL_FUNCTION_ID_HPP_INCLUDED
#define QUAN_DETAIL_FUNCTION_ID_HPP_INCLUDED

namespace quan{
   namespace detail{
      enum function_id{
         function_id_unknown = -1
         ,stm32_flash_read_symbol = -2
         ,stm32_flash_write_symbol = -3
         ,stm32_flash_get_write_count = -4
         ,stm32_ll_flash_get_sym_ptr = -5
         ,stm32_ll_flash_find_end_records = -6
         ,function_id_user = 1
      };
   }
}

#endif
