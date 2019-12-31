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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

// header for si lengths etc with stream output
#include <quan/out/length.hpp>
#include <quan/out/area.hpp>

// Create a custom conversion factor.
// First rational is the exponent.
// Second is the multiplier,
// so the scaling factor to (e.g) meters
// is 10^ exponent * multiplier.
// Here we create a half a meter type
typedef quan::meta::conversion_factor<
    quan::meta::rational<-1>, // base 10 exponent
    quan::meta::rational<5>  // multiplier
> half_si_unit;

// Now create a fixed_quantity
// of required dimension
// with the half a meter conversion factor
typedef quan::fixed_quantity<
    quan::meta::unit<
      quan::meta::components::of_length::abstract_quantity,
      half_si_unit 
    >,
    double
> half_a_meter;

// half_a_meter is a non SI unit
// so requires its own overload
// if stream output is required...
namespace quan{namespace meta{

    inline std::ostream& operator <<(
        std::ostream & os,
        unit<
            components::of_length
                ::abstract_quantity,
            half_si_unit
        >
    )
    {
        return os << "half meter";
    }

}}//quan::meta

namespace {
   // add a UDL
   constexpr inline half_a_meter operator""_half_a_meter( long double v) \
   { 
      return half_a_meter{static_cast<double>(v)}; \
   } 

}

namespace {
   // standard UDL for length m
   QUAN_QUANTITY_REAL_LITERAL(length,m)
}

// now use custom length type ...
int main()
{   
    // test odd length functionality 
    // create from UDL...
    auto constexpr odd_length1 = 1.0_half_a_meter;
    // output...
    std::cout << "odd length1 = " << odd_length1 <<'\n';

    //-----------------------------
    // test compat
    // create a variable of
    // a Quan predefined length type
    // for comparison
    quan::length::m constexpr si_length = 10.0_m;

    // create a variable of
    // user defined half a meter length type inited by si length
    half_a_meter odd_length = si_length;

    // and use..
    std::cout << "SI length of: " << si_length 
    << " = " << odd_length << ".\n";

    std::cout << "Ratio of SI length to odd length = "
    << si_length / odd_length << ".\n";

    // do some calcs...
    quan::area::m2 area = quan::pow<2>(odd_length);

    std::cout << "Area of a square of side " << odd_length
    << " = " << area << ".\n";
}
