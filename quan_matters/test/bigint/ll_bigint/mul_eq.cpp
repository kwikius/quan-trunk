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
   
  void ll_bigint_mul_eq()
  {
    ll_bigint v1 = 0xFF;
    ll_bigint v2 = 0xFF;

    v1.mul_eq(v2);
    QUAN_CHECK(v1.to_string_base<16>() == "FE01")

    v1 = -1;
    v2 = -1;
    v1.mul_eq(v2);
    QUAN_CHECK(v1.eq_one());

    v1.from_string_base<10>("1098765454364745757346478363546474885");
    v2.from_string_base<10>("65243537486765237157651283681918366139678");
    v1.mul_eq(v2);
    QUAN_CHECK(v1.to_string_base<10>() ==
     "71687345111008928289517920297195379151747598446316920166134978502682428987030");

    v1.from_string_base<10>("-1098765454364745757346478363546474885");
    v2.from_string_base<10>("65243537486765237157651283681918366139678");
    v1.mul_eq(v2);
    QUAN_CHECK(v1.to_string_base<10>() ==
     "-71687345111008928289517920297195379151747598446316920166134978502682428987030");

    v1.from_string_base<10>("1098765454364745757346478363546474885");
    v2.from_string_base<10>("-65243537486765237157651283681918366139678");
    v1.mul_eq(v2);
    QUAN_CHECK(v1.to_string_base<10>() ==
     "-71687345111008928289517920297195379151747598446316920166134978502682428987030");

        v1.from_string_base<10>("-1098765454364745757346478363546474885");
    v2.from_string_base<10>("-65243537486765237157651283681918366139678");
    v1.mul_eq(v2);
    QUAN_CHECK(v1.to_string_base<10>() ==
     "71687345111008928289517920297195379151747598446316920166134978502682428987030");
  }

}}

