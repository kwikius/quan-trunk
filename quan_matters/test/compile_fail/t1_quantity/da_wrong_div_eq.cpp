// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/torque.hpp>
#include <quan/power.hpp>
#include <quan/time.hpp>

/*
    check dimensionally_invalid calcs fail
    example from rationale section in documentation
*/
#include <iostream>

int main()
{
    quan::torque::N_m t;
    t  /= quan::time::s(1);

    //std::cout << value <<'\n';
}

/*
    check dimensionally_invalid calcs fail
    example from rationale section in documentation
*/


