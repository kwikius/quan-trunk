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
/*
    pi as an angle, and two_pi;
*/ 

//constants values in <quan/src/constant.cpp> provided by Paul Bristow

#include <quan/angle.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS

template <>
quan::angle_<float>::rad const
quan::angle_<float>::pi 
= quan::angle_<
    float
>::rad(3.141592653589793238462643383279502884197F);

template <>
quan::angle_<double>::rad const
quan::angle_<double>::pi 
= quan::angle_<
    double
>::rad(3.141592653589793238462643383279502884197);

template <>
quan::angle_<long double>::rad const
quan::angle_<long double>::pi 
= quan::angle_<
    long double
>::rad(3.141592653589793238462643383279502884197L);


template <>
quan::angle_<float>::rad const
quan::angle_<float>::two_pi 
= quan::angle_<
    float
>::rad(2 * 3.141592653589793238462643383279502884197F);

template <>
quan::angle_<double>::rad const
quan::angle_<double>::two_pi 
= quan::angle_<
    double
>::rad(2 * 3.141592653589793238462643383279502884197);

template <>
quan::angle_<long double>::rad const
quan::angle_<long double>::two_pi 
= quan::angle_<
    long double
>::rad(2 * 3.141592653589793238462643383279502884197L);

#endif

