#ifndef QUAN_META_MAX_HPP_INCLUDED
#define QUAN_META_MAX_HPP_INCLUDED

#include <quan/meta/float_max.hpp>
#include <quan/meta/integer_max.hpp>

#ifndef __AVR__
#include <type_traits>
#else
#include <quan/std/tr1/is_integral.hpp>
#include <quan/std/tr1/is_float.hpp>
#endif

namespace quan{namespace meta{ 

   namespace detail{

      template <typename T, typename Where = void>
      struct max_;

      template<
         typename T
      > struct max_<T,
         typename quan::where_<std::is_integral<T> >::type
      > : integer_max<T>{};
      
       template<
         typename T
      > struct max_<T,
         typename quan::where_<std::is_floating_point<T> >::type
      > : float_max<T>{};
   }

   template <typename T>
   struct max_ : quan::meta::detail::max_<T>{};
}}

#endif // QUAN_META_MAX_HPP_INCLUDED
