#ifndef QUAN_META_EQ_HPP_INCLUDED
#define QUAN_META_EQ_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/bool.hpp>
namespace quan { namespace meta{

   template <typename T1, typename T2>
   struct eq_ : bool_<((T1::value) == (T2::value))>{};

}}

#endif
