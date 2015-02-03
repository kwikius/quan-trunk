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

#include "bigint_test.hpp"

namespace {

   void twos_c_test()
   {
       std::cout << "bigint twos c test\n";
       quan::bigint v = "0xFFFFFFFFFFFFFFFFE";
       v &=             "0xFFFFFFFFFFFFFFFFF";  // cap as a reg
       v ^=             "0xFFFFFFFFFFFFFFFFF";  // flip bits
       v +=                               "1";        // add 1
       v &=             "0xFFFFFFFFFFFFFFFFF";  // remove carry 

       QUAN_CHECK(v == "2")

       v ^=             "0xFFFFFFFFFFFFFFFFF";  // flip bits
       v +=                               "1";        // add 1
       v &=             "0xFFFFFFFFFFFFFFFFF";  // remove carry 
      
       QUAN_CHECK(v ==  "0xFFFFFFFFFFFFFFFFE")
   }

   void misc_test()
   {
        std::cout << "bigint misc test\n";
        quan::bigint v = "0b11111111";
        QUAN_CHECK( v == "0xFF")

        v = "0b0111111110";
     //   std::cout << v.to_hex_string() <<'\n';
        QUAN_CHECK( v == "0x1FE")

        v = "0b1110111010000111000000001111111011101110100001110000000011111110";
        QUAN_CHECK( v == "0xEE8700FEEE8700FE")
   }
}

void quan::test::bigint_test1()
{
   typedef quan::bigint bint;
   bint v1 = "1";
   QUAN_CHECK(( v1.to_string() == "1" ))
   QUAN_CHECK(( v1.eq_one() ))
   QUAN_CHECK(( !v1.eq_zero() ))
   QUAN_CHECK(( !v1.lt_zero() ))

   v1 = "0";
   QUAN_CHECK(( v1.eq_zero() ))
   QUAN_CHECK(( !v1.eq_one() ))
   QUAN_CHECK(( !v1.lt_zero() ))

   v1 = "-1";
   QUAN_CHECK(( !v1.eq_zero() ))
   QUAN_CHECK(( !v1.eq_one() ))
   QUAN_CHECK(( v1.lt_zero() ))

   twos_c_test();

   misc_test();

}


