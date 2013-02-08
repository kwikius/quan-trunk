#ifndef QUAN_ARCHETYPES_SCALAR_HPP_INCLUDED
#define QUAN_ARCHETYPES_SCALAR_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/is_scalar.hpp>

namespace quan{ 

   struct Scalar;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<quan::Scalar,T> : quan::meta::is_scalar<T> {};

   }

}//quan


#endif // QUAN_CONCEPTS_ANGLE_HPP_INCLUDED
