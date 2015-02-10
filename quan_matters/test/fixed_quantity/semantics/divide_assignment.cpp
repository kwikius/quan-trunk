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


