// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>

/*
    check abs function
*/

void abs_test()
{
    quan::length::m length(1);

    QUAN_CHECK(  abs(length) == length );
    QUAN_CHECK(  abs(-length) == length);
    QUAN_CHECK(  abs(length).numeric_value() == length.numeric_value() );
    QUAN_CHECK(  abs(-length).numeric_value() == length.numeric_value() );
}




