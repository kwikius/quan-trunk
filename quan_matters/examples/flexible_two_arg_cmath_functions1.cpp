
/*
 Copyright (c) 2003-2014 Andy Little.
 Copyright T. Zach Laine 2006

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
    Enhanced implementation of atan2 will work with
    any two fixed_quantities of the same dimension, instead of being restricted to the same unit,
    but only if the static units allow conversions
*/

#include <quan/out/angle.hpp>
#include <quan/out/length.hpp>
#include <quan/atan2.hpp>

namespace {

   QUAN_QUANTITY_LITERAL(length,m)

}

int main()
{
    auto length1 = 10.0_m;
    auto length2 = quan::length::yd{length1};

    std::cout << "length1 = " << length1 << "\n";
    std::cout << "length2 = " << length2 << "\n";

    std::cout << "atan2(length1, length2) = " << atan2(length1, length2) << "\n";
    std::cout << "std::atan2(1.,1.) = " << std::atan2(1.,1.) <<'\n';
    // this provides angles in rads
    if( quan::compare(atan2(length1, length2),quan::atan2(1.,1.),1e-12) ==0){
       std::cout << "match 1 \n";
    }
    else {
       std::cout << "no match 1\n";
    }
    // this provides angle in rad but automatically converts from rad value_type provided by std::atan2
    if( quan::compare(atan2(length1, length2),std::atan2(1.,1.),1e-12) ==0){
       std::cout << "match 2\n";
    }
    else {
       std::cout << "no match 2\n";
    }
    return 0;
}
