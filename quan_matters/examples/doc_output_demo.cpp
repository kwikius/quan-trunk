// Copyright Andrew Little 2005
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


