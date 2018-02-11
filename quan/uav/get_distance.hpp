#ifndef QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
#define QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
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
#include <quan/cmath.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cmath>
#else
#include <math.h>
#endif

namespace quan{ namespace uav{

   template <typename LengthTypeOut,typename PositionType> 
   inline
   LengthTypeOut
   get_distance(PositionType const & gps1, PositionType const & gps2)
   {
       typedef LengthTypeOut length_type;
       typedef typename PositionType::angle_type angle_type;

       constexpr typename quan::length_<typename length_type::value_type>::m R{6371000.f};

       angle_type const dlat = gps2.lat - gps1.lat; // sort diffence for angle
       angle_type const dlon = gps2.lon - gps1.lon;

      length_type const rlat = cos((gps1.lat + gps2.lat)/2.f) * R;
      length_type const dx = quan::angle_<float>::rad{dlon} * rlat;
      length_type const dy = quan::angle_<float>::rad{dlat} * R;

      return quan::sqrt( dx * dx + dy * dy);
   }

}}


#endif // QUAN_UAV_GET_DISTANCE_HPP_INCLUDED
