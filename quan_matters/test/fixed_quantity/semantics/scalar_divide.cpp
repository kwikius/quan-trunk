// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/mass.hpp>
#include <quan/force.hpp>
#include <quan/time.hpp>
#include <quan/length.hpp>
#include <quan/reciprocal_time.hpp>
#include <quan/resistance.hpp>
#include <quan/conductance.hpp>
#include <type_traits>
/*
    division by a scalar
*/

namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(scalar_divide_test1)
    QUAN_TEST_FUN(reciprocal_scalar_divide_test)

#undef QUAN_TEST_FUN
}

void scalar_divide_test()
{
#define QUAN_TEST_FUN(fun) fun();

    QUAN_TEST_FUN(scalar_divide_test1)
    QUAN_TEST_FUN(reciprocal_scalar_divide_test)

#undef QUAN_TEST_FUN
}

namespace {
   void scalar_divide_test1()
   {
       quan::mass::kg M1(1.1);
       quan::mass::kg M2 = M1 / 25;
       // not sure if we can guarantee this?
       // may need to use QUAN_CHECK_CLOSE?
       QUAN_CHECK_EQUAL(M2.numeric_value(),
           (QUAN_FLOAT_TYPE(1.1) / QUAN_FLOAT_TYPE(25))
       );

       // similar comment
       quan::force::kgf F1(100);
       quan::force::kgf F2  = F1 / 0.3;
       QUAN_CHECK_EQUAL(F2.numeric_value(),
           (QUAN_FLOAT_TYPE(100) / QUAN_FLOAT_TYPE(0.3))
       );
   }

   //value_type / pq acts differently when pq is incoherent
   void reciprocal_scalar_divide_test()
   {
       quan::conductance::mS  S1(100.);
       QUAN_FLOAT_TYPE  v = QUAN_FLOAT_TYPE(2.);
       quan::resistance::kR  R1 = v / S1; 

       //for simplicity initialize incoherent type from coherent type
       quan::length::km L1x (250);
       quan::length::mi L1 = L1x;

       // check conversion of incoherent to anonymous coherent type
       // in division of value_type by pq
       typedef quan::meta::binary_op<
          QUAN_FLOAT_TYPE,
           quan::meta::divides,
           quan::length::mi
       >::type result_type;
       // anonymous check
       QUAN_CHECK(
           (std::is_same<
               result_type::unit::abstract_quantity::named_quantity_traits,
               quan::meta::anonymous_quantity_traits
           >::value == true)
       );
       typedef quan::meta::get_multiplier<
           quan::meta::get_conversion_factor<
               result_type::unit
           >::type
       >::type mux;
       //typedef result_type::unit::multiplier mux;
       QUAN_CHECK( mux::numerator == 1 );
       QUAN_CHECK( mux::denominator == 1 );
       result_type result = v / L1;
       QUAN_CHECK_CLOSE(result.numeric_value(), v/(QUAN_FLOAT_TYPE(250.)), 1e-9);    
   }
}

