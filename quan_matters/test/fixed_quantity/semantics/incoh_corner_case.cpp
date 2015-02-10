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

