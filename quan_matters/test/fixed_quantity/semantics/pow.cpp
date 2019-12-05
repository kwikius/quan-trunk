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


// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>
#include <quan/area.hpp>
#include <quan/volume.hpp>
#include <quan/where.hpp>
#include <type_traits>

/*
Docs state:
template <
    int64_t N,int64_t D,
    typename AbstractQuantity,typename Unit,typename Value_type
>
typename binary_op<
    t1_quantity<AbstractQuantity,Unit,Value_type >,
    pow, rational<N,D>
>::type
pow(t1_quantity<AbstractQuantity,Unit,Value_type > const & x );

1 Returns:

If N / D == 0 the type of the result is int. the value is 1.
If N / D == 1 the type of the result is the type of x and 
its numeric_value() == x.numeric_value.
In all other cases x is used to initialise a quantity t 
which has similar units to x except that t is a coherent-quantity.
 The dimension of the result r is the dimension of t multiplied by N/D. 
r will be an anonymous_quantity. 
The type of the value_type of r is as if QUAN_FLOAT_TYPE was multiplied by the value_type of x.

r.numeric_value() == std::pow(t.numeric_value,static_cast<result_value_type>(N)/D);

*/


namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(test_pow0)
    QUAN_TEST_FUN(test_pow1)
    QUAN_TEST_FUN(test_power_functions)
    QUAN_TEST_FUN(test_root_quantity)

#undef QUAN_TEST_FUN
}

void pow_test()
{
#define QUAN_TEST_FUN(fun) fun();

    QUAN_TEST_FUN(test_pow0)
    QUAN_TEST_FUN(test_pow1)
    QUAN_TEST_FUN(test_power_functions)
    QUAN_TEST_FUN(test_root_quantity)

#undef QUAN_TEST_FUN
}

namespace {
   /*
       check T is an int rather than just something convertible
   */
   template <typename T,typename T1>
   typename quan::where_<
       std::is_same<T,T1>,
       T1
   >::type
   check_is_same(T1 t1)
   {
       return t1;
   }

   void test_root_quantity()
   {

      auto v = quan::pow<1,4>(quan::length::mm{1});

      typedef decltype(v) v_type;

      QUAN_CHECK( quan::meta::is_fixed_quantity<v_type>::value )

      typedef v_type::unit unit;

      QUAN_CHECK(quan::meta::is_static_unit<unit>::value )

      typedef unit::conversion_factor conv_factor;

      QUAN_CHECK(quan::meta::is_conversion_factor<conv_factor>::value)

      typedef quan::meta::get_exponent<conv_factor>::type exponent;

      typedef quan::meta::numerator<exponent> numerator;
      typedef quan::meta::denominator<exponent> denominator;


      QUAN_CHECK(numerator::value == -3)
      QUAN_CHECK(denominator::value == 4);

      quan::length::mm xx = quan::pow<4>(v);

      QUAN_CHECK(xx == quan::length::mm{1})

   }

   void test_pow0()
   {
   //    check_is_same<int>(1.); //FWIW uncomment to check the function works
       quan::length::m L1(200);
       int v1 = check_is_same<int>(quan::pow<0>(L1));
       QUAN_CHECK( v1 == 1);
       quan::area::ft2 A1(20);
       int v2 = check_is_same<int>(quan::pow<0>(A1));
       QUAN_CHECK( v2 == 1);

       int v1a = check_is_same<int>(quan::pow<0,1>(L1));
       QUAN_CHECK( v1a == 1);

       int v2a = check_is_same<int>(quan::pow<0,2>(A1));
       QUAN_CHECK( v2a == 1);

       quan::length_<int>::m L2(200);
       int v3 = check_is_same<int>(quan::pow<0>(L2));
       QUAN_CHECK( v3 == 1);
       quan::area_<long>::ft2 A2(20);
       int v4 = check_is_same<int>(quan::pow<0>(A2));
       QUAN_CHECK( v4 == 1);

       int v3a = check_is_same<int>(quan::pow<-0,8>(L2));
       QUAN_CHECK( v3a == 1);
       int v4a = check_is_same<int>(quan::pow<0,-3>(A2));
       QUAN_CHECK( v4a == 1);
   }

   void test_pow1()
   {
       quan::length::m L1(200);
       quan::length::m r1 
       = check_is_same<
           quan::length::m
       >( quan::pow<1,1>(L1) );
       QUAN_CHECK( r1 == L1);
       QUAN_CHECK( r1.numeric_value() == L1.numeric_value());

       quan::length::m r1a 
       = check_is_same<
           quan::length::m
       >( quan::pow<-1,-1>(L1) );
       QUAN_CHECK( r1 == L1);
       QUAN_CHECK( r1a.numeric_value() == L1.numeric_value());

       quan::length::m r1b
       = check_is_same<
           quan::length::m
       >( quan::pow<10,10>(L1) );
       QUAN_CHECK( r1b == L1);
       QUAN_CHECK( r1b.numeric_value() == L1.numeric_value());

       quan::length::m r1c
       = check_is_same<
           quan::length::m
       >( quan::pow<-10,-10>(L1) );
       QUAN_CHECK( r1c == L1);
       QUAN_CHECK( r1c.numeric_value() == L1.numeric_value());

       quan::area::ft2 A1(20);
       quan::area::ft2 v2 
       = check_is_same<
           quan::area::ft2
       >(quan::pow<1>(A1));
       QUAN_CHECK( v2 == A1);
       QUAN_CHECK( v2.numeric_value() == A1.numeric_value());

       quan::length_<int>::m L2(200);
       quan::length_<int>::m r3
       = check_is_same<
           quan::length_<int>::m 
       >( quan::pow<1>(L2));
       QUAN_CHECK( r3 == L2);
       QUAN_CHECK( r3.numeric_value() == L2.numeric_value());
       quan::area_<long>::ft2 A2(20);
       quan::area_<long>::ft2 v4 = check_is_same<
           quan::area_<long>::ft2
       >(quan::pow<1>(A2));
       QUAN_CHECK( v4.numeric_value() == A2.numeric_value());

   }

   void test_power_functions()
   {
   //power functions
   ///////////////////////////////////
       quan::length::m  L1(10.);
      
       QUAN_CHECK_CLOSE ( 
           (quan::pow<-1>(L1)).numeric_value() , 
           (1/L1).numeric_value(), 
           FP_MAX_DIFFERENCE
       ); 


       // should be exactly this calc
       QUAN_CHECK ( ((quan::pow<3,2>(L1)).numeric_value() == std::pow(10., 3./2)));

       quan::area::m2   A1 = quan::pow<2>(L1);
       QUAN_CHECK( (A1.numeric_value() == 100.));

       quan::volume::m3 V1 = quan::pow<3,1>(L1);
       QUAN_CHECK(( V1.numeric_value() == 1000.));

      //inevitable loss of accuracy in roots
       quan::area::m2 A2 = quan::pow<2,3>(V1);
       QUAN_CHECK_CLOSE (A2.numeric_value() , 100., FP_MAX_DIFFERENCE);

       quan::length::m L2 = quan::pow<1,3>(V1);
       QUAN_CHECK_CLOSE (L2.numeric_value(),10., FP_MAX_DIFFERENCE);

       // should be exact calc
       quan::area::mm2 A3 = quan::pow<2,1>(L1);
       QUAN_CHECK( A3.numeric_value() == 100000000.);
       quan::volume::km3 V3 = quan::pow<3,1>(L1);
       QUAN_CHECK( V3.numeric_value() == 1e-6);

       quan::area::in2 A4 = quan::length::cm(100) * quan::length::cm(100);
       quan::length::in L4 = quan::sqrt(A4);
       QUAN_CHECK_CLOSE( L4.numeric_value(), 100. / 2.54, 0.01);
       quan::length::cm L4A = L4;
       QUAN_CHECK_CLOSE(L4A.numeric_value(),100., FP_MAX_DIFFERENCE);
   }

}//anon
