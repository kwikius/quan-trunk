// Copyright Andrew Little 2005
//
 
 
 
//
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

int main()
{
    // ambient temperature
    quan::temperature::K    T(293);
    std::cout << "At " << T ;
    // resistance
    quan::resistance_<int>::kR    R(10);
    std::cout << " a resistance of " <<  R ;
    // filter cut-off frequency
    quan::frequency_<int>::kHz    f3db(10);
    std::cout << " and cut_off frequency of " << f3db;
    // resulting noise-bandwidth
    quan::frequency::kHz          B
    = (quan::constant::pi / 2) * f3db;
    std::cout << " ( noise-bandwidth " << B  << ")";
    // noise-voltage
    quan::voltage::uV             V 
    = quan::pow<1,2>( 4 * T * R * B * quan::boltzmanns_constant::K) ;
    
    std::cout << " gives johnson-noise voltage of " << V <<'\n';
  
}
