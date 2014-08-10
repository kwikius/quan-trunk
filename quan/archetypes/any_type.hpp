#ifndef QUAN_CONCEPTS_ANY_TYPE_HPP_INCLUDED
#define QUAN_CONCEPTS_ANY_TYPE_HPP_INCLUDED


// Copyright Andrew Little 2007. All rights reserved

#include <quan/where.hpp>
#include <quan/meta/strip_cr.hpp>
#include <quan/undefined.hpp>
#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{ 

   struct AnyType;

   namespace meta{

      template <typename T>
      struct is_any_type : impl::is_any_type_impl<typename strip_cr<T>::type>{};
   }

   namespace impl{

      template <typename T>
      struct is_model_of_impl<quan::AnyType,T> : quan::meta::is_any_type<T> {};

   }

}//quan



#endif

