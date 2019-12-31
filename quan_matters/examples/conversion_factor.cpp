
/*
 Copyright (c) 2003-2017 Andy Little.

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

#include <quan/out/length.hpp>
#include <quan/time.hpp>
#include <quan/where.hpp>

/*
    get conversion factor from one dimensionally-equivalent 
    type to another
    N.B only works with dimenionally equivalent types
    with arithmetci value_types
*/

namespace quan{

    template <
        typename Target,
        typename Source
    >
    inline constexpr
    typename quan::where_<
       quan::meta::dimensionally_equivalent<Target,Source>,
       typename quan::meta::arithmetic_promote<
           typename Target::value_type,
           typename Source::value_type
       >::type
    >::type
    conversion_factor()
    {
        return Target{Source{1}}.numeric_value();
    }

}//quan

namespace {

   QUAN_QUANTITY_REAL_LITERAL(length,mm)
   QUAN_QUANTITY_REAL_LITERAL(length,m)
}

int main()
{
    quan::length::m constexpr plankA = 2.0_m;
    quan::length::mm constexpr plankB = 1000.0_mm;

    std::cout << "ratio  plankA / plankB = " << plankA / plankB << '\n'; 

    std::cout << "conversion factor to convert from vS in " << units_str(plankA) ;
    std::cout << " to vT in " << units_str(plankB) << " : vT = vS * ";
    std::cout << quan::conversion_factor<
        quan::length::mm,quan::length::m
    >() << '\n';

    // can be evaluated at compile time
    static_assert(quan::conversion_factor<
        quan::length::mm,quan::length::m
    >() == 1000,"error");

   // auto x = quan::conversion_factor<quan::length::m,quan::time::s>(); // error as not dimensionally equivalent
}
