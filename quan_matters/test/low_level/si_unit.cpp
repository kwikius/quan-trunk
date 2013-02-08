
// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    tset static si_unit functionality
*/

#include <quan_matters/test/test.hpp>
#include <quan_matters/test/low_level/aux_test.hpp>

using quan::meta::conversion_factor;
using quan::meta::si_unit;

// add binary_operations stuff
void test_si_unit()
{
    CHECK_SI_QUANTITY_UNIT(si_unit::yotta,24);
    CHECK_SI_QUANTITY_UNIT(si_unit::zetta,21);
    CHECK_SI_QUANTITY_UNIT(si_unit::exa,18);
    CHECK_SI_QUANTITY_UNIT(si_unit::peta,15);
    CHECK_SI_QUANTITY_UNIT(si_unit::tera,12);
    CHECK_SI_QUANTITY_UNIT(si_unit::giga,9);
    CHECK_SI_QUANTITY_UNIT(si_unit::mega,6);
    CHECK_SI_QUANTITY_UNIT(si_unit::kilo,3);
    CHECK_SI_QUANTITY_UNIT(si_unit::hecto,2);
    CHECK_SI_QUANTITY_UNIT(si_unit::deka,1);
    CHECK_SI_QUANTITY_UNIT(si_unit::none,0);
    CHECK_SI_QUANTITY_UNIT(si_unit::deci,-1);
    CHECK_SI_QUANTITY_UNIT(si_unit::centi,-2);
    CHECK_SI_QUANTITY_UNIT(si_unit::milli,-3);
    CHECK_SI_QUANTITY_UNIT(si_unit::micro,-6);
    CHECK_SI_QUANTITY_UNIT(si_unit::nano,-9);
    CHECK_SI_QUANTITY_UNIT(si_unit::pico,-12);
    CHECK_SI_QUANTITY_UNIT(si_unit::femto,-15);
    CHECK_SI_QUANTITY_UNIT(si_unit::atto,-18);
    CHECK_SI_QUANTITY_UNIT(si_unit::zepto,-21);
    CHECK_SI_QUANTITY_UNIT(si_unit::yocto,-24);
}
void units_semantics_check()
{
// +,-,*,/ todo
}

#if 1

int errors = 0;

int main()
{
   test_si_unit();
   EPILOGUE
}
#endif


