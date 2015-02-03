
#ifndef QUAN_MATTERS_TEST_BIGINT_TEST1_HPP_INCLUDED
#define QUAN_MATTERS_TEST_BIGINT_TEST1_HPP_INCLUDED

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

#include <quan_matters/test/simple_test.hpp>
#include <quan/bigint.hpp>

namespace quan{
   namespace test{

      void bigint_test1();
      void bigint_plus_eq_test();
      void bigint_plus_test();
      void bigint_minus_eq_test();
      void bigint_mul_eq_test();
      void bigint_div_eq_test();
      void bigint_shl_test();
      void bigint_shr_test();
      void bigint_or_test();
      void bigint_and_test();
      void bigint_xor_test();
      void bigint_compare_test();
      void test_ctor();
      void test_assign();

   }
}
#endif

