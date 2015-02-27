#ifndef QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED
#define QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED

#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   bool position_is_good();
   bool home_position_is_set();
   bool set_home_position(position_type const & p, bool force = false);
 // see Arduplane/libraries/AP_GPS.h for the meanings behind thes
 // returned values
   uint8_t read_gps_fix_type();
   uint8_t read_gps_num_sats();

}}}


#endif // QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED
