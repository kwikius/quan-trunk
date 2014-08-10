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

void quan::test::bigint_or_test()
{
  std::cout << "bigint or_test\n";
  quan::bigint v1 =                    "0xF0A0000000000000000000000000007";
  v1 |=                            "0x1000FF0E000000000000000000000000000";
  QUAN_CHECK(v1.to_hex_string() == "0x1000FFAE000000000000000000000000007")
 // std::cout << v1.to_hex_string() <<'\n';
}
