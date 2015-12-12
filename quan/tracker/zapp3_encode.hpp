#ifndef QUAN_TRACKER_ZAPP3_ENCODE_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP3_ENCODE_HPP_INCLUDED
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

#include <quan/uav/cobs/protocol.hpp>
#include <quan/uav/position.hpp>
#include <quan/uav/fletcher16.hpp>
#include <quan/tracker/detail/normalise_angle.hpp>

namespace quan{ namespace tracker{

#if 0
   namespace detail {
      // max =  1800000000
      // min = -1799999999
      inline int32_t normalise (quan::angle_<int32_t>::deg10e7 const & in)
      {
         int64_t v = in.numeric_value();
         if ( v >      1800000000LL){
                  v -= 3600000000LL;
         }else{
            if ( v <  -1799999999LL){
                 v +=  3600000000LL;
            }
         }
        return static_cast<int32_t>(v);
      }
   }
#endif
   inline void zapp3_encode (
      quan::uav::position<
         quan::angle_<int32_t>::deg10e7,
         quan::length_<int32_t>::mm  // N.B changed to mm from old protocol
      > const & pos,
      uint8_t (&encoded) [16]
   )
   {
      union {
         struct {
            int32_t lat;
            int32_t lon;
            int32_t alt;
         } vals;
         uint8_t ar[14];
      } u;

      u.vals.lat = quan::tracker::detail::normalise (pos.lat);
      u.vals.lon = quan::tracker::detail::normalise (pos.lon);
      u.vals.alt = pos.alt.numeric_value();

      uint16_t ck = quan::uav::fletcher16 (u.ar,12);
      u.ar[12] = static_cast<uint8_t> (ck & 0xFF);
      u.ar[13] = static_cast<uint8_t> ( (ck & 0xFF00) >> 8);

      quan::uav::cobs::encode (u.ar,14,encoded+1);
      encoded[0] = 0U; // framing byte
   }
}}

#endif // QUAN_TRACKER_ZAPP3_ENCODE_HPP_INCLUDED
