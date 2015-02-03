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
   
  void ll_bigint_div_mod()
  {
    ll_bigint v1;
    v1.from_string_base<16>("FFFFFFFFFFFFFFFFFFE");
    ll_bigint v2 = 0xF;

    ll_bigint dividend ;
    ll_bigint remainder;
    ll_bigint::div_mod(v1,v2,dividend,remainder);
    QUAN_CHECK(dividend.to_string_base<16>() == "1111111111111111110")
    QUAN_CHECK(remainder.to_string_base<16>() == "E")

    v1.from_string_base<10>("3334");
    v2.from_string_base<10>("3");

    ll_bigint::div_mod(v1,v2,dividend,remainder);
    QUAN_CHECK(dividend.to_string_base<10>() == "1111")
    QUAN_CHECK(remainder.to_string_base<10>() == "1")

    
    v1.from_string_base<10>("30");
    v2.from_string_base<10>("29");

    ll_bigint::div_mod(v1,v2,dividend,remainder);
    QUAN_CHECK(dividend.to_string_base<10>() == "1")
    QUAN_CHECK(remainder.to_string_base<10>() == "1")
    
   
  }

}}

