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

/*
    double used at some points should be modified to quan::quantity_trait::default_value_type
    in case default is changed...todo

*/

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>
#include <quan/meta/min_type.hpp>
#include <quan/config.hpp>
#if ! defined QUAN_NO_RTTI
#include <typeinfo>
#endif

namespace {

   void uv_dimensioned_multiply_test();
   void uv_dimensioned_divide_test();
   void uv_dimensionless_multiply_test();
   void uv_dimensionless_divide_test();
   void uv_addition_test();
   void uv_subtraction_test();
   void uv_initialise_test();
   void uv_assign_test();

}

void united_value_test() ///////////////
{
    uv_dimensioned_multiply_test();
    uv_dimensioned_divide_test();
    uv_dimensionless_multiply_test();
    uv_dimensionless_divide_test();
    uv_addition_test();
    uv_subtraction_test();
    uv_initialise_test();
    uv_assign_test();
};

#if 1
int errors = 0;
int main()
{
   united_value_test();
   EPILOGUE
}
#endif

namespace{

    typedef  quan::meta::conversion_factor<
        quan::meta::rational<3>
    > coh_unit3;
    using quan::detail::united_value;
    typedef  quan::meta::conversion_factor<
        quan::meta::rational<0>
    > coh_unit0;
    typedef  quan::meta::conversion_factor<
        quan::meta::rational<-3>
    > coh_unitn3;

    typedef  quan::meta::conversion_factor<
        quan::meta::rational<3>
    > coh_unit3;

   void uv_initialise_test()
   {
       using quan::detail::united_value;
       united_value<coh_unit0,int> u0 = united_value<coh_unit3,int>(1);
       QUAN_CHECK_EQUAL(u0.raw_value(), 1000);
       
       united_value<coh_unit0,double> u1 = united_value<coh_unitn3,int>(1);
       QUAN_CHECK_CLOSE(u1.raw_value(), 1e-3, 1.e-15);
   }

   void uv_assign_test()
   {
       using quan::detail::united_value;
       united_value<coh_unit0,int> u0(100);
       u0 = united_value<coh_unit3,int>(1);
       QUAN_CHECK_EQUAL(u0.raw_value(), 1000);
       
       united_value<coh_unit0,double> u1(0);
       u1 = united_value<coh_unitn3,int>(1);
       QUAN_CHECK_CLOSE(u1.raw_value(), 1e-3, 1.e-15);
   }

   void uv_dimensioned_multiply_test()
   {
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result1,
   //        (dimensioned_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) ))) ;
   //#else
   //        quan::detail::dimensioned_multiply_functor<
   //            coh_unit3,double,coh_unit0,double
   //        >::result_type result1
   //        = dimensioned_multiply(
   //            quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) 
   //        );
   //#endif
   //    QUAN_CHECK_CLOSE(result1.raw_value() ,1., 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result2,
   //        (dimensioned_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) ))) ;
   //#else
   //        quan::detail::dimensioned_multiply_functor<
   //            coh_unitn3,double,coh_unit0,double
   //        >::result_type result2
   //        = dimensioned_multiply(
   //            quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) 
   //        );
   //#endif
   //    QUAN_CHECK_CLOSE(result2.raw_value(),1., 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result2a,
   //        (dimensioned_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit3,double>(1) ))) ;
   //#else
   //     quan::detail::dimensioned_multiply_functor<
   //            coh_unitn3,double,coh_unit3,double
   //     >::result_type result2a
   //     = dimensioned_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit3,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result2a.raw_value(),1., 1.e-12);
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //     QUAN_AUTO(result2b,
   //        (dimensioned_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) ))) ;
   //#else
   //     quan::detail::dimensioned_multiply_functor<
   //            coh_unit3,double,coh_unitn3,double
   //     >::result_type result2b
   //     = dimensioned_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) );
   //#endif 
   //    QUAN_CHECK_CLOSE(result2b.raw_value(),1., 1.e-12);
   }
   void uv_dimensioned_divide_test()
   {
      // using quan::length;
       using quan::meta::si_unit;

       typedef quan::detail::dimensioned_divide<
           si_unit::none::multiplier,
           si_unit::none::multiplier
       > func0;

       QUAN_CHECK_CLOSE((func0::eval<int,int>()(1,1)), 1., 1e-12);
       QUAN_CHECK_CLOSE( (func0::eval<int,int>()(1,2)),0.5,1e-12);
       QUAN_CHECK(( func0::eval<int,int>()(2,1)== 2.0));
       QUAN_CHECK(( func0::eval<int,int>()(-2,1) == -2.0f));
       QUAN_CHECK(( func0::eval<int,int>()(1000,2) == 500.0));
       QUAN_CHECK(( func0::eval<int,int>()(1000,-2) == -500.0));
#if ! defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(func0::eval<int,int>()(1,1)) == typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func0::eval<unsigned int,unsigned int>()(1,1)) == typeid(quan::meta::min_default_value_type<unsigned int>::type)) );
       QUAN_CHECK( (typeid(func0::eval<long,long>()(1,1)) == typeid(quan::meta::min_default_value_type<long>::type)) );
       QUAN_CHECK( (typeid(func0::eval<unsigned long,unsigned long>()(1,1)) == typeid(quan::meta::min_default_value_type<unsigned long>::type)) );
       QUAN_CHECK( (typeid(func0::eval<float,int>()(1,1)) == typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func0::eval<int,float>()(1,1)) == typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func0::eval<float,float>()(1,1)) == typeid(float)) );
       QUAN_CHECK( (typeid(func0::eval<double,int>()(1,1)) == typeid(double)) );
       QUAN_CHECK( (typeid(func0::eval<double,double>()(1,1)) == typeid(double)) );
       QUAN_CHECK( (typeid(func0::eval<double,float>()(1,1)) == typeid(double)) );
       QUAN_CHECK( (typeid(func0::eval<long double,int>()(1,1)) == typeid(long double)) );
#endif

       //constant resolves to 2.54
       typedef quan::detail::dimensioned_divide<
           quan::meta::get_conversion_factor<quan::length::in::unit>::type::multiplier::type,
           si_unit::none::multiplier
       > func1;

       QUAN_CHECK_EQUAL( (func1::eval<int,int>()(1,1) ) , 2.54);
       QUAN_CHECK_EQUAL( (func1::eval<int,int>()(1,1) ) , 2540000./1000000);
       QUAN_CHECK_EQUAL( (func1::eval<float,float>()(1,1) ) , 2.54f);
       QUAN_CHECK_EQUAL( (func1::eval<float,float>()(1,1) ) , 2540000.f/1000000);
       QUAN_CHECK_CLOSE( (func1::eval<float,double>()(1,1) ) , 2.54, 1e-12);
       QUAN_CHECK_CLOSE( (func1::eval<float,float>()(2,4) ) , 2.54f / 2, 1e-12f);
       func1::eval<float,float>()(3,6);
       func1::eval<float,float>()(3,-6);
       QUAN_CHECK_CLOSE( (func1::eval<float,float>()(3,-6) ) , -2.54f / 2, 1e-12f);
       QUAN_CHECK_CLOSE( (func1::eval<double,double>()(-200,100) ) , -2 * 2.54, 1e-12);
       QUAN_CHECK_CLOSE( (func1::eval<double,double>()(200,-100) ) , 2 * -2.54, 1e-12);
#if ! defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(func1::eval<int,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1::eval<float,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1::eval<double,int>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1::eval<long double,int>()(1,1)) ==typeid(long double)) );
       QUAN_CHECK( (typeid(func1::eval<float,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1::eval<int,float>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1::eval<float,float>()(1,1)) ==typeid(float)) );
       QUAN_CHECK( (typeid(func1::eval<double,int>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1::eval<double,double>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1::eval<double,float>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1::eval<long double,int>()(1,1)) ==typeid(long double)) );
       QUAN_CHECK( (typeid(func1::eval<float,double>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1::eval<double,float>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1::eval<double,long double>()(1,1)) ==typeid(long double)) );
       QUAN_CHECK( (typeid(func1::eval<long double,double>()(1,1)) ==typeid(long double)) );
#endif
       //constant resolves to 1/2.54
       typedef quan::detail::dimensioned_divide<
            si_unit::none::multiplier,
           quan::meta::get_conversion_factor<quan::length::in::unit>::type::multiplier::type
       > func1r;

       QUAN_CHECK_CLOSE( (func1r::eval<float,float>()(1,1) ) , 1/2.54F, 1e-12F);
       QUAN_CHECK_CLOSE( (func1r::eval<float,double>()(1,1) ) , 1/2.54, 1e-12);
       QUAN_CHECK_CLOSE( (func1r::eval<float,float>()(2,4) ) , 1/(2.54F * 2), 1e-12F);
       QUAN_CHECK_CLOSE( (func1r::eval<float,float>()(3,-6) ) , 1/(-2.54F * 2), 1e-12F);
       QUAN_CHECK_CLOSE( (func1r::eval<double,double>()(-200,100) ) , -2 * 1/2.54, 1e-12);
       QUAN_CHECK_CLOSE( (func1r::eval<double,double>()(200,-100) ) , 2 * 1/-2.54, 1e-12);
#if ! defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(func1r::eval<int,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1r::eval<float,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1r::eval<double,int>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1r::eval<long double,int>()(1,1)) ==typeid(long double)) );
       QUAN_CHECK( (typeid(func1r::eval<float,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1r::eval<int,float>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func1r::eval<float,float>()(1,1)) ==typeid(float)) );
       QUAN_CHECK( (typeid(func1r::eval<double,int>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1r::eval<double,double>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1r::eval<double,float>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1r::eval<long double,int>()(1,1)) ==typeid(long double)) );
       QUAN_CHECK( (typeid(func1r::eval<float,double>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1r::eval<double,float>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func1r::eval<double,long double>()(1,1)) ==typeid(long double)) );
       QUAN_CHECK( (typeid(func1r::eval<long double,double>()(1,1)) ==typeid(long double)) );
#endif
       //constant resolves to 1
       typedef quan::detail::dimensioned_divide<
          quan::meta::get_conversion_factor<quan::length::ft::unit>::type::multiplier::type,
          quan::meta::get_conversion_factor<quan::length::ft::unit>::type::multiplier::type
       > func2;
       QUAN_CHECK(( func2::eval<int,int>()(1,1) == 1));
       QUAN_CHECK(( func2::eval<int,int>()(1,2) == 0.5f));
       QUAN_CHECK(( func2::eval<int,int>()(2,1) ==2.f));
       QUAN_CHECK(( func2::eval<int,int>()(-2,1) ==-2));
       QUAN_CHECK(( func2::eval<int,int>()(1000,2) == 500));
       QUAN_CHECK(( func2::eval<int,int>()(1000,-2) == -500));
#if ! defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(func2::eval<int,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func2::eval<unsigned int,unsigned int>()(1,1)) ==typeid(quan::meta::min_default_value_type<unsigned int>::type)) );
       QUAN_CHECK( (typeid(func2::eval<long,long>()(1,1)) ==typeid(quan::meta::min_default_value_type<long>::type)) );
       QUAN_CHECK( (typeid(func2::eval<unsigned long,unsigned long>()(1,1)) ==typeid(quan::meta::min_default_value_type<unsigned long>::type)) );
       QUAN_CHECK( (typeid(func2::eval<float,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func2::eval<int,float>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func2::eval<float,float>()(1,1)) ==typeid(float)) );
       QUAN_CHECK( (typeid(func2::eval<double,int>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func2::eval<double,double>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func2::eval<double,float>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func2::eval<long double,int>()(1,1)) ==typeid(long double)) );
 #endif
       // uses runtime constant division (usually resolved to a constant by the compiler)
       typedef quan::detail::dimensioned_divide<
          quan::meta::get_conversion_factor<quan::length::pica_comp::unit>::type::multiplier::type,
          quan::meta::get_conversion_factor<quan::length::ft_us::unit>::type::multiplier::type
       > func3;
       float const constf = 4233333.F/3048006.F;
       typedef quan::quantity_traits::default_value_type real;
       real const constd = static_cast<real>(4233333L)/static_cast<real>(3048006L);
       QUAN_CHECK_CLOSE((func3::eval<float,double>()(1,1)) ,constd, 1e-12 );
       QUAN_CHECK_CLOSE((func3::eval<int,int>()(1,1)) ,constd ,1e-12);
       QUAN_CHECK_CLOSE((func3::eval<float,int>()(1,1)) ,constd,1e-12 );
       QUAN_CHECK_EQUAL((func3::eval<int,int>()(1,2)), (static_cast<real>(1)/2) * constd);
       QUAN_CHECK_EQUAL((func3::eval<int,int>()(2,1)) , (static_cast<real>(2)/1) * constd);
       QUAN_CHECK_EQUAL((func3::eval<int,int>()(-2,1)), (static_cast<real>(-2)/ 1) * constd);
       QUAN_CHECK_EQUAL(( func3::eval<int,int>()(1001,2)) ,
           (static_cast<real>(1001)/2 ) * constd );
       QUAN_CHECK_EQUAL(( func3::eval<int,int>()(1000,-2)), 
           (static_cast<real>(1000)/-2) * constd);
#if ! defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(func3::eval<int,int>()(1,1)) ==typeid(real)) );
       QUAN_CHECK( (typeid(func3::eval<unsigned int,unsigned int>()(1,1)) ==typeid(real)) );
       QUAN_CHECK( (typeid(func3::eval<long,long>()(1,1)) ==typeid(real)) );
       QUAN_CHECK( (typeid(func3::eval<unsigned long,unsigned long>()(1,1)) ==typeid(real)) );
       QUAN_CHECK( (typeid(func3::eval<float,int>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func3::eval<int,float>()(1,1)) ==typeid(quan::meta::min_default_value_type<int>::type)) );
       QUAN_CHECK( (typeid(func3::eval<float,float>()(1,1)) ==typeid(float)) );
       QUAN_CHECK( (typeid(func3::eval<double,int>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func3::eval<double,double>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func3::eval<double,float>()(1,1)) ==typeid(double)) );
       QUAN_CHECK( (typeid(func3::eval<long double,int>()(1,1)) ==typeid(long double)) );
#endif
   }
   void uv_dimensionless_multiply_test()
   {
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result7,
   //        (dimensionless_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) ))) ;
   //#else
   //    quan::detail::dimensionless_multiply_functor<
   //        double,coh_unit3,double,coh_unit0
   //    >::result_type result7
   //    = dimensionless_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) ) ;
   //#endif
   //    QUAN_CHECK_CLOSE(result7 ,1000., 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result8,
   //        (dimensionless_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) ))) ;
   //#else
   //     quan::detail::dimensionless_multiply_functor<
   //        double,coh_unitn3,double,coh_unit0
   //    >::result_type result8
   //    = dimensionless_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result8,0.001, 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result9,
   //        (dimensionless_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) ))) ;
   //#else
   //    quan::detail::dimensionless_multiply_functor<
   //        double,coh_unit3,double,coh_unitn3
   //    >::result_type result9
   //    = dimensionless_multiply(quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result9 ,1., 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result10,
   //        (dimensionless_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit3,double>(1) ))) ;
   //#else
   //     quan::detail::dimensionless_multiply_functor<
   //        double,coh_unitn3,double,coh_unit3
   //    >::result_type result10
   //    = dimensionless_multiply(quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit3,double>(1) );
   //#endif
   //     QUAN_CHECK_CLOSE(result10,1., 1.e-12);
   }

   void uv_dimensionless_divide_test()
   {
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result1,(dimensionless_divide(
   //            quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) )));
   //#else
   //     quan::detail::dimensionless_divide_functor<
   //        double,coh_unitn3,double,coh_unit0
   //    >::result_type result1
   //    = dimensionless_divide(
   //            quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit0,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result1,.001, 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result2,(dimensionless_divide(
   //            quan::detail::united_value<coh_unit0,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) )));
   //#else
   //     quan::detail::dimensionless_divide_functor<
   //        double,coh_unit0,double,coh_unitn3
   //    >::result_type result2
   //    = dimensionless_divide(
   //            quan::detail::united_value<coh_unit0,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result2,1000., 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result3,(dimensionless_divide(
   //            quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit3,double>(1) )));
   //#else
   //     quan::detail::dimensionless_divide_functor<
   //        double,coh_unitn3,double,coh_unit3
   //    >::result_type result3
   //    = dimensionless_divide(
   //            quan::detail::united_value<coh_unitn3,double>(1)
   //        , quan::detail::united_value<coh_unit3,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result3,1e-6, 1.e-12);
   //
   //#ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
   //    QUAN_AUTO(result4,(dimensionless_divide(
   //            quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) )));
   //#else
   //  quan::detail::dimensionless_divide_functor<
   //        double,coh_unit3,double,coh_unitn3
   //    >::result_type result4
   //    = dimensionless_divide(
   //            quan::detail::united_value<coh_unit3,double>(1)
   //        , quan::detail::united_value<coh_unitn3,double>(1) );
   //#endif
   //    QUAN_CHECK_CLOSE(result4,1e6, 1.e-12);
   }

   void uv_addition_test()
   {
   #ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
       QUAN_AUTO(result3,(quan::detail::united_value<coh_unitn3,double>(1)
           + quan::detail::united_value<coh_unit0,double>(1) )) ;
   #else
       quan::meta::binary_op<
          quan::detail::united_value<coh_unitn3,double>,
          quan::meta::plus ,
           quan::detail::united_value<coh_unit0,double>
       >::type result3 
       = quan::detail::united_value<coh_unitn3,double>(1)
           + quan::detail::united_value<coh_unit0,double>(1);
   #endif
       QUAN_CHECK_CLOSE(result3.raw_value(),1001., 1.e-12);

   #ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
       QUAN_AUTO(result4,(quan::detail::united_value<coh_unit3,double>(1)
           + quan::detail::united_value<coh_unit0,double>(1) )) ;
   #else
       quan::meta::binary_op<
          quan::detail::united_value<coh_unit3,double>,
          quan::meta::plus ,
           quan::detail::united_value<coh_unit0,double>
       >::type result4
       = quan::detail::united_value<coh_unit3,double>(1)
           + quan::detail::united_value<coh_unit0,double>(1);
   #endif
       QUAN_CHECK_CLOSE(result4.raw_value(),1001., 1.e-12);

   }
   void uv_subtraction_test()
   {
    #ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
       QUAN_AUTO(result5,(quan::detail::united_value<coh_unit3,double>(1)
           - quan::detail::united_value<coh_unit0,double>(1) )) ;
   #else
        quan::meta::binary_op<
          quan::detail::united_value<coh_unit3,double>,
          quan::meta::plus ,
           quan::detail::united_value<coh_unit0,double>
       >::type result5
       = quan::detail::united_value<coh_unit3,double>(1)
           - quan::detail::united_value<coh_unit0,double>(1);
   #endif
       QUAN_CHECK_CLOSE(result5.raw_value(),999., 1.e-12);

    #ifdef QUAN_USE_QUAN_TYPEOF_BINARY_OPERATION
       QUAN_AUTO(result6,(quan::detail::united_value<coh_unitn3,double>(1)
           - quan::detail::united_value<coh_unit0,double>(1) )) ;
   #else
       quan::meta::binary_op<
          quan::detail::united_value<coh_unitn3,double>,
          quan::meta::minus ,
           quan::detail::united_value<coh_unit0,double>
       >::type result6
       = quan::detail::united_value<coh_unitn3,double>(1)
           - quan::detail::united_value<coh_unit0,double>(1);
   #endif
       QUAN_CHECK_CLOSE(result6.raw_value(),-999., 1.e-12);

   }

}
