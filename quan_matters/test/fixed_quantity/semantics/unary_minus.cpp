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
#include <quan/resistance.hpp>
#include <quan/magnetic_permeability.hpp>

/*
    test unary_minus for t1_quantity
*/


void unary_minus_test()
{
   quan::resistance::MR R1(4.7);
   quan::resistance::MR R2 = -R1;
   QUAN_CHECK_EQUAL(R1.numeric_value(), -R2.numeric_value());
   quan::magnetic_permeability_<int>::mH_per_m mp1(987.51);
   quan::magnetic_permeability::mH_per_m mp2 = -mp1;
   QUAN_CHECK(mp1.numeric_value() == -mp2.numeric_value());
   QUAN_CHECK(mp2.numeric_value() == -988);
}
