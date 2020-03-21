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

#include <quan/reciprocal_time.hpp>
#include <quan/capacitance.hpp>

int main()
{
    quan::reciprocal_time::per_s a(1);
    quan::reciprocal_time::per_ms b(2);

    // These should work!
    a < b;
    b < a;

    quan::capacitance::uF c(20.);

    //Error: couldnt find less
    a < c;
    //Error: couldnt find less
    c < a;
}

#endif

