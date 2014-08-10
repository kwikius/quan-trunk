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

void quan::test::bigint_xor_test()
{
  std::cout << "bigint xor_test\n";
  quan::bigint v1 =               "0xF00000000000000000000000000065000000000000000000";
  v1 ^=                           "0xF1F000000000000000000000000050000000000000000000";
  //std::cout << "!? " << v1.to_hex_string() <<'\n';
  QUAN_CHECK(v1.to_hex_string() == "0x1F000000000000000000000000035000000000000000000")

}

