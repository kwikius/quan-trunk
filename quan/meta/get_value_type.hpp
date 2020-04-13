#ifndef QUAN_META_GET_VALUETYPE_HPP_INCLUDED1
#define QUAN_META_GET_VALUETYPE_HPP_INCLUDED1

#include <quan/config.hpp>
#include <quan/where.hpp>
#include <quan/meta/strip_cr.hpp>
#if defined QUAN_USE_QUAN_STD_TR1
#include <quan/std/tr1/is_arithmetic.hpp>
#else
#include <type_traits>
#endif

namespace quan{ namespace meta{

   namespace impl{

      template <typename T, typename Where = void>
      struct get_value_type_impl {
         typedef typename T::value_type type;
      };

      template<typename T>
      struct get_value_type_impl<T,typename quan::where_<std::is_arithmetic<T> >::type>
      {
         typedef T type;
      };

      template<typename T>
      struct get_value_type_impl<T,typename quan::where_<std::is_enum<T> >::type>
      {
         typedef T type;
      };
   }

   template <typename T>
   struct get_value_type : impl::get_value_type_impl<typename quan::meta::strip_cr<T>::type>{};

   template <typename T,unsigned int N>
   struct get_value_type<T[N]>{
      typedef T type;
   };
}}

#endif //QUAN_META_GET_VALUETYPE_HPP_INCLUDED