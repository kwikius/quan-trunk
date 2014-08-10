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
 along with this program. If not, see http://www.gnu.org/licenses.
*/



#include <quan/angle.hpp>
#include <quan/uav/msg_protocol.hpp>
#include <quan/uav/do_checksum.hpp>
#include <quan/arithmetic_convert.hpp>

/*
convert an angle to the dege7 array format for transport 
*/
template<uint8_t ID>
quan::uav::frsky::create_msg<ID,quan::angle::deg,int32_t>::create_msg(quan::angle::deg const & angle_in) {

   m_msg_buf[0] = msgID::header_value;
   m_msg_buf[1] = ID;

  // static constexpr auto zero = quan::angle::deg{0};
   static constexpr auto angle_max = quan::angle::deg{180}; 
   static constexpr auto one_rotation = quan::angle::deg{360};

   auto angle = angle_in;

   while (angle < -angle_max){
      angle += one_rotation;
   }
   while (angle > angle_max){
      angle -=  one_rotation;
   }

   converter conv;
   conv.m_raw_value = quan::arithmetic_convert<output_type>(angle.numeric_value() * 1e7);

   for (uint32_t i = 0; i < sizeof(output_type);++i){
      m_msg_buf[2 + i] = conv.m_array[i];
   }
   m_msg_buf[length -1] = do_checksum(m_msg_buf);
}

/*
convert length in mm to array for transport
*/
template<uint8_t ID>
quan::uav::frsky::create_msg<ID,quan::length::mm,int32_t>::create_msg(quan::length::mm const & length_in) {

   m_msg_buf[0] = msgID::header_value;
   m_msg_buf[1] = ID;

   converter conv;
   conv.m_raw_value = quan::arithmetic_convert<output_type>(length_in.numeric_value());

   for (uint32_t i = 0; i < sizeof(output_type);++i){
      m_msg_buf[2 + i] = conv.m_array[i];
   }
    m_msg_buf[length -1] = do_checksum(m_msg_buf);
}

template struct quan::uav::frsky::create_msg<quan::uav::frsky::msgID::GPSLAT,quan::angle::deg,int32_t>;
template struct quan::uav::frsky::create_msg<quan::uav::frsky::msgID::GPSLON,quan::angle::deg,int32_t>;

template struct quan::uav::frsky::create_msg<quan::uav::frsky::msgID::GPSALT,quan::length::mm,int32_t>;
template struct quan::uav::frsky::create_msg<quan::uav::frsky::msgID::BAROALT,quan::length::mm,int32_t>;


