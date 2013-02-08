#ifndef QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_DISTANCE_HPP_INCLUDED

#include <quan/uav/position.hpp>
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
//maybe = 0.02 s v approx
    quan::length::m const 						R(6371000);
    quan::angle::rad const 				   dlat = gps2.get_lat() - gps1.get_lat();
    quan::angle::rad const 					dlon = gps2.get_lon() - gps1.get_lon();
 
    QUAN_FLOAT_TYPE const 						latH = quan::pow<2>(sin(dlat/2));
    QUAN_FLOAT_TYPE const						lonH = quan::pow<2>(sin(dlon/2));
 
    QUAN_FLOAT_TYPE const                 tmp = cos(gps1.get_lat()) * cos(gps2.get_lat());
    return                                 asin(sqrt(latH + tmp * lonH)) * 2 * R;
   //could add height part too.. useful to know radio distance?
}


}}


#endif // QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
