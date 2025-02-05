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
   
  void ll_bigint_minus_eq()
  {
    ll_bigint v1 = quan::meta::integer_min<long long>::value;
    ll_bigint v2 = quan::meta::integer_max<long long>::value;
   // v1.dump_rep();
    v1.minus_eq(v2);
   // v1.dump_rep();
    v1.minus_eq(v1);
    QUAN_CHECK(v1.eq_zero());

    v1.from_string_base<10>("12345434567890876554456766255236");
    v2.from_string_base<10>("98765432134263738364544747464747484848");
    v1.minus_eq(v2);
    QUAN_CHECK(v1.to_string_base<10>()
         == "-98765419788829170473668193007981229612")
  }

}}

