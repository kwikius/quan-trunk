
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    capacitor discharge curve using compile_time
    physical_quantities
*/

#include <quan/capacitance.hpp>
#include <quan/resistance.hpp>
#include <quan/time.hpp>
#include <quan/out/voltage.hpp>

namespace {

   QUAN_QUANTITY_LITERAL(capacitance,uF)
   QUAN_QUANTITY_LITERAL(voltage,V)
   QUAN_QUANTITY_LITERAL(voltage,mV)
   QUAN_QUANTITY_LITERAL(voltage,uV)
   QUAN_QUANTITY_LITERAL(voltage,nV)
   QUAN_QUANTITY_LITERAL(resistance,kR)
   QUAN_QUANTITY_LITERAL(time,ms)
}

int main()
{
    using quan::voltage;

    std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
    std::cout.precision(3);

    #define let auto constexpr

    let C = 0.47_uF;
    let V0 = 5.0_V;
    let R = 4.7_kR;

    for ( auto t = 0_ms ; t <= 50_ms; ++t  ){

        auto const Vt = V0 * std::exp(-t / (R * C));

        std::cout << "at " << t << " voltage is " ;

        if     ( Vt >= 1_V )    std::cout << Vt ;
        else if( Vt >= 1_mV )   std::cout << voltage::mV{Vt};
        else if( Vt >= 1_uV )   std::cout << voltage::uV{Vt};
        else if( Vt >= 1_nV )   std::cout << voltage::nV{Vt};
        else                    std::cout << voltage::pV{Vt};
        std::cout << "\n";

    }
}
