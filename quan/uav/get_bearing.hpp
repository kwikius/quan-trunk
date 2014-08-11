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

	inline 
	quan::angle::deg 
	get_bearing(quan::uav::position const & gps1, quan::uav::position const & gps2)
	{
        // check for too small to use...
        // if dist is less than N meters == N meters = dlon * R
        quan::angle::rad const dLon = gps2.lon - gps1.lon;

        
        auto const cos_gps2_lat =  cos(gps2.lat);
        auto const y = sin(dLon) * cos_gps2_lat;
        auto const x = cos(gps1.lat) * sin(gps2.lat)
                              - sin(gps1.lat) * cos_gps2_lat * cos(dLon);
        quan::angle::deg result = quan::atan2(y,x);
        while (result < quan::angle::deg(0)){
           result += quan::angle::deg(360);
        }
        while (result > quan::angle::deg(360)){
           result -= quan::angle::deg(360);
        }
        return result;  
	}

}}

#endif // QUAN_UAV_GET_BEARING_HPP_INCLUDED
