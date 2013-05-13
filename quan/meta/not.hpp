#ifndef QUAN_META_NOT_HPP_INCLUDED
#define QUAN_META_NOT_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/bool.hpp>

namespace quan { namespace meta{

   template <typename T>
   struct not_ : bool_<((T::type::value)==0)>{};
   
}}

#endif
