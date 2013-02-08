// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/resistance.hpp>
#include <quan/voltage.hpp>

/*
    should fail to compile
*/

int main()
{
    quan::voltage::uV     v(1);
    v -= 1.;
}
