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
        // check for too small to use...
        // if dist is less than N meters == N meters = dlon * R
        typedef typename PositionType::angle_type angle_type;
        angle_type const dLon = gps2.lon - gps1.lon;
        
        auto const cos_gps2_lat =  cos(gps2.lat);
        auto const y = sin(dLon) * cos_gps2_lat;
        auto const x = cos(gps1.lat) * sin(gps2.lat)
                              - sin(gps1.lat) * cos_gps2_lat * cos(dLon);
        angle_type result  = quan::atan2(y,x);
        while (result < quan::angle_<float>::deg(0.f)){
           result += quan::angle_<float>::deg(360.f);
        }
        while (result > quan::angle_<float>::deg(360.f)){
           result -= quan::angle_<float>::deg(360.f);
        }
        return result;  
	}

}}

#endif // QUAN_UAV_GET_BEARING_HPP_INCLUDED
