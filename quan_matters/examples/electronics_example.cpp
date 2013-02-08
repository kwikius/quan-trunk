// Copyright Andrew Little 2005
//


 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
     some basic electronics calcs
*/

#include <quan/out/voltage.hpp>
#include <quan/out/resistance.hpp>
#include <quan/out/current.hpp>
#include <quan/out/time.hpp>
#include <quan/out/power.hpp>
#include <quan/out/energy.hpp>

int main()
{
    using quan::voltage;
    using quan::current;
    using quan::resistance;
    using quan::time;
    using quan::power;
    using quan::energy;
   // using quan::pow;

    voltage::V        v{5.0};
    resistance::kR    r{1};
    current::mA       i = v/r;
    time::s           t{1.0};
    power::mW         w = quan::pow<2>(v)/r;
    energy::mJ        e = w * t;
    std::cout
    << "A current of " << i
    << "\nthrough a voltage of " << v
    << "\nrequires a resistance of " << r
    << "\nand produces "  << w << " of heat\n";
    std::cout
    << "total energy used in " << t
    << " is " <<  e  << '\n';
}
