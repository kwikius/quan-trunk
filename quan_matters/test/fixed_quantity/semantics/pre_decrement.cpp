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
#include <quan/resistance.hpp>
#include <quan/force.hpp>

/*
    test pre_decrement for t1_quantity
*/


void pre_decrement_test()
{
   quan::resistance::MR R1(4.7);
   quan::resistance::MR Rold = R1;
   QUAN_CHECK_EQUAL( Rold.numeric_value(),R1.numeric_value());

   quan::resistance::MR R2 = --R1;
   QUAN_CHECK_EQUAL(R2.numeric_value(), R1.numeric_value() );
   QUAN_CHECK_EQUAL(R1.numeric_value(),Rold.numeric_value() - 1);

   quan::force::kip F1(987.51);
   quan::force::kip Fold = F1;
   quan::force::kip F2 = --F1;
   QUAN_CHECK(F2.numeric_value() == F1.numeric_value() );
   QUAN_CHECK(F1.numeric_value() == Fold.numeric_value() - 1 );
   QUAN_CHECK(F2.numeric_value() == QUAN_FLOAT_TYPE(986.51));
}
