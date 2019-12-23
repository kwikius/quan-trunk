#ifndef QUAN_MATH_TO_POWER_HPP_INCLUDED
#define QUAN_MATH_TO_POWER_HPP_INCLUDED

#include <quan/math/to_power_impl.hpp>
#include <quan/math/root.hpp>

namespace quan{

   template <int64_t N, typename Float>
   constexpr inline
   typename std::enable_if< std::is_floating_point<Float>::value, Float>::type
   to_power(Float const & v)
   {
      return impl::to_power_impl<N>(v);
   }

   template <int N, int D, typename Float>
   inline constexpr
   typename std::enable_if< std::is_floating_point<Float>::value, Float>::type
   to_power( Float const & v)
   {
      return quan::root<D>(quan::to_power<N>(v));
   }

} // quan

#endif