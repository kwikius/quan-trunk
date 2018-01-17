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
#include "ll_bigint_test.hpp"
#include "bigint_test.hpp"
#include <quan_matters/test/big_rational/big_rational_test1.hpp>

//#if( QUAN_VERSION == 1)
int errors =0;
//#else
//int quan::test::errors =0;
//#endif

int main()
{
  // quan::test::ll_bigint_test();
   quan::test::bigint_and_test();
   quan::test::test_assign();
   quan::test::bigint_test1();
   quan::test::bigint_compare_test();
   quan::test::test_ctor();
   quan::test::bigint_div_eq_test();
   quan::test::bigint_minus_eq_test();
   quan::test::bigint_mul_eq_test();
   quan::test::bigint_or_test();
   quan::test::bigint_plus_eq_test();
   quan::test::bigint_plus_test();
   quan::test::bigint_shl_test();
   quan::test::bigint_shr_test();
   quan::test::bigint_xor_test();

   // add ll tests
   
   QUAN_EPILOGUE
}
