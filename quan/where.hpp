#ifndef QUAN_WHERE_HPP_INCLUDED
#define QUAN_WHERE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andy Little 2007

//source, acknowledgements
//--------------
//"C++ Templates The Complete guide, David Vandevoorde and Nicolai M. Josuttis. Section 8.3.1
// Copyright 2003 Pearson Education Inc
//-------------

#include <quan/config.hpp>
#include <quan/where_fwd.hpp>

namespace quan{

   template <bool C, typename T>
   struct where_c{
      typedef T type;
   };

   template <bool C, typename T>
   struct eval_where_c{
      typedef typename T::type type;
   };

   template <typename T>
   struct where_c<false, T>{};

   template <typename T>
   struct eval_where_c<false, T>{};

   template <typename C, typename T >
   struct where_ : where_c<(C::value),T>{};

   template <typename C, typename T >
   struct eval_where : eval_where_c<(C::value),T>{};

   template <typename C,typename T>
   struct where_not : where_c<(!(C::value)),T>{};

   template <typename C,typename T>
   struct eval_where_not : eval_where_c<(!(C::value)),T>{};

}

#endif

