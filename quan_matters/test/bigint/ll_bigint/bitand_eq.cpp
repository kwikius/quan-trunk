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

#include <quan_matters/test/bigint/ll_bigint/ll_bigint_test_local.hpp>
#include <quan/meta/integer_limits.hpp>

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
  void ll_bigint_bitand_eq()
  {
    ll_bigint v1 = int{0xFF7FFF};
    v1.from_string_base<16>("FF7FFF");
    ll_bigint v2 = 0xFFFF0;
    v1.bitand_eq(v2);

    QUAN_CHECK( v1.to_string_base<16>() == "F7FF0")

    v1.from_string_base<16>("FFFF0000888811110000FFFF000088881111");
    v2.from_string_base<16>( "FFF0000788811110000FFFF000000001101");
    v1.bitand_eq(v2);
    QUAN_CHECK( v1.to_string_base<16>()
         ==                  "FFF0000088811110000FFFF000000001101");
  }

}}

