#ifndef QUAN_META_IS_MODEL_OF_HPP_INCLUDED
#define QUAN_META_IS_MODEL_OF_HPP_INCLUDED

#include <quan/is_model_of.hpp>

namespace quan{ namespace meta{

template <typename C>
   struct is_model_of{

      template <typename T>
      struct apply : quan::is_model_of<C,T>{};

   };

}} //quan::meta

#endif // QUAN_META_IS_MODEL_OF_HPP_INCLUDED
