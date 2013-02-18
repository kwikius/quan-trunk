#ifndef QUAN_UAV_RC_PULSE_HPP_INCLUDED
#define QUAN_UAV_RC_PULSE_HPP_INCLUDED

#include <quan/time.hpp>

namespace quan { namespace uav {
   struct rc_pulse{

      static constexpr auto num_channels = 10U;
      typedef quan::time_<int16_t>::us us;
      us channel[num_channels];

   };
}}//quan::uav

#endif // QUAN_UAV_RC_PULSE_HPP_INCLUDED
