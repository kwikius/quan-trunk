#ifndef QUAN_CONCEPT_CHECK_META_BOOLEAN_FUNCTION_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_BOOLEAN_FUNCTION_HPP_INCLUDED
// Copyright Andrew Little 2006


// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/concept_check/meta/boolean_constant.hpp>

namespace quan{ namespace concept_check{namespace meta{

   // assert that T is a metafunction
   template <typename T>
   inline
   void boolean_function()
   {
      quan::concept_check::meta::function<T>();
      quan::concept_check::meta::boolean_constant<typename T::type>();
   }

   template <typename T>
   inline
   void true_function()
   {
      quan::concept_check::meta::boolean_function<T>();
      quan::concept_check::meta::true_constant<typename T::type>();
   }

   template <typename T>
   inline
   void false_function()
   {
      quan::concept_check::meta::boolean_function<T>();
      quan::concept_check::meta::false_constant<typename T::type>();
   }

}}}//quan::concept_check::meta


#endif
 
