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

//// rad/s to freq.
#include <quan/out/angle.hpp>
#include <quan/out/reciprocal_time.hpp>
///for angle::pi def
#include <quan_matters/src/angle.cpp>
#include <iostream>

int main()
{
   // use angle as value_type
   typedef quan::reciprocal_time_<
      quan::angle::rad
   >::per_s rad_per_s;

   rad_per_s x( quan::angle::rad(1));
//####### now disallowed
#if(0)
   quan::reciprocal_time::per_min xx =x;
#endif
//###############
//OK
   x *=2;
   x/=2;
   rad_per_s zz = x *2;
   std::cout << zz <<'\n';
   quan::reciprocal_time::per_min xxx =x /(2*quan::angle::pi);

   std::cout << 1/zz <<'\n';

   std::cout << xxx <<'\n';
}
