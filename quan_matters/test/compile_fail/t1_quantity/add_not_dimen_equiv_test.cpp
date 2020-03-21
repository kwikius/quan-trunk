

#if ! defined __MBED__
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
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/time.hpp>
#include <quan/acceleration.hpp>
#include <quan/velocity.hpp>

/*
    check dimensionally_invalid calcs fail
    example from documentation
*/


int main()
{
    quan::velocity::m_per_s      v(1);
    quan::acceleration::m_per_s2 a(2); 
    v + a;

}

#endif

