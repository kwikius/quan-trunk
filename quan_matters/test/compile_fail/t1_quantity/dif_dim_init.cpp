// Copyright Andrew Little 2006
//
 
 
 
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
