
#ifndef QUAN_ATAN_HPP_INCLUDED
#define QUAN_ATAN_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/meta/is_angle_value_type.hpp>
#include <quan/angle.hpp>
#include <cmath>

namespace quan{

   template <typename T>
   inline
   typename quan::where_<
      quan::meta::is_angle_value_type<T>,
      quan::angle::rad
   >::type
   atan(T const & v)
   {
      return quan::angle::rad(std::atan(v));
   }
}

#endif
