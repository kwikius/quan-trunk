#ifndef QUAN_ITOA_HPP_INCLUDED
#define QUAN_ITOA_HPP_INCLUDED
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

#include <cstring>
#include <cstdint>
/*
  include <quan_matters/src/itoa.cpp>
  and  instantiate as required
*/

namespace quan{

   template <typename IntType>
   inline constexpr size_t get_itoasc_buf_size()
   {
      return sizeof(IntType) * 8 + 2;
   }

   template <typename IntType>
   inline char * itoasc( IntType in, char * array,  int base )
   {
      if ( (base > 16) || ( base < 2)){
        return nullptr;
      }
      static constexpr size_t arlen = get_itoasc_buf_size<IntType>();
      char local_array[arlen];
      char* ptr = local_array + arlen-1;
      *ptr = '\0';
      --ptr;
      if ( in == 0){
         *ptr = '0';
      }else{
         int32_t const sign = (in>=0)?1:-1;
         IntType abs_in = in * sign;
         for(size_t i = 0; i < arlen; ++i){

            IntType rem = (abs_in % base);
            char ch = ( rem < 10)
               ? static_cast<char>(rem + '0') 
               : static_cast<char>(rem + ('A' - 10));
            *ptr = ch;
            abs_in /= base;
            if( abs_in != 0){
               -- ptr;
               continue;
            }else{
              break;
            }
         }
         if ( sign == -1){
            --ptr;
            *ptr = '-';
         }
      }
      strcpy(array,ptr) ;
      return array;
   }
}

#endif // QUAN_ITOA_HPP_INCLUDED
