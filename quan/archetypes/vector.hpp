#ifndef QUAN_ARCHETYPES_VECTOR_HPP_INCLUDED
#define QUAN_ARCHETYPES_VECTOR_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/is_vector.hpp>

namespace quan{ 

   struct Vector;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<quan::Vector,T> : quan::meta::is_vector<T> {};
   
   }
}//quan


#endif // QUAN_CONCEPTS_ANGLE_HPP_INCLUDED
