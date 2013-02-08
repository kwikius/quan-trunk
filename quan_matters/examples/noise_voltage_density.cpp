// Copyright Andrew Little 2005
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
                meta::rational<2>,
                meta::rational<-5,2>,
                meta::rational<1>,
                meta::rational<0>,
                meta::rational<-1>,
                meta::rational<0>,
                meta::rational<0>
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
