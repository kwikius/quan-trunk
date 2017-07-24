#ifndef QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED

#include <quan/length.hpp>
#include <quan/angle.hpp>
#include <quan/uav/position.hpp>
#include <quan/atan2.hpp>

namespace quan{ namespace uav{

/*
   Always write results, but return false if too close to home to calculate

   N.B. Dont input a uav_position with the quan::angle_<int32_t>::deg10e7 for lat lon
   It will provide incorrect results
   Convert it to a quan::angle_<float>::deg for correct results
   eg deg_float temp  = deg10_e7;
*/

   template <typename AngleType, typename LengthType, typename AngleType1, typename LengthType1>
   inline
   bool get_bearing_and_distance(
      quan::uav::position<AngleType, LengthType> const & from, 
      quan::uav::position<AngleType, LengthType> const & to, 
      AngleType1 & bearing_out, LengthType1 & distance_out)
   {
       static_assert( std::is_same<AngleType,quan::angle_<int32_t>::deg10e7>::value == false,"Error not a good choice of angle type");

       typedef AngleType angle_type;
       typedef LengthType length_type;

       constexpr quan::length_<QUAN_FLOAT_TYPE>::m rworld{static_cast<QUAN_FLOAT_TYPE>(6371000)};
       angle_type const dlat = from.lat - to.lat; // sort diffence for angle
       angle_type const dlon = from.lon - to.lon;

       length_type const rlat = cos(quan::angle_<QUAN_FLOAT_TYPE>::rad{abs((to.lat + from.lat)/2)}) * rworld;
       length_type const dx = (dlon * rlat) / quan::angle_<QUAN_FLOAT_TYPE>::rad{1};

       length_type const dy =  (dlat * rworld ) / quan::angle_<QUAN_FLOAT_TYPE>::rad{1};
       distance_out = quan::sqrt(dx * dx + dy * dy);
       if ( abs(distance_out) > quan::length::m{2}){
         bearing_out = quan::atan2(-dy, dx) + quan::angle::pi/2;
         return true;
       }else{
         bearing_out = AngleType1{0};
         return false;
       }
   }

}}

#endif // QUAN_UAV_GET_BEARING_AND_DISTANCE_HPP_INCLUDED
