
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

#include <quan/out/length.hpp>
    
/*
    get conversion factor from one dimensionally-equivalent 
    type to another
*/

namespace quan{

    template <
        typename Target,
        typename Source
    >
    typename quan::meta::arithmetic_promote<
        typename Target::value_type,
        typename Source::value_type
    >::type
    conversion_factor()
    {
        Source s(1);
        Target t = s;
        return t.numeric_value();
    }

    
}//quan

int main()
{
    quan::length::m plankA(2);
    quan::length::mm plankB(1000);
    std::cout << "ratio  plankA / plankB = " << plankA / plankB << '\n'; 

    std::cout << "conversion-factor\n";
    std::cout << quan::conversion_factor<
        quan::length::mm,quan::length::m
    >() << '\n';
}
