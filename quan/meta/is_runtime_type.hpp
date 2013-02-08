#ifndef QUAN_META_IS_RUNTIME_TYPE_HPP_INCLUDED
#define QUAN_META_IS_RUNTIME_TYPE_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

//#include <type_traits>
#include <quan/meta/bool/true.hpp>
namespace quan{ namespace meta{

   template <typename T>
   struct is_runtime_type : true_{};
      
}}

#endif
