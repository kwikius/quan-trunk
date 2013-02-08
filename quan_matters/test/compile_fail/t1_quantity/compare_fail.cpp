// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/force.hpp>
#include <quan/energy.hpp>

int main()
{
    quan::force::kgf f1(1);
    quan::force::N f2(2);

    quan::force::mN ep(5);
    // These should work!
    compare(f1,f2,ep);
    compare(f2,f1,ep);
    compare(f2,f1);

    quan::energy::kJ e(20.);

    //Error: couldnt find compare
  //  compare(f1,e,ep);

    //Error: couldnt find compare
    compare(f1,e);
}
