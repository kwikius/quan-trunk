
// Copyright Andrew Little 2005
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
    v - a;

}
