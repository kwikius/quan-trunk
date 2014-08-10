
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
*/

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
