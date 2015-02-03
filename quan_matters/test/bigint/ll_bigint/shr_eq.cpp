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
   
  void ll_bigint_shr_eq()
  {
    ll_bigint v = 0xff000000LL;
    v.logical_shr_eq(24);
    QUAN_CHECK(v.to_string_base<16>() == "FF")

    ll_bigint v1 = 0xff000000LL;
    v1.logical_shr_eq(23); 
    QUAN_CHECK(v1.to_string_base<16>() == "1FE")

    ll_bigint v2 = 0xff000000LL;
    v2.logical_shr_eq(22); 
    QUAN_CHECK(v2.to_string_base<16>() == "3FC")

    ll_bigint v3 = 0xff000000LL;
    v3.logical_shr_eq(21); 
    QUAN_CHECK(v3.to_string_base<16>() == "7F8")
    
  
  }

}}

