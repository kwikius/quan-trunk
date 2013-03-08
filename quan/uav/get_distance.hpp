#ifndef QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_DISTANCE_HPP_INCLUDED

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
