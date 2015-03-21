#ifndef QUAN_DETAIL_ERROR_ID_HPP_INCLUDED
#define QUAN_DETAIL_ERROR_ID_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

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
      ,bad_float_range = -11
      ,bad_int_range = -12
      ,stm32_flash_erase_page_failed =-13
      ,stm32_unknown_flash_error =-14
      ,stm32_flash_incorrect_type = -15
      ,unexpected_nullptr = -16
      ,error_num_user = 1
   };

}}

#endif // QUAN_DETAIL_ERROR_ID_HPP_INCLUDED
