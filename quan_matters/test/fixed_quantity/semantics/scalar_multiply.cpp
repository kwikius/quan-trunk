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

#include <quan_matters/test/simple_test.hpp>
#include <quan/mass.hpp>
#include <quan/force.hpp>
/*
    multiplication by a scalar
*/


void scalar_multiply_test()
{
    quan::mass::kg M1(1.1);
    quan::mass::kg M2 = M1 * 25;
    // not sure if we can guarantee this?
    // may need to use QUAN_CHECK_CLOSE?
    QUAN_CHECK_EQUAL(M2.numeric_value(),
        (QUAN_FLOAT_TYPE(1.1) * QUAN_FLOAT_TYPE(25))
    );
    //check other orientation
    quan::mass::kg M2a = 25 * M1;
    // not sure if we can guarantee this?
    // may need to use QUAN_CHECK_CLOSE?
    QUAN_CHECK_EQUAL(M2a.numeric_value(),
        (QUAN_FLOAT_TYPE(25) * QUAN_FLOAT_TYPE(1.1) )
    );

    // similar comment
    quan::force::kgf F1(100);
    quan::force::kgf F2  = F1 * 0.3;
    QUAN_CHECK_EQUAL(F2.numeric_value(),
        (QUAN_FLOAT_TYPE(100) * QUAN_FLOAT_TYPE(0.3))
    );
     //check other orientation
    quan::force::kgf F2a  = 0.3 * F1 ;
    QUAN_CHECK_EQUAL(F2.numeric_value(),
        (QUAN_FLOAT_TYPE(0.3) * QUAN_FLOAT_TYPE(100))
    );
    
}
