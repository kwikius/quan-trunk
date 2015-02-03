
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


