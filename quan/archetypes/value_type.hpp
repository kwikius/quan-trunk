#ifndef QUAN_ARCHETYPES_VALUE_TYPE_HPP_INCLUDED
#define QUAN_ARCHETYPES_VALUE_TYPE_HPP_INCLUDED

#include <quan/where.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/is_value_type.hpp>

namespace quan{ 

   struct ValueType;

   namespace impl{

      template <typename T>
      struct is_model_of_impl<quan::ValueType,T> : quan::meta::is_value_type<T> {};

   }

}//quan


#endif // QUAN_ARCHETYPES_VALUE_TYPE_HPP_INCLUDED
