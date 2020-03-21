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
#define QUAN_NO_MATH_ANGLE_NUMERIC_CONVERSION
// angles in convenient struct with output
// for quan::angle_<value_type> def see < quan/angle.hpp> line 1041
// derived quan::angle struct at line 1095
#include <quan/out/angle.hpp>

namespace {

    QUAN_ANGLE_LITERAL(rad)
    QUAN_ANGLE_LITERAL(rev)
}

int main()
{
   constexpr quan::angle::rad alpha = 1_rev;

   if ( compare(alpha, quan::angle::two_pi, 0.0_rad) ==0){
      std::cout << "alpha == 2 * pi\n";
   }
   else {
      std::cout << "conversion error = " << alpha - quan::angle::pi <<'\n';
  } 
}
