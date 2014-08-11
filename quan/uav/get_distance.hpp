#ifndef QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
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
#include <quan/cmath.hpp>
#ifndef __AVR__
#include <cmath>
#else
#include <math.h>
#endif

namespace quan{ namespace uav{

inline
quan::length::m 
get_distance(quan::uav::position const & gps1, quan::uav::position const & gps2)
{

    constexpr quan::length::m  			   R{6371000};

    quan::angle_<int32_t>::deg10e7  dlat = gps2.lat - gps1.lat; // sort diffence for angle
    quan::angle_<int32_t>::deg10e7  dlon = gps2.lon - gps1.lon;

   quan::length::m  rlat = cos((gps1.lat + gps2.lat)/2) * R;
   quan::length::m  dx = quan::angle::rad{dlon} * rlat;
   quan::length::m  dy = quan::angle::rad{dlat} * R;
   return quan::sqrt( dx * dx + dy * dy);

}


}}


#endif // QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
