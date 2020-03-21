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

//
 
 #if ! defined __MBED__
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Try to initialise a t1_quantity with 
    another of same unit but not dimensionally_equivalent
*/
/*
    Should fail to compile
*/

#include <quan/resistance.hpp>
#include <quan/capacitance.hpp>

using namespace quan;

int main()
{
    resistance::R  R = capacitance::F(1.);
}

#endif

