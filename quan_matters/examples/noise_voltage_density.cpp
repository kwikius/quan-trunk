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

#include <quan/out/temperature.hpp>
#include <quan/out/resistance.hpp>
#include <quan/out/frequency.hpp>
#include <quan/out/voltage.hpp>

#include <quan_matters/src/boltzmanns_constant.cpp>
/*
    Just demonstrates a quantity using a rational(rather than integer)dimension.
    noise voltage density here
    From The Art of Electronics Horovitz and Hill 7.11 Johnson Noise.
    Note the result for the power of 10 of 1.27 x 10-4 seems wrong 
    in one part of the chapter in my version (2nd Ed) of the book.

    Also demonstrates a simple way of creating ones own named-quantity.
    though the prefferrde method is detailed in the documentation
*/

namespace quan{

    template <typename T>
    struct noise_voltage_density_{
        typedef meta::abstract_quantity<
            meta::dimension<

               quan::meta::dim_length<2> 
               ,quan::meta::dim_time_ratio<-5,2> 
               ,quan::meta::dim_mass<1> 
               ,quan::meta::dim_current<-1> 

            >,
            noise_voltage_density_
         > abstract_quantity;

        typedef fixed_quantity<
            quan::meta::unit<
                abstract_quantity,
                typename meta::si_unit::nano
            >,
            T
        > nV_per_sqrt_hz;
    };

    struct noise_voltage_density : noise_voltage_density_<
        quantity_traits::default_value_type
    >{};

    template <typename CharType, typename T>
    std::basic_ostream<CharType>& 
    operator <<(
        std::basic_ostream<CharType> & os, 
        fixed_quantity<
            quan::meta::unit<
                typename noise_voltage_density::abstract_quantity,
                typename meta::si_unit::nano
            >,
            T
        > const & pq)
    {
        os << pq.numeric_value() << " nV.Hz-1/2";
        return os;
    }  
}//quan

#include <iostream>

int main()
{
    using quan::boltzmanns_constant;
    quan::temperature::K t(293.16);
    quan::resistance::kR r(10);
    quan::noise_voltage_density::nV_per_sqrt_hz nvd 
    = sqrt( 4 * boltzmanns_constant::K * t * r);

    std::cout << "noise voltage density  of " << r << " at " 
    << t << " = " << nvd  << '\n';
    quan::frequency ::kHz f(10);
    quan::voltage::uV v = nvd * sqrt(f);

    std::cout << "noise voltage at " << f << " = " << v << '\n';
}
