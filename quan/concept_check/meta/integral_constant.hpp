#ifndef QUAN_CONCEPT_CHECK_META_INTEGRAL_CONSTANT_HPP_INCLUDED
#define QUAN_CONCEPT_CHECK_META_INTEGRAL_CONSTANT_HPP_INCLUDED
// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/concept_check/meta/identity_function.hpp>

namespace quan{ namespace concept_check{ namespace meta{

// assert that T is a integral_constant
   template <typename T>
   inline
   void integral_constant()
   {
      quan::concept_check::meta::identity_function<T>();
      static const int64_t value = T::value;
   }

}}}//quan::concept_check::meta


#endif
 