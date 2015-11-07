#ifndef QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED

#include <quan/length.hpp>
#include <quan/angle.hpp>
#include <quan/uav/position.hpp>
#include <quan/atan2.hpp>

namespace quan{ namespace uav{

/*
   always puts distance, but only put bearing if distance > 2m
   to avoid div 0, returns treu if put bearing else false
*/

   template <typename AngleType, typename LengthType, typename AngleType1, typename LengthType1>
   inline
   bool get_bearing_and_distance(
      quan::uav::position<AngleType, LengthType> const & from, 
      quan::uav::position<AngleType, LengthType> const & to, 
      AngleType1 & bearing_out, LengthType1 & distance_out)
   {

#if 1

//     template <typename PositionType>
//	inline 
//	typename PositionType::angle_type 
//	get_bearing(PositionType const & gps1, PositionType const & gps2)
//	{
      quan::angle_<float>::deg  dlat = from.lat - to.lat; // sort diffence for angle
      quan::angle_<float>::deg  dlon = from.lon - to.lon;
      constexpr typename quan::length_<float>::m R{6371000.f};
      quan::length_<float>::m  rlat = cos(quan::angle_<float>::rad{abs(to.lat)}) * R;
      quan::length_<float>::m  dx = (dlon * rlat) / quan::angle_<float>::rad{1};
      quan::length_<float>::m  dy =  (dlat * R ) / quan::angle_<float>::rad{1.f};
      quan::length_<float>::m  distance = quan::sqrt(dx * dx + dy * dy);
      distance_out = distance;
      if ( abs(distance) > quan::length_<float>::m{2.f}){
        bearing_out = quan::atan2(-dy, dx) + quan::angle::pi/2;
        return true;
      }else{
        bearing_out = AngleType1{0};
        return false;
      }

#else
// note that to and from are reversed from above impl
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

#endif
   }

}}


#endif // QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED
