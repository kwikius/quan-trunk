#ifndef QUAN_ARCHETYPES_FIXED_QUANTITY_HPP_INCLUDED
#define QUAN_ARCHETYPES_FIXED_QUANTITY_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/where.hpp>
#include <quan/meta/is_fixed_quantity.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{

   struct FixedQuantity;

   namespace impl{

      template <typename T>
      struct is_model_of_impl< quan::FixedQuantity,T> 
      : quan::meta::is_fixed_quantity<T>{};
  }//impl

}//quan


#endif // QUAN_ARCHETYPES_FIXED_QUANTITY_HPP_INCLUDED
