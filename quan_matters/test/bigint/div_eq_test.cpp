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

void quan::test::bigint_div_eq_test()
{

   std::cout << "bigint div_eq_test\n";
   quan::bigint v1 = "1000";
   v1.div_eq("3");
   QUAN_CHECK(v1.to_string() == "333");
   v1 = "1000";
   v1.mod_eq("3");
   QUAN_CHECK(v1.to_string() == "1");
   v1 =      "1000000000000000000";
   v1.div_eq( "999000000000000000");
   //  std::cout << v1.to_string() <<'\n';
   QUAN_CHECK(v1.to_string() == "1");
   v1 = "234567";
   QUAN_CHECK(v1.to_string() == "234567");
   v1.div_eq( v1);
   QUAN_CHECK(v1.to_string() == "1");

}
