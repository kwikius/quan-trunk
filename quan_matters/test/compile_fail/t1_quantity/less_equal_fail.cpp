// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/reciprocal_time.hpp>
#include <quan/capacitance.hpp>

int main()
{
    quan::reciprocal_time::per_s a(1);
    quan::reciprocal_time::per_ms b(2);

    // These should work!
    a <= b;
    b <= a;

    quan::capacitance::uF c(20.);

    //Error: couldnt find lessequal
    a <= c;
    //Error: couldnt find lessequal
  //  c <= a;
}
