
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

#include <quan/time.hpp>
#include <quan/acceleration.hpp>
#include <quan/velocity.hpp>

/*
    check dimensionally_invalid calcs fail
    example from rationale section in documentation
*/

int main()
{
    quan::velocity::m_per_s      initial_velocity(1);
    quan::velocity::m_per_s      final_velocity(2);
    quan::time::s                time(0.5);
    quan::acceleration::m_per_s2 acceleration 
    = final_velocity - initial_velocity / time; 
    
}

#endif

