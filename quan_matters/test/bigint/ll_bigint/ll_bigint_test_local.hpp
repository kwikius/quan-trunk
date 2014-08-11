
#ifndef QUAN_TEST_BIGINT_LL_BIGINT_TEST_HPP_INCLUDED
#define QUAN_TEST_BIGINT_LL_BIGINT_TEST_HPP_INCLUDED
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
 along with this program. If not, see http://www.gnu.org/licenses./
 */
/*

 local implementation header

*/

// include interface header
#include <quan_matters/test/bigint/ll_bigint_test.hpp>

namespace quan{
   namespace test{

     void ll_bigint_default_ctor();
     void ll_bigint_int_ctor();
     void ll_bigint_resize();
     void ll_bigint_shr_eq();
     void ll_bigint_shl_eq();
     void ll_bigint_div_mod();
     void ll_bigint_minus_eq();
     void ll_bigint_plus_eq();
     void ll_bigint_mul_eq();
     void ll_bigint_compare();
     void ll_bigint_bitand_eq();
     void ll_bigint_bitor_eq();
     void ll_bigint_bitxor_eq();
     void ll_bigint_invert();
     void ll_bigint_negate();
     void ll_bigint_from_string_base10();
     void ll_bigint_to_string_base10();
     void ll_bigint_gcd();
   }
}

#endif
