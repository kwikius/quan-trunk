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
    boltzmanns constant definition
*/
#include <quan/config.hpp>
#include <quan/constants/boltzmanns_constant.hpp>

#if ! defined __MBED__
#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<>
quan::boltzmanns_constant_<double>::K_type const
quan::boltzmanns_constant_<double>::K 
= quan::boltzmanns_constant_<double>::K_type(1.380658);

template<>
quan::boltzmanns_constant_<long double>::K_type const
quan::boltzmanns_constant_<long double>::K 
= quan::boltzmanns_constant_<long double>::K_type(1.380658L);

template<>
quan::boltzmanns_constant_<float>::K_type const
quan::boltzmanns_constant_<float>::K 
= quan::boltzmanns_constant_<float>::K_type(1.380658f);

#endif
#endif

