#ifndef QUAN_TWO_D_MAKE_VECT_HPP_INCLUDED
#define QUAN_TWO_D_MAKE_VECT_HPP_INCLUDED

#include <quan/meta/strip_cr.hpp>
#include <quan/two_d/vect.hpp>

namespace quan{ namespace two_d{

   template <typename T>
   inline constexpr
   vect<T>
   make_vect( T && x, T && y)
   {
      return {x,y};
   }

   template <typename T>
   inline constexpr
   vect<T>
   make_vect( T const& x, T const& y)
   {
      return {x,y};
   }

}}

#endif // QUAN_TWO_D_MAKE_VECT_HPP_INCLUDED
