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

#include <quan/torque.hpp>
#include <quan/power.hpp>
#include <quan/time.hpp>

/*
    check dimensionally_invalid calcs fail
    example from rationale section in documentation
*/


int main()
{
    quan::torque::N_m t = quan::power::W(1) / quan::time::s(1);
}

/*
    check dimensionally_invalid calcs fail
    example from rationale section in documentation
*/

#endif
