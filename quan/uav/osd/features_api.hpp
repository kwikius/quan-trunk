#ifndef QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED
#define QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED

#include <quan/voltage.hpp>
#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   bool position_is_good();
   bool home_position_is_set();
   bool set_home_position(position_type const & p, bool force = false);
 // see Arduplane/libraries/AP_GPS.h for the meanings behind the
 // fix_type return values
   uint8_t read_gps_fix_type();
   uint8_t read_gps_num_sats();

   uint8_t get_num_batteries();
   const char* const get_battery_name(uint8_t n);
   quan::voltage_<float>::V  get_battery_voltage(uint8_t n);

}}}


#endif // QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED
