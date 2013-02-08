// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>

/*
    test /= numeric for fixed_quantity
*/

void divide_assignment_test()
{
    quan::length::m L1(3.);
    L1 /=2;
    QUAN_CHECK_EQUAL(L1.numeric_value() , QUAN_FLOAT_TYPE(3.) / 2);

    quan::length::mm L2(-2310);
    L2 /= 2343;
    QUAN_CHECK_EQUAL(L2.numeric_value() ,QUAN_FLOAT_TYPE(-2310) / 2343);

    quan::length::in L3(-12);
    L3 /= 0.1;
    QUAN_CHECK_EQUAL(L3.numeric_value() ,QUAN_FLOAT_TYPE(-12) / 0.1 );

    quan::length::in L4(0.314142);
    L4 /= 3.14142;
    QUAN_CHECK_EQUAL(L4.numeric_value() ,QUAN_FLOAT_TYPE(0.314142) / 3.14142);

}


