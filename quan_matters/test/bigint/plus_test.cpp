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
/*
  quan::bigint plus_test
*/

#include "bigint_test.hpp"

void quan::test::bigint_plus_test()
{
   std::cout << "bigint plus test\n";
   quan::bigint v1 = -1;

   QUAN_CHECK(( v1.to_string() == "-1"));

   QUAN_CHECK((v1.to_double() == -1.0))
  // std::cout << v1.to_double() <<'\n';
   auto v2 = v1 + v1;

   QUAN_CHECK(( v2.to_string() == "-2"))
   
   v2 = v2 + "20";

   QUAN_CHECK((v2.to_string() == "18"));
   v1 = "100000000000000000000000000000000000000000900";
   v2 = "100000000000000000000000000000000000000000011";
   auto v3 = v1 + v2;

   QUAN_CHECK((v3.to_string() == "200000000000000000000000000000000000000000911"));
}


