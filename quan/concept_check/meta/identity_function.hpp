#ifndef QUAN_CONCEPT_CHECK_META_IDENTITY_FUNCTION_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_IDENTITY_FUNCTION_HPP_INCLUDED

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <type_traits>
#include <quan/concept_check/meta/function.hpp>
#include <quan/meta/eq.hpp>

namespace quan{ namespace concept_check{ namespace meta{

   // assert that T is an identity function
   template <typename T>
   inline
   void identity_function()
   {
       quan::concept_check::meta::function<T>();
       static_assert(std::is_same<typename T::type, T>::value ,"T is not a model of meta::identity_function");
   }

}}}//quan::concept_check::meta


#endif
 