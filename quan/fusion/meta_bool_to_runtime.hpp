#ifndef QUAN_FUSION_META_BOOL_TO_RUNTIME_HPP_INCLUDED
#define QUAN_FUSION_META_BOOL_TO_RUNTIME_HPP_INCLUDED

#include <quan/fusion/to_runtime.hpp>
#include <quan/meta/bool.hpp>

namespace quan{ namespace fusion{

  namespace impl{

     template <bool B>
     struct to_runtime_impl<
         quan::meta::bool_<B>
     >{
         typedef bool type;
         constexpr type operator()(quan::meta::bool_<B>) const
         {
            return B;
         }
     };
   }
}}

#endif // QUAN_FUSION_META_BOOL_TO_RUNTIME_HPP_INCLUDED
