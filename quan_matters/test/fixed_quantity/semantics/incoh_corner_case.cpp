// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>

/*
    Check that incoherent unit which 
    has a unitary multiplier is differentiated from a coherent unit
*/

#include <quan/out/pressure.hpp>
#include <quan/fixed_quantity/io/output.hpp>

void incoh_corner_case_test()
{
    quan::pressure::mbar p1;
    quan::pressure::hPa p2;
    QUAN_CHECK(units_str(p1) == "mbar");
    QUAN_CHECK(units_str(p2) == "hPa");
}

