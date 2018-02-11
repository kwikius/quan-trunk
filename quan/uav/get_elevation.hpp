#ifndef QUAN_UAV_GET_ELEVATION_HPP_INCLUDED
#define QUAN_UAV_GET_ELEVATION_HPP_INCLUDED
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


#include <quan/uav/position.hpp>
#include <quan/uav/get_distance.hpp>
#include <quan/atan2.hpp>

#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cmath>
#else
#include <math.h>
#endif

namespace quan { namespace uav{


   inline quan::angle::deg get_elevation(quan::uav::position const & gps1, quan::uav::position const & gps2)
   {
       return quan::atan2(gps2.alt - gps1.alt, get_distance(gps1,gps2));
   }

}}

#endif // QUAN_UAV_GET_ELEVATION_HPP_INCLUDED
