#ifndef QUAN_META_EVAL_IF_HPP_INCLUDED
#define QUAN_META_EVAL_IF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace meta{
   
   template <bool B, typename TrueFunction, typename FalseFunction>
   struct eval_if_c{
      typedef typename TrueFunction::type type;
   };

   template <typename TrueFunction,typename FalseFunction>
   struct eval_if_c<false,TrueFunction,FalseFunction> {
      typedef typename FalseFunction::type type;
   };

   template<typename C, typename TrueFunction, typename FalseFunction>
   struct eval_if : eval_if_c<((C::type::value)!=0),TrueFunction,FalseFunction>{};
   
}}//quan::meta

#endif
