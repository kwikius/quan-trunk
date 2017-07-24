#ifndef QUAN_TRACKER_DETAIL_NORMALISE_ANGLE_HPP_INCLUDED
#define QUAN_TRACKER_DETAIL_NORMALISE_ANGLE_HPP_INCLUDED

#include <quan/angle.hpp>

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
   } // detail

}} //quan::tracker

#endif // QUAN_TRACKER_DETAIL_NORMALISE_ANGLE_HPP_INCLUDED
