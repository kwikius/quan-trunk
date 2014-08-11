#ifndef UAV_PROTOCOL_HPP_INCLUDED
#define UAV_PROTOCOL_HPP_INCLUDED
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

#include <quan/angle.hpp>
#include <quan/length.hpp>

/*
 source in quan_matters/uav/msg_protocol.cpp
*/


//move into frsky namespace
namespace quan{namespace uav{ namespace frsky{
/*
 The ids for sending messages on the frsky link
*/
      struct msgID{
         static constexpr uint8_t header_value =   0x5e;
         static constexpr uint8_t escape_value =   0x5d;
         static constexpr uint8_t GPSLAT   =       0x1; // deg to uint32_t *** change this to signed *** DONE
         static constexpr uint8_t GPSLON   =       0x2; // deg to uint32_t *** change this to signed *** DONE
         static constexpr uint8_t GPSALT   =       0x3; // cm to uint32_t *** change this to signed *** DONE
         static constexpr uint8_t GPSHEADING =     0x4; // deg<uint8_t> ??? change to signed or decimal degrees?
         static constexpr uint8_t GPSSPEED  =      0x5; // find format used 
         static constexpr uint8_t COMPASSBEARING = 0x6; 
         static constexpr uint8_t AIRSPEED =       0x7; // change to signed int32 DONE
         static constexpr uint8_t BAROALT =        0x8; // int32_t
         // add attitude  split 32 bits into 3 of 10 bits signed x,y,z
         // add battery voltage, current
      };
       
      struct abc_msg{
        virtual ~abc_msg(){}
      };

      template<uint8_t ID, typename InputType,typename OutputType>
      struct create_msg;

      

      template<uint8_t ID>
       struct create_msg<ID,quan::angle::deg,int32_t> : abc_msg{
          typedef quan::angle::deg input_type;
          typedef int32_t output_type;
          create_msg(input_type const & in);
          static constexpr int length = sizeof(output_type)+3;
          typedef uint8_t const(&result_type)[length];
          result_type get()const{return m_msg_buf;}
        private:
          typedef union{
               uint8_t m_array[sizeof(output_type)];
               output_type m_raw_value;
          } converter;
          uint8_t      m_msg_buf[length];
       };

       typedef create_msg<msgID::GPSLAT,quan::angle::deg,int32_t> lat_msg;
       typedef create_msg<msgID::GPSLON,quan::angle::deg,int32_t> lon_msg;

       template<uint8_t ID>
       struct create_msg<ID,quan::length::mm,int32_t> : abc_msg{
          typedef quan::length::mm input_type;
          typedef int32_t output_type;
          create_msg(input_type const & in);
          static constexpr int length = sizeof(output_type)+3;
          typedef uint8_t const(&result_type)[length];
          result_type get()const{return m_msg_buf;}
        private:
          typedef union{
               uint8_t m_array[sizeof(output_type)];
               output_type m_raw_value;
          } converter;
          uint8_t      m_msg_buf[length];
       };

       typedef create_msg<msgID::GPSALT,quan::length::mm,int32_t> gps_alt_msg;
       typedef create_msg<msgID::BAROALT,quan::length::mm,int32_t> baro_alt_msg;
       

}}}//quan::uav::frsky


#endif // UAV_PROTOCOL_HPP_INCLUDED
