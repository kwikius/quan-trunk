
// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    test abstract_quantity
*/
// neded for is_named_quantity

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>
#include <quan_matters/test/low_level/aux_test.hpp>
#include <quan/meta/abstract_quantity.hpp>
#include <quan/meta/dimension.hpp>
#include <quan/meta/unit.hpp>
#include <quan/meta/rational.hpp>

#if 1

void test_abstract_quantity();
int errors=0;
int main()
{
   test_abstract_quantity();
   EPILOGUE
}
#endif

namespace quan{
 
    namespace aux{

        typedef quan::meta::rational<0> zero;
        typedef quan::meta::rational<1,4> one_quarter;
        typedef quan::meta::rational<1,3> one_third;
        typedef quan::meta::rational<1,2> one_half;
        typedef quan::meta::rational<2,3> two_thirds;
        typedef quan::meta::rational<3,4> three_quarters;
        typedef quan::meta::rational<1>  one;      
    }
   
    typedef quan::meta::abstract_quantity <
            quan::meta::dimension<
                aux::one_quarter,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::three_quarters
            >,
            quan::meta::int32<1>
    > type;

    typedef ::quan::meta::abstract_quantity <
            quan::meta::dimension< 
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero
            >,
            quan::meta::int32<0>
    > dimless_type;
     typedef quan::meta::abstract_quantity <
           quan::meta::dimension<
                aux::one,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero
            >,
            quan::meta::int32<1>
    > length_type0;
    typedef ::quan::meta::abstract_quantity <
           quan::meta::dimension<
                aux::one,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero,
                aux::zero
            >,
            quan::meta::int32<1>
    > length_type1;
}

void test_abstract_quantity()
{
    using quan::meta::binary_op;
    using quan::meta::plus;
    using quan::meta::minus;
    using quan::meta::times;

    typedef binary_op<
        quan::type,
        plus,
        quan::type
    >::type plus_type;
    QUAN_CHECK( (std::is_same<
        quan::meta::get_quantity_system<
            quan::length_type1
        >::type,
        quan::meta::si_unit_system
    >::value == true));
    QUAN_CHECK( (quan::meta::is_named_quantity<
        quan::length_type1
    >::value == true));

    QUAN_CHECK( (quan::meta::is_same_quantity<
        quan::type,plus_type
    >::value == true));
    
    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::type,plus_type
    >::value));
    QUAN_CHECK((quan::meta::is_dimensionless<
        quan::type
    >::value == false));
    QUAN_CHECK((quan::meta::is_dimensionless<
        quan::meta::dimension<
            quan::aux::zero,
            quan::aux::zero,
            quan::aux::zero,
            quan::aux::zero,
            quan::aux::zero,
            quan::aux::zero,
            quan::aux::zero
        >
    >::value == true));
    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::type::dimension,
        plus_type::dimension
    >::value));
    typedef binary_op<
        quan::length_type1,
        plus,
        quan::length_type1
    >::type plus_type_l;

    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::length_type1,quan::length_type0
    >::value));
    typedef binary_op<
        quan::type,
        minus,
        quan::type
    >::type minus_type;
    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::type,minus_type
    >::value));
    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::type::dimension,minus_type::dimension
    >::value));
    QUAN_CHECK((quan::meta::is_dimensionless<
        minus_type
    >::value == false) );
    QUAN_CHECK( (quan::meta::is_dimensionless<
        minus_type::dimension
    >::value ==false));
    
    typedef binary_op<
        quan::type,
        times,
        quan::type
    >::type multiplies_type;
    QUAN_CHECK((
        quan::meta::is_named_quantity<multiplies_type>::value == false
    ));
    QUAN_CHECK( (quan::meta::is_same_quantity<
        quan::type,multiplies_type
    >::value == false));
    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::type,multiplies_type
    >::value == false));
    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::type::dimension,multiplies_type::dimension
    >::value == false));
    QUAN_CHECK((quan::meta::is_dimensionless<
        multiplies_type
    >::value == false) );
    QUAN_CHECK( (quan::meta::is_dimensionless<
        multiplies_type::dimension
    >::value ==false));
    
    typedef multiplies_type::dimension::d1 mux1;
    CHECK_RAT( mux1,1,2);
   
    typedef quan::meta::binary_op<
        quan::type,
        quan::meta::divides,
        quan::type
    >::type divides_type;
    QUAN_CHECK(quan::meta::is_dimensionless<divides_type>::value == true );
    QUAN_CHECK(quan::meta::is_dimensionless<divides_type::dimension>::value == true);
  
    
    typedef quan::meta::binary_op<
            quan::type,
            quan::meta::pow,
            quan::meta::rational<3>  
    >::type pow_type;

    typedef pow_type::dimension::d1 pow_t1;
    CHECK_RAT( pow_t1,3,4);
    typedef pow_type::dimension::d2 pow_t2;
    CHECK_RAT( pow_t2,0,1);
    typedef pow_type::dimension::d3 pow_t3;
    CHECK_RAT( pow_t3,0,1);
    typedef pow_type::dimension::d4 pow_t4;
    CHECK_RAT( pow_t4,0,1);
    typedef pow_type::dimension::d5 pow_t5;
    CHECK_RAT( pow_t5,0,1);
    typedef pow_type::dimension::d6 pow_t6;
    CHECK_RAT( pow_t6,0,1);
    typedef pow_type::dimension::d7 pow_t7;
    CHECK_RAT( pow_t7,9,4);

    QUAN_CHECK((quan::meta::dimensionally_equivalent<
        quan::meta::abstract_quantity <
            quan::meta::dimension< 
                quan::aux::one,
                quan::aux::zero,
                quan::aux::zero,
                quan::aux::zero,
                quan::aux::zero,
                quan::aux::zero,
                quan::meta::rational<1,2>
            >,
            quan::meta::int32<1>
        >,
         quan::meta::abstract_quantity <
            quan::meta::dimension< 
            quan::meta::rational<1>,
                quan::aux::zero,
                quan::aux::zero,
                quan::aux::zero,
                quan::aux::zero,
                quan::aux::zero,
                quan::meta::rational<1,2>
            >,
            quan::meta::int32<0>
        >
    >::value ));
 
    QUAN_CHECK( ( quan::meta::is_dimensionless<
            quan::dimless_type
    >::value ) == true);
    QUAN_CHECK( (quan::meta::is_dimensionless<
            quan::type
    >::value ) == false );
   
  }

