#ifndef QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED

#include <quan/length.hpp>
#include <quan/angle.hpp>
#include <quan/uav/position.hpp>

namespace quan{ namespace uav{

/*
   always puts distance, but only put bearing if distance > 2m
   to avoid div 0, returns treu if put bearing else false
*/

   template <typename AngleType, typename LengthType>
   inline
   bool get_bearing_and_distance(
      quan::uav::position<AngleType, LengthType> const & from, 
      quan::uav::position<AngleType, LengthType> const & to, 
      AngleType & bearing_out, LengthType & distance_out
   {
       typedef AngleType angle_type;
       typedef LengthType length_type;

       constexpr quan::length_<QUAN_FLOAT_TYPE>::m rworld{6371000};
       angle_type const dlat = to.lat - from.lat; // sort diffence for angle
       angle_type const dlon = to.lon - from.lon;

       length_type const rlat = cos(quan::angle_<QUAN_FLOAT_TYPE>::rad{abs((to.lat + from.lat)/2)}) * rworld;
       length_type const dx = (dlon * rlat) / quan::angle_<QUAN_FLOAT_TYPE>::rad{1};

       length_type const dy =  (dlat * rworld ) / quan::angle_<QUAN_FLOAT_TYPE>::rad{1};
       distance_out = quan::sqrt(dx * dx + dy * dy);
       if ( abs(distance_out) > quan::length::m{2}){
         bearing_out = quan::atan2(-dy, dx) + quan::angle::pi/2;
         return true;
       }else{
         return false;
       }
   }

}}


#endif // QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED
