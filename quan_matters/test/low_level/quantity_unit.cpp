
// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan_matters/test/low_level/aux_test.hpp>
#include <quan/meta/conversion_factor.hpp>
#include <quan/meta/si_units.hpp>
#include <type_traits>
#include <quan/meta/eq.hpp>
// same si
// different si
// same inco
// different inco
// si inco
// same conversion_factor but diff tag

#if 1
void test_quantity_unit();
int errors =0;
int main()
{
   test_quantity_unit();
   EPILOGUE
}
#endif

void test_quantity_unit()
{
    using quan::meta::conversion_factor;
    using quan::meta::si_unit;
    using quan::meta::binary_op;
    using quan::meta::plus;
    using quan::meta::minus;
    using quan::meta::times;
    using quan::meta::divides;
    using quan::meta::rational;

//same si conversion_factor
    typedef conversion_factor<> default_type;
    CHECK_SI_QUANTITY_UNIT(default_type, 0);

    typedef binary_op<
        si_unit::micro,
        plus,
        si_unit::micro 
    >::type plus_unit0;
    CHECK_SI_QUANTITY_UNIT(plus_unit0,-6);
    QUAN_CHECK( (std::is_same<
          plus_unit0,
          si_unit::micro
    >::value));

    typedef binary_op<
        si_unit::kilo,
        minus,
        si_unit::kilo 
    >::type minus_unit0;
    QUAN_CHECK( (std::is_same<
          minus_unit0,
          si_unit::kilo
    >::value));
    CHECK_SI_QUANTITY_UNIT(minus_unit0,3);
    typedef binary_op<
            si_unit::nano,
            times,
            si_unit::nano 
    >::type times_unit0;
    CHECK_SI_QUANTITY_UNIT(times_unit0,-18);
    typedef binary_op<
            si_unit::mega,
            divides,
            si_unit::mega 
    >::type divides_unit0;
    CHECK_SI_QUANTITY_UNIT(divides_unit0,0);
////////// different si conversion_factor
    typedef binary_op<
            si_unit::nano,
            plus,
            si_unit::milli 
    >::type plus_unit1;
    CHECK_SI_QUANTITY_UNIT(plus_unit1,-9);
    QUAN_CHECK( (std::is_same<
          plus_unit1,
          si_unit::nano
    >::value));
    typedef binary_op<
            si_unit::nano,
            minus,
            si_unit::milli 
    >::type minus_unit1;
    CHECK_SI_QUANTITY_UNIT(minus_unit1,-9);
    QUAN_CHECK( (std::is_same<
          minus_unit1,
          si_unit::nano
    >::value));
    typedef binary_op<
            si_unit::nano,
            times,
            si_unit::milli 
    >::type times_unit1;
    CHECK_SI_QUANTITY_UNIT(times_unit1,-12);
    QUAN_CHECK( (std::is_same<
          times_unit1,
          si_unit::pico
    >::value));
    typedef binary_op<
            si_unit::nano,
            divides,
            si_unit::milli 
    >::type divides_unit1;
    CHECK_SI_QUANTITY_UNIT(divides_unit1,-6);
    QUAN_CHECK( (std::is_same<
          divides_unit1,
          si_unit::micro
    >::value));

// same non si conversion_factor
    typedef conversion_factor<
            rational<3>,
            rational<1020000,1000000>,
           quan::meta::int32<1>
    > non_si_type0;
    typedef binary_op<
        non_si_type0,
        plus,
        non_si_type0
    >::type plus_non_si_type0;
    QUAN_CHECK( (std::is_same<
          plus_non_si_type0,
          non_si_type0::type
    >::value)); 

 //   std::cout << "non_si_type " <<typeid(non_si_type0).name() <<'\n';
  //  std::cout << "plus_non_si_type " <<typeid(plus_non_si_type0).name() <<'\n';
    
    typedef binary_op<
        non_si_type0,
        minus,
        non_si_type0
    >::type minus_non_si_type0;
    QUAN_CHECK( (std::is_same<
          non_si_type0::type,
          minus_non_si_type0
    >::value));
    typedef binary_op<
        non_si_type0,
        times,
        non_si_type0
    >::type times_non_si_type0;
    CHECK_SI_QUANTITY_UNIT(times_non_si_type0,6);
    typedef binary_op<
        non_si_type0,
        divides,
        non_si_type0
    >::type divides_non_si_type0;
    CHECK_SI_QUANTITY_UNIT(divides_non_si_type0,0);
// different non si
    typedef conversion_factor<
            rational<2>,
            rational<1020000,1000000>,
           quan::meta::int32<1>
    > non_si_type1;
////////
    typedef binary_op< // finest grained
        non_si_type0,
        plus,
        non_si_type1
    >::type plus_non_si_type1;
    QUAN_CHECK( (std::is_same<
          plus_non_si_type1,
          non_si_type1::type
    >::value)); 
    typedef binary_op<
        non_si_type0,
        minus,
        non_si_type1
    >::type minus_non_si_type1;
    QUAN_CHECK( (std::is_same<
          minus_non_si_type1,
          non_si_type1::type
    >::value)); 
 
    typedef binary_op<
        non_si_type1,
        times,
        non_si_type0
    >::type times_non_si_type1;
    CHECK_SI_QUANTITY_UNIT(times_non_si_type1,5);
    typedef binary_op<
        non_si_type0,
        divides,
        non_si_type1
    >::type divides_non_si_type1;
    CHECK_SI_QUANTITY_UNIT(divides_non_si_type1,1);
// special case same conversion_factor different id
   typedef conversion_factor<
            rational<2>,
            rational<1020000,1000000>,
           quan::meta::int32<1>
    > non_si_type2;

    typedef binary_op< 
        non_si_type1,
        plus,
        non_si_type2
    >::type plus_non_si_type2;
    QUAN_CHECK( (std::is_same<
          plus_non_si_type2,
          non_si_type1::type
    >::value)); 
   /* std::cout << "non_si_type1 " <<typeid(non_si_type1::type).name() <<'\n';
    std::cout << "plus_non_si_type2 " <<typeid(plus_non_si_type2::type).name() <<'\n';*/
    typedef binary_op< 
        non_si_type2,
        plus,
        non_si_type1
    >::type plus_non_si_type3;
    QUAN_CHECK( (std::is_same<
          plus_non_si_type3,
          non_si_type2::type
    >::value)); 
    // std::cout << "non_si_type2 " <<typeid(non_si_type2::type).name() <<'\n';
    // std::cout << "plus_non_si_type3 " <<typeid(plus_non_si_type3).name() <<'\n';
    typedef binary_op< 
        non_si_type1,
        minus,
        non_si_type2
    >::type minus_non_si_type2;
    QUAN_CHECK( (std::is_same<
          minus_non_si_type2,
          non_si_type1::type
    >::value)); 

    typedef binary_op< 
        non_si_type2,
        minus,
        non_si_type1
    >::type minus_non_si_type3;
    QUAN_CHECK( (std::is_same<
          minus_non_si_type3,
          non_si_type2::type
    >::value)); 

//si v non si
    typedef binary_op<
            si_unit::milli,
            plus,
            non_si_type0
    >::type plus_si_non_si0;
    CHECK_SI_QUANTITY_UNIT(plus_si_non_si0,-3);
    typedef binary_op<
            si_unit::milli,
            minus,
            non_si_type0
    >::type minus_si_non_si0;
    CHECK_SI_QUANTITY_UNIT(minus_si_non_si0,-3);
    typedef binary_op<
            si_unit::milli,
            times,
            non_si_type0
    >::type times_si_non_si0;
    CHECK_SI_QUANTITY_UNIT(times_si_non_si0,0);

    typedef binary_op<
            si_unit::milli,
            divides,
            non_si_type0
    >::type divides_si_non_si0;
    CHECK_SI_QUANTITY_UNIT(divides_si_non_si0,-6);
     
}
