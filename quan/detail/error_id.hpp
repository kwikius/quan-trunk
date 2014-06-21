#ifndef QUAN_DETAIL_ERROR_ID_HPP_INCLUDED
#define QUAN_DETAIL_ERROR_ID_HPP_INCLUDED

namespace quan{ namespace detail{

/*
 lib uses negative numbers so user can use positive ones
*/
   enum error_num{
       error_num_unknown = -1
      ,stm32_flash_page_corrupted =-2
      ,stm32_flash_symbol_not_found = -3
      ,invalid_storage_size = -4
      ,out_of_heap_memory = -5
      ,stm32_flash_invalid_symbol_index = -6
      ,recursion_too_deep = -7
      ,out_of_flash_memory = -8
      ,stm32_invalid_flash_page = -9
      ,unterminated_string_constant = -10
      ,error_num_user = 1
   };

}}

#endif // QUAN_DETAIL_ERROR_ID_HPP_INCLUDED
