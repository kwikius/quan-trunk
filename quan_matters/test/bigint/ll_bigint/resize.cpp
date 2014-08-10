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
   
  void ll_bigint_resize()
  {
    ll_bigint v = 1;
   
    QUAN_CHECK(v.get_num_elements() == 1 );
    QUAN_CHECK(v.is_negative() == false)
    v.extend(20);
    QUAN_CHECK(v.get_num_elements() == 20);
    QUAN_CHECK(v.is_negative() == false)
    v.request_compact(1);
    QUAN_CHECK(v.get_num_elements() == 1);
    QUAN_CHECK(v.is_negative() == false)

    ll_bigint v1 = -1;
   
    QUAN_CHECK(v1.get_num_elements() == 1 );
    QUAN_CHECK(v1.is_negative() == true)
    v1.extend(2000);
    QUAN_CHECK(v1.get_num_elements() == 2000);
    QUAN_CHECK(v1.is_negative() == true)
    v1.request_compact(1);
    QUAN_CHECK(v1.get_num_elements() == 1);
    QUAN_CHECK(v1.is_negative() == true)
    v1.extend(2000);
    v1.negate();
    QUAN_CHECK(v1.eq_one())
    QUAN_CHECK(v1.get_num_elements() == 2000);
  
  }

}}

