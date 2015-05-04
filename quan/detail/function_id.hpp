#ifndef QUAN_DETAIL_FUNCTION_ID_HPP_INCLUDED
#define QUAN_DETAIL_FUNCTION_ID_HPP_INCLUDED
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

namespace quan{
   namespace detail{
      enum function_id{
         function_id_unknown = -1
         ,stm32_flash_read_symbol = -2
         ,stm32_flash_write_symbol = -3
         ,stm32_flash_get_write_count = -4
         ,stm32_ll_flash_get_sym_ptr = -5
         ,stm32_ll_flash_find_end_records = -6
         ,stm32_flash_text_to_type = -7
         ,stm32_flash_type_to_text = -8
         ,stm32_flash_symtab_init = -9
         ,stm32_flash_bytestream_to_type = -10
         ,stm32_flash_validate = -11
         ,stm32_flash_write = -12
         ,stm32_flash_read = -13
         ,ll_flash_swap_pages = -14
         ,function_id_user = 1
      };
   }
}

#endif
