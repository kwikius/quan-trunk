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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
#include <quan/detail/ll_bigint.hpp>
#include <quan/meta/char_to_digit.hpp>
#include <stdexcept>
using quan::detail::ll_bigint;

template <int N>
void ll_bigint::from_string_base(std::string const & str)
{
   *this = 0;

   std::size_t const len = str.length();
   if ( len == 0) {
     return;
   }
   ll_bigint const mult = N;
   bool minus_sign = false;
   std::size_t start = 0;
   if ( str.at(0) == '-'){
     minus_sign = true;
     start = 1;
   }
   for (size_type i = start; i < len; ++i){
      if ( i != start){
        this->mul_eq(mult);
      } 
      int digit = quan::meta::character_to_digit<N>{}(str.at(i));
      if ( digit == -1 ) {
         throw std::runtime_error("invalid integer digit");
      }
      this->plus_eq(digit);
   }
   if ( minus_sign){
     this->negate();
   }

}

template 
void ll_bigint::from_string_base<10>(std::string const & str);

template 
void ll_bigint::from_string_base<16>(std::string const & str);

template 
void ll_bigint::from_string_base<2>(std::string const & str);



