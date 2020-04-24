#ifndef QUAN_THREE_D_MAKE_VECT_HPP_INCLUDED
#define QUAN_THREE_D_MAKE_VECT_HPP_INCLUDED

#include <quan/meta/strip_cr.hpp>
#include <quan/three_d/vect.hpp>

namespace quan{ namespace three_d{

   template <typename T>
   inline constexpr
   quan::three_d::vect<T>
   make_vect( T && x, T&& y, T&& z)
   {
      return {x,y,z};
   }

   template <typename T>
   inline constexpr
   quan::three_d::vect<T>
   make_vect( T const& x, T const& y, T const& z)
   {
      return {x,y,z};
   }

}}

#endif // QUAN_THREE_D_MAKE_VECT_HPP_INCLUDED
