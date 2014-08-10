#ifndef QUAN_META_TEST_UNARY_METAFUNCTION_HPP_INCLUDED
#define QUAN_META_TEST_UNARY_METAFUNCTION_HPP_INCLUDED
// Copyright Andrew Little 2006

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <type_traits>

namespace quan{ namespace concept_check{

// assert that T is a unary metafunction
   template <typename T>
   inline
   void UnaryMetafunction()
   {
       typedef typename T::type type;
       static_assert(std::is_same<typename T::type, T>::value, "T is not a model of UnaryMetafunction");
   }

} }//quan::concept_check


#endif
 
