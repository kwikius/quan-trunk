// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/time.hpp>
#include <quan/frequency.hpp>
#include <quan/reciprocal_time.hpp>
#include <quan/resistance.hpp>
#include <quan/conductance.hpp>
#include <type_traits>
#include <typeinfo>

/*
    dimensionless multiply tests

    dimensionless multiply is the front end for
    various specialisations of the dimensionless multiply calculation
    for the numeric values of 2 quantities
    see <$QUAN_ROOT/detail/united_value/operations/dimensionless_multiply.hpp>
    for more details
    
*/

namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(si_si_multiply_test)
    QUAN_TEST_FUN(si_non_si_multiply_test)
    QUAN_TEST_FUN(non_si_si_multiply_test)
    QUAN_TEST_FUN(non_si_non_si_multiply_test)
    QUAN_TEST_FUN(test_zero_exp_unitary_mul)
    QUAN_TEST_FUN(test_zero_exp_1_integer_mul)
    QUAN_TEST_FUN(test_zero_exp_1_rational_mul)
    QUAN_TEST_FUN(test_zero_exp_2_mul)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_2mul)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_2mul)
    QUAN_TEST_FUN(test_ct_negative_integer_exp_2mul)
    QUAN_TEST_FUN(test_rt_negative_integer_exp_2mul)
    QUAN_TEST_FUN(test_rational_exp_2mul)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_1mul)
    QUAN_TEST_FUN(test_ct_negative_integer_exp_1mul)
    QUAN_TEST_FUN(test_rt_negative_integer_exp_1mul)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_1mul)
    QUAN_TEST_FUN(test_rational_exp_1mul)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_only)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_only)
    QUAN_TEST_FUN(test_rational_exp_only)
    QUAN_TEST_FUN(test_ct_negative_integer_exp_only)
    QUAN_TEST_FUN(test_rt_negative_integer_exp_only)

   #undef QUAN_TEST_FUN
}

void dimless_multiply_test()
{
#define QUAN_TEST_FUN(fun) fun();
    QUAN_TEST_FUN(si_si_multiply_test)
    QUAN_TEST_FUN(si_non_si_multiply_test)
    QUAN_TEST_FUN(non_si_si_multiply_test)
    QUAN_TEST_FUN(non_si_non_si_multiply_test)
    QUAN_TEST_FUN(test_zero_exp_unitary_mul)
    QUAN_TEST_FUN(test_zero_exp_1_integer_mul)
    QUAN_TEST_FUN(test_zero_exp_1_rational_mul)
    QUAN_TEST_FUN(test_zero_exp_2_mul)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_2mul)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_2mul)
    QUAN_TEST_FUN(test_ct_negative_integer_exp_2mul)
    QUAN_TEST_FUN(test_rt_negative_integer_exp_2mul)
    QUAN_TEST_FUN(test_rational_exp_2mul)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_1mul)
    QUAN_TEST_FUN(test_ct_negative_integer_exp_1mul)
    QUAN_TEST_FUN(test_rt_negative_integer_exp_1mul)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_1mul)
    QUAN_TEST_FUN(test_rational_exp_1mul)
    QUAN_TEST_FUN(test_ct_positive_integer_exp_only)
    QUAN_TEST_FUN(test_rt_positive_integer_exp_only)
    QUAN_TEST_FUN(test_rational_exp_only)
    QUAN_TEST_FUN(test_ct_negative_integer_exp_only)
    QUAN_TEST_FUN(test_rt_negative_integer_exp_only)

   #undef QUAN_TEST_FUN
}

//#include <iostream>
//helper
namespace{
    template <typename PQA,typename PQB>
    struct xtimes{
        typedef typename quan::meta::binary_op<
            PQA,quan::meta::times,PQB
        >::type type;
    };


   // si-unit * si-unit
   void si_si_multiply_test()
   {
       quan::resistance::R r1(24);
       quan::conductance::S s1(12);
       typedef xtimes<
           quan::resistance::R,
           quan::conductance::S
       >::type result_type1;
       QUAN_CHECK( (std::is_same<result_type1,QUAN_FLOAT_TYPE>::value ==true));
       result_type1 result1 = r1 * s1;
       QUAN_CHECK_CLOSE(result1, 288. ,1e-12);

       quan::resistance::kR r2(24);
       quan::conductance::kS s2(12);
       typedef xtimes<
           quan::resistance::kR,
           quan::conductance::kS
       >::type result_type2;
       QUAN_CHECK( (std::is_same<result_type2,QUAN_FLOAT_TYPE>::value ==true));
       result_type2 result2 = r2 * s2;
       QUAN_CHECK_CLOSE(result2, 288.e6 ,1e-6);

       quan::resistance::kR r3(24);
       quan::conductance::mS s3(12);
       typedef xtimes<
           quan::resistance::kR,
           quan::conductance::mS
       >::type result_type3;
       QUAN_CHECK( (std::is_same<result_type3,QUAN_FLOAT_TYPE>::value ==true));
       result_type3 result3 = r3 * s3;
       QUAN_CHECK_CLOSE(result3, 288.,1e-12);
   }
   // si-unit * non-si-unit
   void si_non_si_multiply_test()
   {
       quan::time::s secs(20);
       quan::reciprocal_time::per_min per_min(12);
       double value = secs * per_min;
       double value1 = static_cast<QUAN_FLOAT_TYPE>(20) 
               * static_cast<QUAN_FLOAT_TYPE>(12) 
               / static_cast<QUAN_FLOAT_TYPE>(60);
      // std::cout.precision(32);
       //std::cout << value <<'\n' << value1 <<'\n';

       // This may fail if the multiplier for reciprocal_time
       // in <quan/components/of_reciprocal_time.hpp>
       // is <16666667'/'10000000> rather than <100'/'60>
       QUAN_CHECK((value == value1 ));
       //
    
   }

   // non-si-unit * si-unit
   void non_si_si_multiply_test()
   {

       quan::time::s secs(20);
       quan::reciprocal_time::per_min per_min(12);
       double value =  per_min * secs;
       double value1 = static_cast<QUAN_FLOAT_TYPE>(12) 
               * static_cast<QUAN_FLOAT_TYPE>(20) 
               / static_cast<QUAN_FLOAT_TYPE>(60);
      // std::cout.precision(32);
       //std::cout << value <<'\n' << value1 <<'\n';

       // This may fail if the multiplier for reciprocal_time
       // in <quan/components/of_reciprocal_time.hpp>
       // is <16666667'/'10000000> rather than <100'/'60>
       QUAN_CHECK((value == value1 ));
     
   }


   void non_si_non_si_multiply_test()
   {
       quan::fixed_quantity<
           quan::meta::unit<
               quan::meta::components::of_reciprocal_time::abstract_quantity,
               quan::meta::conversion_factor<
                   quan::meta::rational<-3>,
                   quan::meta::rational<10,36>
               >
           >,
           double
       > per_hour(1);
       quan::time::min minutes(2.5);
       double value = minutes * per_hour;
       double value_chk = (2.5 * 1.) * (1./60.); ;

       // This may fail if the multiplier for reciprocal_time
       // in <quan/components/of_reciprocal_time.hpp>
       // is <16666667'/'10000000> rather than <100'/'60>
       QUAN_CHECK_EQUAL(value,value_chk);
       
     
   }
   // tests of the low level unit conversion functions
   void test_zero_exp_unitary_mul()
   {
       // exponent of result is zero and single mutiplier is 1
       // hence no scaling should occur.
       // no promotion of integer inputs.

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
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK((typeid(mul::eval<int,int>()(1,1)) == typeid(int)));
       int val1 = mul::eval<int,int>()(100,200);
       int val1_chk = 100 * 200;
       QUAN_CHECK_EQUAL(val1,val1_chk);
       
       QUAN_CHECK( (typeid(mul::eval<int,double>()(1,1)) == typeid(double)));
       double val2 = mul::eval<int,double>()(100,200);
       double val2_chk = 100. * 200.;
       QUAN_CHECK_EQUAL(val2,val2_chk);

       QUAN_CHECK( (typeid(mul::eval<float, float>()(1,1)) == typeid(float)));
       float val3 = mul::eval<float,float>()(-0.1f,33);
       float val3_chk = -0.1f * 33.f;
       QUAN_CHECK_EQUAL(val3,val3_chk); 
   }

   void test_zero_exp_1_integer_mul()
   {
       /* Exponent of result is zero
          Single multiplier is not 1
          Single multiplier is an integer
          Calculation is the same as dimensioned_multiply

        // no promotion of integer inputs. This is contentious as
           silent integer overflow can occur
           It may be better to convert to a float.
           the converter will then check that no
           overflow has occurred before converting back to an int
           and if not throw an exception.
           At least The control possibility is there now !
       */
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<7,1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<9,1>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK((typeid(mul::eval<int,int>()(1,1)) == typeid(int)));
       int val1 = mul::eval<int,int>()(1,1);
       int val1_chk = (1 * 1) * ((7 / 1) * (9 / 1));
       QUAN_CHECK_EQUAL(val1,val1_chk);
       QUAN_CHECK((typeid(mul::eval<float,int>()(1,1)) == typeid(float)));
       float in2 = -.1f;
       float val2 =mul::eval<float,int>()(in2,val1);
       float val2_chk = (in2 * val1) * ((7.f / 1.f) * (9.f / 1.f));
       QUAN_CHECK_EQUAL(val2,val2_chk);
   }
   void test_zero_exp_1_rational_mul()
   {
       /* Exponent of result is zero
          Single multiplier is not 1
          Single multiplier is not an integer
          Calculation is the same as dimensioned_multiply
       */
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<7,3>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<13,5>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK((typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       quan::quantity_traits::default_value_type val1 = mul::eval<int,int>()(10,7);
       quan::quantity_traits::default_value_type val1_chk = (10. * 7.) * (91. / 15.);
       QUAN_CHECK_EQUAL(val1,val1_chk);
       QUAN_CHECK((typeid(mul::eval<float,float>()(1,1)) == typeid(float)));
       QUAN_CHECK((typeid(mul::eval<float,int>()(1,1)) == typeid(float)));
       float in2 = -.1f;
       float in2a = -333.3f;
       float val2 = mul::eval<float,float>()(in2,in2a);
       float val2_chk = (in2 * in2a) * (91.f / 15.f);
       QUAN_CHECK_EQUAL(val2,val2_chk);
   }

   void test_zero_exp_2_mul()
   {
       /* Exponent of result is zero
          2 multipliers
          Calculation is the same as dimensioned_multiply
       */
        typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<11000123,1000000>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<0>,
           quan::meta::rational<11000297,1000000>
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK((typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
        QUAN_CHECK((typeid(mul::eval<int,double>()(1,1)) == typeid(double)));
       double in1 = 97865.31;
       double in2 = 12345.;
       double result = mul::eval<double,double>()(in1,in2);
       double result_chk = (in1 * in2 ) * ((static_cast<double>(11000123) / 1000000) * ( static_cast<double>(11000297)/1000000));
       QUAN_CHECK_EQUAL(result, result_chk);
   }


   void test_rt_positive_integer_exp_2mul()
   {
       // runtime evaluated positive integer exponent
       // two multipliers
       typedef quan::meta::conversion_factor<
           quan::meta::rational<7>,
           quan::meta::rational<2000001,700000 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<8 >,
           quan::meta::rational<2000001,700000 >
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       double value = mul::eval<int,double>()(1,1);
       double value_chk = (1. * 1.) * (1.e15 * ( (2000001./700000) * (2000001. / 700000)));
       QUAN_CHECK_EQUAL(value,value_chk);
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       QUAN_CHECK( (typeid(mul::eval<int,float>()(1,1)) == typeid(float)));
       QUAN_CHECK( (typeid(mul::eval<float,int>()(1,1)) == typeid(float)));
       QUAN_CHECK( (typeid(mul::eval<float,float>()(1,1)) == typeid(float)));
       QUAN_CHECK( (typeid(mul::eval<int,double>()(1,1)) == typeid(double)));
       QUAN_CHECK( (typeid(mul::eval<double,double>()(1,1)) == typeid(double)));

   // VC7.1 returns a double here !
   #if(defined _MSC_VER && _MSC_VER == 1310)
       QUAN_CHECK( (typeid(mul::eval<double,long double>()(1,1)) == typeid(double))); 
   #else 
       QUAN_CHECK( (typeid(mul::eval<double,long double>()(1,1)) == typeid(long double)));
   #endif
       QUAN_CHECK( (typeid(mul::eval<long double,double>()(1,1)) == typeid(long double))); 
       QUAN_CHECK( (typeid(mul::eval<int,long double>()(1,1)) == typeid(long double))); 
   }
   void test_ct_positive_integer_exp_2mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<2>,
           quan::meta::rational<1234569,7 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<5>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 29.807;
       double in_R = 77.894;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * (10000000. * ((1234569./7.) * (20. / 7.)));
       QUAN_CHECK_EQUAL(result,result_chk);
   }

   void test_ct_negative_integer_exp_2mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<2>,
           quan::meta::rational<45638976,1000000 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-10>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 29.807;
       double in_R = 77.894;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * (((45638976./1000000.) * (20. / 7.)) / 100000000.);
       QUAN_CHECK_EQUAL(result,result_chk);
   }
   void test_rt_negative_integer_exp_2mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<7>,
           quan::meta::rational<45638976,1000000 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-20>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 29.807;
       double in_R = 77.894;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * (((45638976./1000000.) * (20. / 7.)) / 1.e13);
       QUAN_CHECK_EQUAL(result,result_chk);
       
   }
   void test_rational_exp_2mul()
   {
      typedef quan::meta::conversion_factor<
           quan::meta::rational<7,3>,
           quan::meta::rational<45638976,1000000 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-3>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;

     /*  typedef quan::meta::binary_op<
               conversion_factor_L,
               quan::meta::times,
               conversion_factor_R
       >::type test1;
       typedef test1::exponent exp;
       std::cout << "exp = " << exp::numerator << "/" << exp::denominator <<'\n';*/
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 29.807;
       double in_R = 77.894;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * ( std::pow(10.,-2./3.) *((45638976./1000000.) * (20. / 7.))) ;
       QUAN_CHECK_EQUAL(result,result_chk);
   }

   void  test_ct_positive_integer_exp_1mul()
   {
        typedef quan::meta::conversion_factor<
           quan::meta::rational<7>,
           quan::meta::rational<457,100 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-3>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = -29.807;
       double in_R = 77.894;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * ( 10000. *(457.* 20. /700.)) ;
       QUAN_CHECK_EQUAL(result,result_chk);
   }

   void test_ct_negative_integer_exp_1mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-7>,
           quan::meta::rational<457,100 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<3>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       QUAN_CHECK( (typeid(mul::eval<int,float>()(1,1)) == typeid(float)));
       float in_L = -29.807f;
       float in_R = 77.894f;
       float result = mul::eval<float,float>()(in_L,in_R);
       float result_chk = (in_L * in_R) * ( (457.f / 35.f)/ 10000.f) ;
       QUAN_CHECK_CLOSE(result,result_chk,1e-5);
   }

   void test_rt_negative_integer_exp_1mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-7>,
           quan::meta::rational<457,100 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-3>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
    /*   typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
       std::cout << rat::numerator << "/ " << rat::denominator <<'\n';*/
       QUAN_CHECK( (typeid(mul::eval<int,float>()(1,1)) == typeid(float)));
       float in_L = -2.807f;
       float in_R = 77.894f;
       float result = mul::eval<float,float>()(in_L,in_R);
       float result_chk = (in_L * in_R) * ((457.f / 35.f) / 1.e10f) ;
       QUAN_CHECK_CLOSE(result,result_chk,1e-5);
   }

   void test_rt_positive_integer_exp_1mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<7>,
           quan::meta::rational<457,100 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<3>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       //typedef quan::meta::binary_op<
       //    conversion_factor_L::multiplier,
       //    quan::meta::times,
       //    conversion_factor_R::multiplier
       //>::type rat;
       //std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,float>()(1,1)) == typeid(float)));
       float in_L = 2.8f;
       float in_R = 7.2f;
       float result = mul::eval<float,float>()(in_L,in_R);
       float result_chk = (in_L * in_R) *( 1.e10f * (457.f / 35.f) ) ;
       QUAN_CHECK_CLOSE(result,result_chk,1e-4);   
   }

   void test_rational_exp_1mul()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<8,7>,
           quan::meta::rational<457,100 >
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<1>,
           quan::meta::rational<20,7 >
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
     //  std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,double>()(1,1)) == typeid(double)));
       double in_L = 2.8f;
       double in_R = 7.2f;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) *( pow(10., 15./7.) * (457. / 35.) ) ;
       QUAN_CHECK_EQUAL(result,result_chk);   

   }
   void test_ct_positive_integer_exp_only()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<8>,
           quan::meta::rational<1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<1>,
           quan::meta::rational<1>
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
     //  std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(int)));
       double in_L = 2.8f;
       double in_R = 7.2f;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * 1000000000.  ;
       QUAN_CHECK_EQUAL(result,result_chk);   
   }

   void test_rt_positive_integer_exp_only()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<8>,
           quan::meta::rational<1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<3>,
           quan::meta::rational<1>
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
     //  std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 2.8f;
       double in_R = 7.2f;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * 1.e11  ;
       QUAN_CHECK_EQUAL(result,result_chk);   
       
   }

   void  test_rational_exp_only()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<7,3>,
           quan::meta::rational<1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<1>,
           quan::meta::rational<1>
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
     //  std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 2.8f;
       double in_R = 7.2f;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) * std::pow(10.,10./3.)  ;
       QUAN_CHECK_EQUAL(result,result_chk);   
       
   }

   void test_ct_negative_integer_exp_only()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-7>,
           quan::meta::rational<1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<1>,
           quan::meta::rational<1>
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
     //  std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 2.8f;
       double in_R = 7.2f;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) / 1000000.  ;
       QUAN_CHECK_EQUAL(result,result_chk);    
   }

   void test_rt_negative_integer_exp_only()
   {
       typedef quan::meta::conversion_factor<
           quan::meta::rational<-14>,
           quan::meta::rational<1>
       > conversion_factor_L;
       typedef quan::meta::conversion_factor<
           quan::meta::rational<1>,
           quan::meta::rational<1>
       > conversion_factor_R;
       
       typedef quan::detail::dimensionless_multiply1<
           conversion_factor_L, conversion_factor_R
       > mul;
       typedef quan::meta::binary_op<
           conversion_factor_L::multiplier,
           quan::meta::times,
           conversion_factor_R::multiplier
       >::type rat;
     //  std::cout << rat::numerator << "/ " << rat::denominator <<'\n';
       QUAN_CHECK( (typeid(mul::eval<int,int>()(1,1)) == typeid(quan::quantity_traits::default_value_type)));
       double in_L = 2.8f;
       double in_R = 7.2f;
       double result = mul::eval<double,double>()(in_L,in_R);
       double result_chk = (in_L * in_R) / 1.e13  ;
       QUAN_CHECK_EQUAL(result,result_chk); 
   }

}//anon
