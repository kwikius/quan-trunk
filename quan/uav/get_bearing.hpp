#ifndef QUAN_UAV_GET_BEARING_HPP_INCLUDED
#define QUAN_UAV_GET_BEARING_HPP_INCLUDED
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
#include <quan/atan2.hpp>

namespace quan{ namespace uav{

 // gives bearing in degrees relative to grid north
 // positive is clockwise

   template <typename PositionType>
	inline 
	typename PositionType::angle_type 
	get_bearing(PositionType const & gps1, PositionType const & gps2)
	{
      quan::angle_<float>::deg  dlat = gps1.lat - gps2.lat; // sort diffence for angle
      quan::angle_<float>::deg  dlon = gps1.lon - gps2.lon;
      constexpr typename quan::length_<float>::m R{6371000.f};
      quan::length_<float>::m  rlat = cos(quan::angle_<float>::rad{abs(gps2.lat)}) * R;
      quan::length_<float>::m  dx = (dlon * rlat) / quan::angle_<float>::rad{1};
      quan::length_<float>::m  dy =  (dlat * R ) / quan::angle_<float>::rad{1.f};
      quan::length_<float>::m  distance = quan::sqrt(dx * dx + dy * dy);
      if ( abs(distance) > quan::length::m{2}){
        return quan::atan2(-dy, dx) + quan::angle::pi/2;
      }else{
         return typename PositionType::angle_type{0};
      }
	}
}}

#endif // QUAN_UAV_GET_BEARING_HPP_INCLUDED
