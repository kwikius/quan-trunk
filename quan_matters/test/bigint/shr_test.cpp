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

void quan::test::bigint_shr_test()
{
     std::cout << "bigint shr_test\n";
     quan::bigint v1 = "4848484800000000"  ;
     v1 >>= "2";
  //   std::cout << v1.to_string() <<'\n';
     QUAN_CHECK(v1.to_string() == "1212121200000000");
     v1 =  "1";
     v1 <<= "20";
     QUAN_CHECK(v1.to_binary_string() == "0b100000000000000000000")
     v1 >>= "20";
    // std::cout << "???" << v1.to_binary_string() <<'\n';
     QUAN_CHECK(v1.to_binary_string() == "0b1" )

     v1 = "4848484800000001"  ;
     v1 >>= "2";
  //   std::cout << v1.to_string() <<'\n';
     QUAN_CHECK(v1.to_string() == "1212121200000000");
}
