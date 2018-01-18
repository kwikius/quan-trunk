#ifndef QUAN_FUSION_TO_RUNTIME_HPP_INCLUDED
#define QUAN_FUSION_TO_RUNTIME_HPP_INCLUDED

#include <cstdint>
#include <quan/meta/is_runtime_type.hpp>
#include <quan/where.hpp>
#include <type_traits>

namespace quan{ namespace fusion{

   namespace impl{

     template <typename T,typename Where = void>
     struct to_runtime_impl;

     template <typename T>
     struct to_runtime_impl<T, typename quan::where_<quan::meta::is_runtime_type<T> >::type> {
         typedef T type;
         constexpr type operator()( T const & t) const 
         {
             return t;
         }
     };
    
   } // impl

   struct to_runtime{

      template<typename T> struct result{
         typedef typename impl::to_runtime_impl<
            typename std::remove_const<
               typename std::remove_reference<
                  T
               >::type
            >::type
        >::type type;
      };

      template <typename T>
      constexpr 
      typename result<T>::type
      operator()( T const & t)
      {
         typedef impl::to_runtime_impl<T> f;
         return f{}(t);
      }
   };
}}

#endif // QUAN_FUSION_TO_RUNTIME_HPP_INCLUDED
