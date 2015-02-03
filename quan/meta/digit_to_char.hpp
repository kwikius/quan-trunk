#ifndef QUAN_META_DIGIT_TO_CHAR_HPP_INCLUDED
#define QUAN_META_DIGIT_TO_CHAR_HPP_INCLUDED
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

namespace quan{ namespace meta{

   template <int Base> struct digit_to_char;

   template <>  struct digit_to_char<16>{

       char operator()(int digit){
          static int const vals[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
          if ( ( digit >= 0) && (digit <= 15) ) {
            return vals[digit];
          }else{
            return '\0';
          }
       } 
   };

   template <>  struct digit_to_char<10>{

       char operator()(int digit){
          static int const vals[] = {'0','1','2','3','4','5','6','7','8','9'};
          if ( ( digit >= 0) && (digit <= 9) ) {
            return vals[digit];
          }else{
            return '\0';
          }
       } 
   };

    template <>  struct digit_to_char<2>{

       char operator()(int digit){
          static int const vals[] = {'0','1'};
          if ( ( digit >= 0) && (digit <= 1) ) {
            return vals[digit];
          }else{
            return '\0';
          }
       } 
   };

   


}}



#endif // QUAN_META_CHAR_TO_DIGIT_HPP_INCLUDED
