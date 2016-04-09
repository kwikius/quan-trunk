#ifndef QUAN_UAV_ATTITUDE_HPP_INCLUDED
#define QUAN_UAV_ATTITUDE_HPP_INCLUDED

#include <quan/angle.hpp>

/*
  Could be some confusion here  as yet
Think these are Euler angles ( as far as provided by Mavlink in APM)
Here is what I can glean so far
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

 x axis positive forward is plane direction
 y axis positive to left from pilot view
 z axis positive down ( if from plane view, think of object on ground etc)

  so seq is roll * pitch * yaw
*/

namespace quan{ namespace uav{

   template <typename ValueType>
   struct attitude{
      typedef ValueType value_type;
       
      typename quan::angle_<ValueType>::deg            yaw;
      typename quan::angle_<ValueType>::deg            pitch;                  
      typename quan::angle_<ValueType>::deg            roll;                   
      attitude():yaw{0},pitch{0},roll{0}{}
      attitude(
         typename quan::angle_<ValueType>::deg const & yaw_in
         ,typename quan::angle_<ValueType>::deg const & pitch_in
         ,typename quan::angle_<ValueType>::deg const & roll_in
      ): yaw{yaw_in},pitch{pitch_in},roll{roll_in}{}
   };

}}

#endif // QUAN_UAV_ATTITUDE_HPP_INCLUDED
