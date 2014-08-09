#ifndef QUAN_TRACKER_ZAPP3_ENCODE_HPP_INCLUDED
#define QUAN_TRACKER_ZAPP3_ENCODE_HPP_INCLUDED

#include <quan/uav/cobs/protocol.hpp>
#include <quan/uav/position.hpp>
#include <quan/uav/fletcher16.hpp>

namespace quan{ namespace tracker{

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
