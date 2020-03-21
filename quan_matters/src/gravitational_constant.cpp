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
 
  #if ! defined __MBED__
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/constants/gravitational_constant.hpp>
/*
    gravitational_constant definition required to link
*/
#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::gravitational_constant_<long double>::G_type const 
quan::gravitational_constant_<long double>::G
= quan::gravitational_constant_<long double>::G_type(6.6726L);

template<>
quan::gravitational_constant_<double>::G_type const  
quan::gravitational_constant_<double>::G
= quan::gravitational_constant_<double>::G_type(6.6726);

template<>
quan::gravitational_constant_<float>::G_type const  
quan::gravitational_constant_<float>::G
= quan::gravitational_constant_<float>::G_type(6.6726F);
#endif

#endif


