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

using quan::detail::ll_bigint;

namespace quan{ namespace test{
   
   void ll_bigint_test()
   {
      ll_bigint_default_ctor();
      ll_bigint_int_ctor();
      ll_bigint_resize();
      ll_bigint_shr_eq();
      ll_bigint_shl_eq();
      ll_bigint_minus_eq();
      ll_bigint_plus_eq();
      ll_bigint_compare();
      ll_bigint_div_mod();
      ll_bigint_mul_eq();
      ll_bigint_bitand_eq();
      ll_bigint_bitor_eq();
      ll_bigint_bitxor_eq();
      ll_bigint_invert();
      ll_bigint_negate();
      ll_bigint_from_string_base10();
      ll_bigint_to_string_base10();
      ll_bigint_gcd();
   }

}}


