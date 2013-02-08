#ifndef QUAN_META_NEQ_HPP_INCLUDED
#define QUAN_META_NEQ_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <type_traits>
#include <quan/meta/eq.hpp>
#include <quan/meta/not.hpp>

namespace quan { namespace meta{

   template <typename T1, typename T2>
   struct neq_ : not_<eq_<T1,T2> >{};
   
}}

#endif
