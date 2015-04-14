#ifndef QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED
#define QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED

#include <quan/voltage.hpp>
#include <quan/current.hpp>
#include <quan/velocity.hpp>
#include <quan/uav/osd/api.hpp>

namespace quan{ namespace uav{ namespace osd{

   bool position_is_good();
   bool home_position_is_set();
   bool set_home_position(position_type const & p, bool force = false);
 // see Arduplane/libraries/AP_GPS.h for the meanings behind the
 // fix_type return values
   uint8_t read_gps_fix_type();
   uint8_t read_gps_num_sats();
   quan::length_<uint16_t>::cm read_gps_hdop();
   uint16_t get_osd_mode();
   uint16_t get_rssi();

   uint8_t get_num_batteries();
   const char* const get_battery_name(uint8_t n);
   quan::voltage_<float>::V  get_battery_voltage(uint8_t n);
   quan::current_<float>::A  get_battery_current(uint8_t n);
   float get_battery_remaining(uint8_t n);
   uint8_t get_custom_mode();
   uint16_t get_rssi();
   uint16_t get_rc_raw_chan(uint8_t channel);
   uint8_t get_base_mode();
   quan::velocity_<float>::m_per_s get_groundspeed();
   quan::velocity_<float>::m_per_s get_airspeed();
   quan::length_<float>::m get_baro_alt();
  
}}}


#endif // QUAN_UAV_OSD_FEATURES_API_HPP_INCLUDED
