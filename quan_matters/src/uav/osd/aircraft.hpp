
#ifndef QUAN_OSD_AIRCRAFT_HPP_INCLUDED
#define QUAN_OSD_AIRCRAFT_HPP_INCLUDED

/*
 Copyright (c) 2012 - 2015 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/time.hpp>
#include <quan/length.hpp>
#include <quan/velocity.hpp>
#include <quan/voltage.hpp>
#include <quan/current.hpp>
#include <quan/charge.hpp>
#include <quan/angle.hpp>
#include <quan/uav/position.hpp>
#include <quan/uav/attitude.hpp>
#include <quan/uav/osd/api.hpp>

/*
See http://gentlenav/googlecode.com/files/DCMdraft2.pdf 

"The orientation of the body frame with respect to the fixed earth system
can be determined in the following manner. Imagine the aircraft to be 
positioned so that the body axis system is parallel to the fixed frame
and then apply the following rotations:
1. Rotate the body about its zbody axis through the yaw angle thetaZ
2. Rotate the body about its ybody axis through the pitch angle thetaY
3. Rotate the body about its xbody axis through the roll angle thetaX 

The rotation matrix R =   // (untested!)
 [ 
  cos(thetaY) * cos(thetaZ) , 
      sin(thetaX) * sin(thetaY) * cos(thetaZ) - cos(thetaX) * sin(thetaZ),
         cos(thetaX) * sin(thetaY) * cos(thetaZ) - sin(thetaX) * sin(thetaZ)
   cos(thetaY) * sin(thetaZ),
      sin(thetaX) * sin(thetaY) * sin(thetaZ) + cos(thetaX) * cos(thetaZ),
         cos(thetaX) * sin(thetaY) * sin(thetaZ) - sin(thetaX) * cos(thetaZ)
   -sin(thetaY),
      sin(thetaX) * cos(thetaY),
         cos(thetaX) * cos(thetaY)
]
*/

//struct attitude_t{
//   
//   angle_type            pitch;                  
//   angle_type            roll;                   
//   angle_type            yaw; 
//   attitude_t():pitch{0},roll{0},yaw{0}{}
//};

struct aircraft{
   typedef quan::uav::osd::lat_lon_type   lat_lon_type;
   typedef quan::uav::osd::altitude_type  altitude_type;
   typedef quan::uav::osd::position_type position_type;
   typedef quan::uav::osd::attitude_type attitude_type;
   typedef quan::uav::osd::angle_type angle_type;
   position_type const & get_position() const { return m_position;}
   position_type const & get_home_position() const { return m_home_position;}
   attitude_type const & get_attitude() const { return m_attitude;}
   angle_type const & get_heading()const { return m_heading;}
   void set_heading(angle_type const & value_in)
   {
      auto value = value_in;
      while( value > angle_type{360.f}){
         value -= angle_type{360};
      }
      while( value < angle_type{0}){
         value += angle_type{360};
      }
      this->m_heading = value;
   }
   private:
   position_type                       m_position;
   position_type                       m_home_position;
   attitude_type                       m_attitude;
     
   angle_type            m_heading;              
   quan::velocity_<float>::m_per_s     m_airspeed;            
   quan::velocity_<float>::m_per_s     m_groundspeed;

      // ADD rc output values              
  public:               
   aircraft():
     // throttle{0},
      m_heading{0}
      ,m_airspeed{0}
      ,m_groundspeed{0}
   {}

   private:

};

//QUAN_DLL_LOCAL aircraft const & get_aircraft();

#endif // OSD_BITMAP_MAKER_AIRCRAFT_HPP_INCLUDED
