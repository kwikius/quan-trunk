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

/*
    Demo of output of anonymous_quantity, 
    and two dimensionally_equivalent 
    but distinct quantities.
*/

#include <quan/out/force.hpp>
#include <quan/out/length.hpp>
#include <quan/out/torque.hpp>
#include <quan/out/energy.hpp>

int main()
{
    quan::force::kN    force(1);
    quan::length::mm  distance(1);
    
    // temporary result of f * d 
    // is an anonymous_quantity
    // so output is that for anonymous quantity
    std::cout << force * distance << '\n';

    //However can be assigned to energy
    quan::energy::J energy = force * distance;
    // output is particular to energy
    std::cout << energy << '\n';

    // or torque
    quan::torque::N_m torque = force * distance;
    // output is particular to torque
    std::cout << torque << '\n';
}


