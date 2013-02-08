
// Copyright Andrew Little 2005
//


 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    capacitor discharge curve using compile_time
    physical_quantities
*/

#include <quan/capacitance.hpp>
#include <quan/resistance.hpp>
#include <quan/time.hpp>
#include <quan/out/voltage.hpp>

int main()
{
    using quan::capacitance;
    using quan::voltage;
    using quan::resistance;
    using quan::time_; // for non default time with int value_type

    std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
    std::cout.precision(3);

    capacitance::uF   const C{0.47}; // capacitor
    voltage::V        const V0{5};   // starting voltage across capacitor
    resistance::kR    const R{4.7};  // resistance between terminals

    // one possible useage of integer value_type
    for ( auto t = time_<int>::ms{0} ; t <= time_<int>::ms{50}; ++t  ){

        auto const Vt = V0 * std::exp(-t / (R * C));

        std::cout << "at " << t << " voltage is " ;
        //format
        if     (Vt >= voltage::V{1})      std::cout << Vt ;
        else if(Vt >= voltage::mV{1})     std::cout << voltage::mV{Vt};
        else if(Vt >= voltage::uV{1})     std::cout << voltage::uV{Vt};
        else if(Vt >= voltage::nV{1})     std::cout << voltage::nV{Vt};
        else                              std::cout << voltage::pV{Vt};
        std::cout << "\n";

    }
}
