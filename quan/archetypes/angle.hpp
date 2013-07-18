#ifndef QUAN_ARCHETYPES_ANGLE_HPP_INCLUDED
#define QUAN_ARCHETYPES_ANGLE_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/is_angle.hpp>

namespace quan{ 

   struct Angle;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<quan::Angle,T> : quan::meta::is_angle<T> {};

   }

}//quan


#endif // QUAN_ARCHETYPES_ANGLE_HPP_INCLUDED
