#ifndef QUAN_THREE_D_ROTATION_FROM_HPP_INCLUDED
#define QUAN_THREE_D_ROTATION_FROM_HPP_INCLUDED

#include <quan/three_d/vect.hpp>
#include <quan/three_d/quat.hpp>
#include <quan/angle.hpp>

// see https://bitbucket.org/sinbad/ogre/src/9db75e3ba05c/OgreMain/include/OgreVector3.h#cl-651
// https://stackoverflow.com/questions/1171849/finding-quaternion-representing-the-rotation-from-one-vector-to-another

namespace quan{ namespace three_d{

   template <typename TL, typename TR>
   inline
   quat<double> rotation_from( vect<TL> const & lhs, vect<TR> const & rhs)
   {
      auto const ul = unit_vector(lhs);
      auto const ur = unit_vector(rhs);
      auto const d = dot_product(ul,ur);
      if (d > (1e-6 - 1.0)){
         if(d < 1.){
            auto const a = cross_product(ul,ur);
            return unit_quat(quat<double>{ sqrt( norm(ul) * norm(ur) ) + d, a.x,a.y,a.z});
         }else{
            // no rotation
            return {1.0,0.0,0.0,0.0};
         }
      }else{
         // 180 degree rotation
         auto axis = unit_vector(perp_vector_axis_x(ul));
         if ( magnitude(axis) > 0.9){
            return quatFrom(axis,quan::angle::pi);
         }else{
            axis = unit_vector(perp_vector_axis_y(ul));
            if ( magnitude(axis) > 0.9){
                return quatFrom(axis,quan::angle::pi);
            }else{
                // redundant
                axis = unit_vector(perp_vector_axis_z(ul));
                return quatFrom(axis,quan::angle::pi);
            }
         }
      }
   }

}} //quan::three_d

#endif // QUAN_THREE_D_ROTATION_FROM_HPP_INCLUDED
