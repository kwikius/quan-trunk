#ifndef QUAN_META_CHAR_TO_DIGIT_HPP_INCLUDED
#define QUAN_META_CHAR_TO_DIGIT_HPP_INCLUDED
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

   template <int Base> struct character_to_digit;

   template <>  struct character_to_digit<16>{

       int operator()(char ch){
         switch (ch){

            case '0' : return 0;
            case '1' : return 1;
            case '2' : return 2;
            case '3' : return 3;
            case '4' : return 4;
            case '5' : return 5;
            case '6' : return 6;
            case '7' : return 7;
            case '8' : return 8;
            case '9' : return 9;
            case 'a' : return 10;
            case 'b' : return 11;
            case 'c' : return 12;
            case 'd' : return 13;
            case 'e' : return 14;
            case 'f' : return 15;
            case 'A' : return 10;
            case 'B' : return 11;
            case 'C' : return 12;
            case 'D' : return 13;
            case 'E' : return 14;
            case 'F' : return 15;
            default  : return -1;
         }
       }
   };

   template <>  struct character_to_digit<10>{

       int operator()(char ch){
         switch (ch){

            case '0' : return 0;
            case '1' : return 1;
            case '2' : return 2;
            case '3' : return 3;
            case '4' : return 4;
            case '5' : return 5;
            case '6' : return 6;
            case '7' : return 7;
            case '8' : return 8;
            case '9' : return 9;
            default  : return -1;
         }
       }
   };

   template <>  struct character_to_digit<2>{

       int operator()(char ch){
         switch (ch){
            case '0' : return 0;
            case '1' : return 1;
            default  : return -1;
         }
       }
   };


}}



#endif // QUAN_META_CHAR_TO_DIGIT_HPP_INCLUDED
