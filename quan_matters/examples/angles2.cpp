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
#include <quan/out/time.hpp>
#include <quan/out/length.hpp>
///for angle::pi def
#include <quan_matters/src/angle.cpp>
#include <quan_matters/src/constant.cpp>

int main()
{
   // use angle as value_type
   // radians
   typedef quan::reciprocal_time_<quan::angle::rad>::per_s rad_per_s;

   // quan::angle rev is a fraction of revolution 
   // representing an angle type of 1 revolution
   typedef quan::reciprocal_time_<quan::angle::rev>::per_min rev_per_min;

   rad_per_s mu( quan::angle::rad(1));

   rev_per_min rpm =mu;

   std::cout << "rpm = " << rpm <<'\n';

// compute an arc length from quantity with rev_per_min
   quan::length::m radius(12);
   quan::time::s t(1);
//using "strong" angle type arc length value_type must be angular...
#if (0)
// should fail 
   quan::length_<double>::m arc_length = rpm * radius * t;
#else
//should succeed
   quan::length_<quan::angle::rad>::m arc_length = rpm * radius * t;
#endif
   std::cout 
   << arc_length << " should be same as " << radius << " (but \"angular\")\n";
}
