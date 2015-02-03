#ifndef QUAN_TRACKER_ZAPP3_DECODE_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP3_DECODE_HPP_INCLUDED
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

namespace quan{ namespace tracker{

   inline bool zapp3_decode(
      uint8_t const( &encoded) [16],
       quan::uav::position<
         quan::angle_<int32_t>::deg10e7,
         quan::length_<int32_t>::mm  // N.B changed to mm from old protocol
      > & pos
   )
   {
      if( encoded[0] != 0){
         return false;
      }
      union {
         struct {
            int32_t lat;
            int32_t lon;
            int32_t alt;
         } vals;
         uint8_t ar[14];
      } u;

      if (!quan::uav::cobs::decode(encoded+1,15,u.ar)){
         return false;
      }
      uint16_t ck1 = quan::uav::fletcher16 (u.ar,12);
      uint16_t ck2 = static_cast<uint16_t>(u.ar[12]) | (static_cast<uint16_t>(u.ar[13]) << 8U);
      if (ck1 != ck2){
         return false;
      }
      pos.lat = quan::angle_<int32_t>::deg10e7{u.vals.lat};
      pos.lon = quan::angle_<int32_t>::deg10e7{u.vals.lon};
      pos.alt = quan::length_<int32_t>::mm{u.vals.alt};
      return true;
   }
}}

#endif // QUAN_TRACKER_ZAPP3_DECODE_HPP_INCLUDED
