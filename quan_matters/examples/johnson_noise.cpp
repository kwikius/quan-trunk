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
    Calculate Johnson noise voltage for 10 kHz LP RC filter
    From Horowitz and Hill ,The Art of Electronics.
    Example of definitions of constants
*/

#include <quan/config.hpp>

#ifndef  QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/boltzmanns_constant.cpp>
#include <quan_matters/src/constant.cpp>
#else
#include <quan/constants/boltzmanns_constant.hpp>
#include <quan/constants/constant.hpp>
#endif
#include <quan/out/temperature.hpp>
#include <quan/out/resistance.hpp>
#include <quan/out/frequency.hpp>
#include <quan/out/voltage.hpp>

namespace {

   QUAN_QUANTITY_LITERAL(temperature,K)
   QUAN_QUANTITY_LITERAL(resistance,kR)
   QUAN_QUANTITY_LITERAL(frequency,kHz)
   
}

int main()
{
    // ambient temperature
    auto constexpr T = 293.0_K;

    std::cout << "At " << T ;
    // resistance
    auto constexpr R = 10_kR;
    std::cout << " a resistance of " <<  R ;
    // filter cut-off frequency
    auto constexpr f3dB  = 10_kHz;
    std::cout << " and cut_off frequency of " << f3dB;
    // resulting noise-bandwidth
    quan::frequency::kHz  B = (quan::constant::pi / 2) * f3dB;
    std::cout << " ( noise-bandwidth " << B  << ")";
    // noise-voltage
    quan::voltage::uV V = quan::pow<1,2>( 4 * T * R * B * quan::boltzmanns_constant::K) ;
    
    std::cout << " gives johnson-noise voltage of " << V <<'\n';
  
}
