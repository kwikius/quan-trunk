// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/resistance.hpp>
#include <quan/voltage.hpp>

/*
    check dimensionally_invalid calcs fail
    example from documentation
*/

int main()
{
    quan::voltage::uV     v(1);
    quan::resistance::kR  r(2); 
    v -= r;
}
