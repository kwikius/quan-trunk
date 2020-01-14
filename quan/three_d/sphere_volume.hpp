#ifndef QUAN_THREE_D_SPHERE_VOLUME_HPP_INCLUDED
#define QUAN_THREE_D_SPHERE_VOLUME_HPP_INCLUDED

#include <quan/three_d/sphere.hpp>
#include <quan/constants/constant.hpp>
#include <quan/fixed_quantity/operations/power_root.hpp>

namespace quan{ namespace three_d{

   //volume of a sphere

   template <typename LengthType>
   inline constexpr
   typename quan::meta::binary_op<
      LengthType,
      quan::meta::pow,
      quan::meta::rational<3>
   >::type
   get_volume(quan::three_d::sphere<LengthType> const & s)
   {
      return (4.0/3.0) * quan::constant::pi * quan::pow<3>(s.radius);
   }

}} // quan::three_d

#endif // QUAN_THREE_D_SPHERE_VOLUME_HPP_INCLUDED
