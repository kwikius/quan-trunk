#ifndef QUAN_UAV_GET_BEARING_HPP_INCLUDED
#define QUAN_UAV_GET_BEARING_HPP_INCLUDED

#include <quan/uav/position.hpp>
#ifndef __AVR__
#include <cmath>
#else
#include <math.h>
#endif

namespace quan{ namespace uav{

 // gives bearing in degrees relative to grid north
 // positive is clockwise

	inline 
	quan::angle::deg 
	get_bearing(quan::uav::position const & gps1, quan::uav::position const & gps2)
	{
// maybe 0.02 sec   
        quan::angle::rad const dLon = gps2.get_lon() - gps1.get_lon();
        QUAN_FLOAT_TYPE const cos_gps2_lat =  cos(gps2.get_lat());
        QUAN_FLOAT_TYPE const y = sin(dLon) * cos_gps2_lat;
        QUAN_FLOAT_TYPE const x = cos(gps1.get_lat()) * sin(gps2.get_lat())
                              - sin(gps1.get_lat()) * cos_gps2_lat * cos(dLon);
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
