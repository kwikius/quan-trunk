#ifndef QUAN_META_STATIC_NUMERIC_CONCEPT_HPP_INCLUDED
#define  QUAN_META_STATIC_NUMERIC_CONCEPT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    StaticNumeric concept
*/
#include <quan/meta/bool.hpp>
#include <quan/meta/not.hpp>
namespace quan{namespace meta{

    template <typename T>
    struct eq_zero : bool_<((T::value) ==0)>{};
    
    template <typename T>
    struct neq_zero : not_<eq_zero<T> >{};

    template <typename T>
    struct eq_one : bool_<((T::value) ==1)>{};
    
    template <typename T>
    struct neq_one : not_<eq_one<T> >{};

   template <typename T>
   struct lt_zero : bool_<((T::value) < 0)>{};
   
   template <typename T>
   struct gt_zero : bool_<((T::value) > 0)>{};

   template <typename T>
   struct gte_zero : bool_<((T::value) >= 0)>{};
   
   template <typename T>
   struct lte_zero : bool_<((T::value) <= 0)>{};
    
}}

#endif
