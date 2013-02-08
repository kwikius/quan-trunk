// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/simple_test.hpp>
#include <quan/power.hpp>
#include <quan/current.hpp>
#include <quan/voltage.hpp>
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/force.hpp>
#include <quan/energy.hpp>

/*
    dimensionful multiply
*/

namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(coh_coh_multiply_test)
    QUAN_TEST_FUN(coh_incoh_multiply_test)
    QUAN_TEST_FUN(incoh_coh_multiply_test)
    QUAN_TEST_FUN(incoh_incoh_multiply_test)

#undef QUAN_TEST_FUN
}

void multiply_test()
{
#define QUAN_TEST_FUN(fun) fun();

    QUAN_TEST_FUN(coh_coh_multiply_test)
    QUAN_TEST_FUN(coh_incoh_multiply_test)
    QUAN_TEST_FUN(incoh_coh_multiply_test)
    QUAN_TEST_FUN(incoh_incoh_multiply_test)

#undef QUAN_TEST_FUN
}


//helper
namespace{

    template <typename PQA,typename PQB>
    struct xtimes{
        typedef typename quan::meta::binary_op<
            PQA,quan::meta::times,PQB
        >::type type;
    };

    template <typename Unit>
    struct get_cf_mux_n : quan::meta::numerator<
        typename quan::meta::get_multiplier<
            typename quan::meta::get_conversion_factor<
                    Unit
            >::type
        >::type
    >{};
    template <typename Unit>
    struct get_cf_mux_d : quan::meta::denominator<
        typename quan::meta::get_multiplier<
            typename quan::meta::get_conversion_factor<
                    Unit
            >::type
        >::type
    >{};

    template <typename Unit>
    struct get_cf_exp_n : quan::meta::numerator<
        typename quan::meta::get_exponent<
            typename quan::meta::get_conversion_factor<
                    Unit
            >::type
        >::type
    >{};
    template <typename Unit>
    struct get_cf_exp_d : quan::meta::denominator<
        typename quan::meta::get_exponent<
            typename quan::meta::get_conversion_factor<
                    Unit
            >::type
        >::type
    >{};


   // coherent * coherent
   void coh_coh_multiply_test()
   {
       quan::current::A  i(10);
       quan::voltage::V v(240);
       quan::power::W p = v * i;
       QUAN_CHECK_EQUAL(p.numeric_value(),
           (QUAN_FLOAT_TYPE(240) * QUAN_FLOAT_TYPE(10)));
    
       quan::current::mA i1(10);
       quan::voltage::mV v1(240);
       quan::power::uW p1 = v1 * i1;
       QUAN_CHECK_EQUAL(p.numeric_value(),
           (QUAN_FLOAT_TYPE(240) * QUAN_FLOAT_TYPE(10)));
      
   }
   // coherent * incoherent
   void coh_incoh_multiply_test()
   {
       quan::time::ms T1(99.);
       // for simpler mental calc start from coherent type
       quan::length::dm L1x(100.); 
       quan::length::ft L1 = L1x; 
       typedef xtimes<
           quan::time::ms,quan::length::ft
       >::type result_type;
       result_type R1 = T1 * L1;

       int mult = get_cf_mux_n<result_type::unit>::value;
       QUAN_CHECK(mult == 1);
       int exp_nume = get_cf_exp_n<result_type::unit>::value;
       QUAN_CHECK(exp_nume == -4);
       int exp_denom = get_cf_exp_d<result_type::unit>::value;
       QUAN_CHECK(exp_denom == 1);

       QUAN_CHECK_CLOSE(R1.numeric_value(), 
           QUAN_FLOAT_TYPE(100. * 99), 
           QUAN_FLOAT_TYPE(1e-12)
       );
   }

   // incoherent * coherent
   void incoh_coh_multiply_test()
   {
       quan::time::ms T1(99.);
       // for simpler mental calc start from coherent type
       quan::length::dm L1x(100.); 
       quan::length::ft L1 = L1x; 
       typedef xtimes<
           quan::length::ft,quan::time::ms
       >::type result_type;
       result_type R1 = L1 * T1 ;

       int mult = get_cf_mux_n<result_type::unit>::value;
       QUAN_CHECK(mult == 1);
       int exp_nume = get_cf_exp_n<result_type::unit>::value;
       QUAN_CHECK(exp_nume == -4);
       int exp_denom = get_cf_exp_d<result_type::unit>::value;
       QUAN_CHECK(exp_denom == 1);

       QUAN_CHECK_CLOSE(R1.numeric_value(), 
           QUAN_FLOAT_TYPE( 99. )  * QUAN_FLOAT_TYPE(100. ), 
           QUAN_FLOAT_TYPE(1e-12)
       );
   }

   void incoh_incoh_multiply_test()
   {
       // for simpler mental calc start from coherent types
       quan::force::N F1x(99.);
       quan::length::dm L1x(100.); 
       // and convert to incoherent types
       quan::force::kgf F1 = F1x;
       quan::length::ft L1 = L1x; 
       typedef xtimes<
           quan::force::kgf,quan::length::ft
       >::type result_type;
       int mult = get_cf_mux_n<result_type::unit>::value;
       QUAN_CHECK(mult == 1);
       int exp_nume = get_cf_exp_n<result_type::unit>::value;
       QUAN_CHECK(exp_nume == -1);
       int exp_denom = get_cf_exp_d<result_type::unit>::value;
       QUAN_CHECK(exp_denom == 1);

       result_type  R1 = F1 * L1;
       QUAN_CHECK_CLOSE(R1.numeric_value(), 
           QUAN_FLOAT_TYPE( 99. ) * QUAN_FLOAT_TYPE(100. ), 
           QUAN_FLOAT_TYPE(1e-12)
       );
   }

}

