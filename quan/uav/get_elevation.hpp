#ifndef QUAN_UAV_GET_ELEVATION_HPP_INCLUDED
#define QUAN_UAV_GET_ELEVATION_HPP_INCLUDED


#include <quan/uav/position.hpp>
#include <quan/uav/get_distance.hpp>
#include <quan/atan2.hpp>

#ifndef __AVR__
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
