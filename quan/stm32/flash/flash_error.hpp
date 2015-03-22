#ifndef QUAN_STM32_FLASH_FLASH_ERROR_HPP_INCLUDED
#define QUAN_STM32_FLASH_FLASH_ERROR_HPP_INCLUDED
/*
 Copyright (c) 2013 -2015 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/error.hpp>

// could be by app
// at least should put in quan::stm32::flash
// needs rehash!
enum function_ids{
   fn_parse_input = quan::detail::function_id_user+1
   ,fn_main
   ,fn_flash_demo
   ,fn_any
   ,fn_rep_to_cstring_Vect3F
   ,fn_rep_to_cstring_Bool
};

#endif //QUAN_STM32_FLASH_FLASH_ERROR_HPP_INCLUDED
