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

#include <quan_matters/test/test.hpp>
#include <quan/velocity.hpp>
#include <quan/length.hpp>

/*
   Check numeric access by ref functions 
*/
namespace {

#define QUAN_TEST_FUN(fun) void fun ();

   QUAN_TEST_FUN(reference_numeric_value)
   QUAN_TEST_FUN(const_reference_numeric_value)
   QUAN_TEST_FUN(test_set_numeric_value)

#undef QUAN_TEST_FUN
}

void numeric_value_access_test()
{
#define QUAN_TEST_FUN(fun) fun();

   QUAN_TEST_FUN(reference_numeric_value)
   QUAN_TEST_FUN(const_reference_numeric_value)
   QUAN_TEST_FUN(test_set_numeric_value)

#undef QUAN_TEST_FUN
}



namespace {

   void test_set_numeric_value()
   {
      quan::length::pc big(1);
      QUAN_CHECK(big.numeric_value() == 1);

      big.set_numeric_value<quan::length::pc>(2.345);
      QUAN_CHECK(big.numeric_value() == 2.345);

   }

   namespace {

      QUAN_FLOAT_TYPE  & ref_f ( QUAN_FLOAT_TYPE & d)
      {
         d = 42.;
         return d;
      }
   }

   void reference_numeric_value()
   {
      quan::velocity::mi_per_h  velocity;
      QUAN_FLOAT_TYPE val = 555.6453;

      velocity.reference_numeric_value<quan::velocity::mi_per_h>()= val;

      QUAN_CHECK(velocity.numeric_value() == val);

      QUAN_FLOAT_TYPE & res = ref_f(velocity.reference_numeric_value<quan::velocity::mi_per_h>());
      QUAN_CHECK( &res == &velocity.reference_numeric_value<quan::velocity::mi_per_h>());
      QUAN_CHECK( res == 42.);
      QUAN_CHECK( velocity.numeric_value() == 42.);
   }

   namespace {

      QUAN_FLOAT_TYPE const & const_ref_f ( QUAN_FLOAT_TYPE const & d)
      {
       
         return d;
      }

   }
   void const_reference_numeric_value()
   {
      quan::length::mm q(1.5);
      QUAN_FLOAT_TYPE const &d = q.const_reference_numeric_value<quan::length::mm>();
      QUAN_FLOAT_TYPE const &d1 = q.const_reference_numeric_value<quan::length::mm>();
      QUAN_CHECK( &d == &d1);
      QUAN_FLOAT_TYPE const & result = const_ref_f( q.const_reference_numeric_value<quan::length::mm>());
      QUAN_CHECK( &result == &d);
      QUAN_CHECK(result == 1.5);

   // implicit const

      QUAN_FLOAT_TYPE const &dd = q.reference_numeric_value<quan::length::mm>();
      QUAN_FLOAT_TYPE const &dd1 = q.reference_numeric_value<quan::length::mm>();
      QUAN_CHECK(&dd == &dd1);
      QUAN_FLOAT_TYPE const & result1 = const_ref_f( q.reference_numeric_value<quan::length::mm>());
      QUAN_CHECK(&result1 == &dd);
      QUAN_CHECK(result1 == 1.5);

   }

}//anon
