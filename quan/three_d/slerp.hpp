#ifndef QUAN_THREE_D_SLERP_HPP_INCLUDED
#define QUAN_THREE_D_SLERP_HPP_INCLUDED

#include <quan/three_d/quat.hpp>
#include <cmath>

namespace quan{ namespace three_d{
// from wikipedia
   template <typename T, typename Float>
   inline
   quan::three_d::quat<T> slerp(quan::three_d::quat<T> const & v0In, quan::three_d::quat<T> const & v1In, Float const & t) 
  {
       // Only unit quaternions are valid rotations.
       // Normalize to avoid undefined behavior.
       auto const v0 = unit_quat(v0In);
       auto v1 = unit_quat(v1In);

       // Compute the cosine of the angle between the two vectors.
       auto dot = dot_product(v0, v1);
       typedef decltype(dot) dot_type;
       // If the dot product is negative, slerp won't take
       // the shorter path. Note that v1 and -v1 are equivalent when
       // the negation is applied to all four components. Fix by 
       // reversing one quaternion.
       if (dot < dot_type{0.0f}) {
           v1 = -v1;
           dot = -dot;
       }

       const auto DOT_THRESHOLD = dot_type{0.9995};
       if (dot > DOT_THRESHOLD) {
           // If the inputs are too close for comfort, linearly interpolate
           // and normalize the result.
           return unit_quat(v0 + t * (v1 - v0));
       }
      
       // Since dot is in range [0, DOT_THRESHOLD], acos is safe
       dot_type const theta_0 = std::acos(dot);        // theta_0 = angle between input vectors
       dot_type const theta = theta_0 * t;          // theta = angle between v0 and result
       dot_type const sin_theta = std::sin(theta);     // compute this value only once
       dot_type const sin_theta_0 = std::sin(theta_0); // compute this value only once

       dot_type const s0 = std::cos(theta) - dot * sin_theta / sin_theta_0;  // == sin(theta_0 - theta) / sin(theta_0)
       dot_type const s1 = sin_theta / sin_theta_0;

       return unit_quat( s0 * v0 + s1 * v1);
   }
}}// quan::three_d


#endif // QUAN_THREE_D_SLERP_HPP_INCLUDED
