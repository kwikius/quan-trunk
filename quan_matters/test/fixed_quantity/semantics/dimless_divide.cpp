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
#include <quan/time.hpp>
#include <quan/frequency.hpp>
#include <quan/reciprocal_time.hpp>
#include <quan/resistance.hpp>
#include <quan/length.hpp>
#include <quan/meta/eval_rational.hpp>
#include <quan_matters/test/utility/eval_exponent.hpp>
#include <type_traits>
#include <typeinfo>

/*
    dimensionless divide ( ***working but unfinished ***
*/

namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(coh_coh_divides_test)
    QUAN_TEST_FUN(coh_incoh_divides_test)
    QUAN_TEST_FUN(incoh_incoh_divides_test)
    QUAN_TEST_FUN(test_zero_exp_2div)
    QUAN_TEST_FUN(test_zero_exp_unitary_div)
    QUAN_TEST_FUN(test_zero_exp_1_rational_div)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_1_div)
    QUAN_TEST_FUN(test_zero_exp_integer_1div)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_1_div)
#if 0
    QUAN_TEST_FUN(test_rt_negative_integer_exp_2div)
#endif

#undef QUAN_TEST_FUN
}

void dimless_divide_test()
{
#define QUAN_TEST_FUN(fun) fun();
    QUAN_TEST_FUN(coh_coh_divides_test)
    QUAN_TEST_FUN(coh_incoh_divides_test)
    QUAN_TEST_FUN(incoh_incoh_divides_test)
    QUAN_TEST_FUN(test_zero_exp_2div)
    QUAN_TEST_FUN(test_zero_exp_unitary_div)
    QUAN_TEST_FUN(test_zero_exp_1_rational_div)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_1_div)
    QUAN_TEST_FUN(test_zero_exp_integer_1div)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_1_div)

#if 0
   //failing currently
    QUAN_TEST_FUN(test_rt_negative_integer_exp_2div)
#endif

#undef QUAN_TEST_FUN
}
namespace {

//helper
    template <typename PQA,typename PQB>
    struct xdivides{
        typedef typename quan::meta::binary_op<
            PQA,quan::meta::divides,PQB
        >::type type;
    };


   template <typename ConversionFactor_L,typename ConversionFactor_R>
   struct check_div
   {
       typedef typename ConversionFactor_L::exponent exp_L;
       typedef typename ConversionFactor_R::exponent exp_R; 
       typedef typename quan::meta::binary_op<
           exp_L, quan::meta::minus, exp_R
       >::type exponent;
      
       template <typename Result,typename Lhs, typename Rhs>
       static Result func ( Lhs const & lhs, Rhs const& rhs)
       {
           typename quan::meta::eval_exponent<exponent>::eval exp_eval;
           typename quan::meta::eval_rational<typename ConversionFactor_L::multiplier> mux_L;
           typename quan::meta::eval_rational<typename ConversionFactor_R::multiplier> mux_R;
        /*   std::cout << " exp ("<< exponent::numerator << "/" << exponent::denominator 
           << ") = " << exp_eval() <<'\n';
           std::cout << "mul_L (" << ConversionFactor_L::multiplier::numerator << "/" 
               << ConversionFactor_L::multiplier::denominator << ") = " << mux_L() << '\n';
           std::cout << "mul_R (" << ConversionFactor_R::multiplier::numerator << "/" 
               << ConversionFactor_R::multiplier::denominator << ") = " << mux_R() << '\n';*/
           Result result = (static_cast<Result>(lhs) / rhs) 
           * static_cast<Result>(exp_eval()) * (static_cast<Result>(mux_L())/mux_R());
           return result;
       }
   };

   // coherent / coherent
   void coh_coh_divides_test()
   {
       quan::resistance::R r1(24);
       quan::resistance::R r2(12);
       typedef xdivides<
           quan::resistance::R,
           quan::resistance::R
       >::type result_type1;
       QUAN_CHECK( (std::is_same<result_type1,QUAN_FLOAT_TYPE>::value ==true));
       result_type1 result1 = r1 / r2;
       QUAN_CHECK_CLOSE(result1, QUAN_FLOAT_TYPE(2.) ,1e-12);

       quan::resistance::kR r3(24);
       quan::resistance::mR r4(12);
       typedef xdivides<
           quan::resistance::kR,
           quan::resistance::mR
       >::type result_type2;
       QUAN_CHECK( (std::is_same<result_type2,QUAN_FLOAT_TYPE>::value ==true));
       result_type2 result2 = r3 / r4;
       QUAN_CHECK_CLOSE(result2, 2e6 ,1e-6);

       quan::resistance::mR r5(24);
       quan::resistance::kR r6(12);
       typedef xdivides<
           quan::resistance::mR,
           quan::resistance::kR
       >::type result_type3;
       QUAN_CHECK( (std::is_same<result_type3,QUAN_FLOAT_TYPE>::value ==true));
       result_type3 result3 = r5 / r6;
       QUAN_CHECK_CLOSE(result3, 2.e-6,1e-12);

       quan::length_<int64_t>::mm i_mm(2);
       quan::length_<int64_t>::km i_km(3);
       int64_t value = i_mm/i_km;
       QUAN_CHECK(value == 0 );
       int64_t value1 = i_km/i_mm;
    
       QUAN_CHECK_EQUAL(value1 , 3000000/2);
       
   }
   // coherent / incoherent
   void coh_incoh_divides_test()
   {
       quan::length::cm cm(2);
       quan::length::in in(1);

       QUAN_CHECK_CLOSE(in/cm,2.54/2.,1e-12);
       QUAN_CHECK_CLOSE(cm/in,2./2.54,1e-12);

       quan::length::mi mi(2);
       quan::length::km km(1);
       QUAN_CHECK_CLOSE( mi / km , 2 * 1.609344 ,1e-12);
       QUAN_CHECK_CLOSE( km / mi , 1 /(2 * 1.609344) ,1e-12);

       quan::time::s t1(1);
       quan::time::min t2(1);
       double time_ratio1 = t1 / t2;
       QUAN_CHECK_CLOSE (time_ratio1, 1/60. ,1e-12);
       double time_ratio2 = t2/t1;
       QUAN_CHECK_CLOSE(time_ratio2,60. ,1e-12);
       quan::time::h t3(1);
       double min_div_hr = t2/t3;
       QUAN_CHECK_CLOSE (min_div_hr, 1/60. ,1e-12);
       double hr_div_min = t3/t2;
       QUAN_CHECK_CLOSE (hr_div_min, 60. ,1e-12);
       
   }

   // inco / inco
   void incoh_incoh_divides_test()
   {
       quan::length::ft ft(0.5);
       quan::length::in in(2);
       QUAN_CHECK_CLOSE( in/ft, 1./3, 1e-12);
       QUAN_CHECK_CLOSE( ft/in, 3., 1e-12);
       quan::length::yd yd(3);
       quan::length::mi mi(2);
       QUAN_CHECK_CLOSE(mi/yd,1760. * 2 / 3.,1e-12);
       QUAN_CHECK_CLOSE(yd/mi, 3 /(1760. * 2),1e-12);
   }

   void test_zero_exp_unitary_div()
   {
       // exponent of result is zero and single mutiplier is 1
       // hence no scaling should occur.
       // but promotion of integer inputs.

       // The actual calc is the same as for dimensioned multiply
       // in this case
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<1000000,9999999>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<1000000,9999999>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       > mul;
       #if !defined QUAN_NO_RTTI 
       QUAN_CHECK((typeid(mul::eval<int,int>()(1,1)) == typeid(double)));
       #endif
       QUAN_CHECK((std::is_same<decltype(mul::eval<int,int>()(1,1)),double>::value));
       double val1 = mul::eval<int,int>()(100,200);
       double val1_chk = 100. / 200.;
       QUAN_CHECK_EQUAL(val1,val1_chk);
       #if !defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(mul::eval<int,double>()(1,1)) == typeid(double)));
       #endif
       QUAN_CHECK((std::is_same<decltype(mul::eval<int,double>()(1,1)),double>::value));
       double val2 = mul::eval<int,double>()(100,200);
       double val2_chk = 100. / 200.;
       QUAN_CHECK_EQUAL(val2,val2_chk);
       #if !defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(mul::eval<float, float>()(1,1)) == typeid(float)));
       #endif
       QUAN_CHECK((std::is_same<decltype(mul::eval<float,float>()(1,1)),float>::value));
       float val3 = mul::eval<float,float>()(-0.1f,33);
       float val3_chk = -0.1f / 33.f;
       QUAN_CHECK_EQUAL(val3,val3_chk); 
   }

   void test_zero_exp_integer_1div()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<7,1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<1,9>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       > div;
       #if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<int,int>()(1,1)) == typeid(double)));
       #endif
       QUAN_CHECK((std::is_same<decltype(div::eval<int,int>()(1,1)),double>::value))
       double val1 = div::eval<int,int>()(100,3);
       double val1_chk = (100 /3.) * (63.);
       QUAN_CHECK_EQUAL(val1,val1_chk);
       #if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<float,int>()(1,1)) == typeid(double)));
       #endif
       QUAN_CHECK((std::is_same<decltype(div::eval<float,int>()(1,1)),double>::value))
       float in2 = -5.f;
       float val2 =div::eval<float,int>()(in2, 4);
       float val2_chk = (in2 / 4) * (63.f);
       QUAN_CHECK_CLOSE(val2,val2_chk,1.e-12f);
   }

   void test_zero_exp_1_rational_div()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<7,1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<9,1>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       > div;
#if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<int,int>()(1,1)) == typeid(double)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<int,int>()(1,1)),double>::value))
       double val1 = div::eval<int,int>()(100,3);
       double val1_chk = (100 /3.) * (7./ 9.);
       QUAN_CHECK_EQUAL(val1,val1_chk);
#if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<float,int>()(1,1)) == typeid(double)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<float,int>()(1,1)),double>::value))
       float in2 = -.1f;
       float val2 =div::eval<float,float>()(in2, 3.f);
       float val2_chk = (in2 / 3.f) * (7.f/9.f);
       QUAN_CHECK_CLOSE(val2,val2_chk,1.e-12f);
   }

   // tests of the low level conversion_factor conversion functions
   void test_zero_exp_2div()
   {
       // exponent of result is zero
      
       // The actual calc is the same as for dimensioned multiply
       // in this case
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<9999999,1000000>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<1000000,9999999>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       >::type div;
#if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<int,int>()(1,1)) == typeid(double)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<int,int>()(1,1)),double>::value))
       double val1 = div::eval<int,int>()(100,200);
       double val1_chk = 100. / 200 * (9999999. * 9999999.) / (1000000. * 1000000.);
       QUAN_CHECK_EQUAL(val1,val1_chk);
       
#if !defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(div::eval<int,double>()(1,1)) == typeid(double)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<int,double>()(1,1)),double>::value))
       double val2 = div::eval<int,double>()(100,200);
       double val2_chk = 100. / 200 * (9999999. * 9999999.) / (1000000. * 1000000.);
       QUAN_CHECK_EQUAL(val2,val2_chk);
#if !defined QUAN_NO_RTTI
       QUAN_CHECK( (typeid(div::eval<float, float>()(1,1)) == typeid(float)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<float,float>()(1,1)),float>::value))
       float val3 = div::eval<float,float>()(-0.1f,33);
       float val3_chk = -0.1f / 33.f * (9999999.f * 9999999.f) / (1000000.f * 1000000.f);
       QUAN_CHECK_CLOSE(val3,val3_chk,1e-5); 
   }

   void test_ct_positive_integer_exp_1_div()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<9>,
           quan::meta::rational<3,2>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<3>,
           quan::meta::rational<8,2>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       >::type div;
#if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<int,int>()(1,1)) == typeid(double)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<int,int>()(1,1)),double>::value))
       double val1 = div::eval<int,int>()(100,200);
       double val2 = check_div<conversion_factor_L,conversion_factor_R>::func<double>(100,200);
       QUAN_CHECK_EQUAL(val1,val2);
   }

   void test_rt_positive_integer_exp_1_div()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<15>,
           quan::meta::rational<3,2>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<3>,
           quan::meta::rational<8,2>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       >::type div;
#if !defined QUAN_NO_RTTI
       QUAN_CHECK((typeid(div::eval<int,int>()(1,1)) == typeid(double)));
#endif
       QUAN_CHECK((std::is_same<decltype(div::eval<int,int>()(1,1)),double>::value))
       double val1 = div::eval<int,int>()(100,200);
       double val2 = check_div<conversion_factor_L,conversion_factor_R>::func<double>(100,200);
       QUAN_CHECK_EQUAL(val1,val2);
   }

   #if 0
   void test_rt_negative_integer_exp_2div()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-20>,
           quan::meta::rational<33333333,10000000>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<3>,
           quan::meta::rational<8,2>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_divide1<
           conversion_factor_L, conversion_factor_R
       >::type div;
       QUAN_CHECK((typeid(div::eval<int,int>()(1,1)) == typeid(double)));

       double val1 = div::eval<int,int>()(100,200);
       double val2 = check_div<conversion_factor_L,conversion_factor_R>::func<double>(100,200);
       QUAN_CHECK_CLOSE(val1,val2, 1e-13);

   }
#endif

}
