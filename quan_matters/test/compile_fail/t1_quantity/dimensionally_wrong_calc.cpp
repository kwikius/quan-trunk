
// Copyright Andrew Little 2005
//
 
 
 
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
