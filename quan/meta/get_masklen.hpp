#ifndef QUAN_META_GET_MASKLEN_HPP_INCLUDED
#define QUAN_META_GET_MASKLEN_HPP_INCLUDED
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

#include <stdint.h>
#include <quan/meta/get_lowest_set_bit.hpp>
#include <quan/meta/get_highest_set_bit.hpp>

/*
 returns bit pos of lowest set bit or -1 if input is 0;
*/
namespace quan{
   namespace meta{
     
    template<uin32_t Val> struct get_masklen{
      static const int value = (quan::meta::get_highest_set_bit<Val>::value - quan::meta::get_lowest_set_bit<Val>::value)+1;
    };

    template<> struct get_masklen<0>{
      static const int value =0;
    };

}}

#endif // QUAN_META_GET_HIGHEST_SET_BIT_HPP_INCLUDED
