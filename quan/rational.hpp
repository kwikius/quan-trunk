#ifndef QUAN_RATIONAL_HPP_INCLUDED
#define QUAN_RATIONAL_HPP_INCLUDED

/*
   requires c++20 ?
*/

#include <cstdint>
#include <cassert>
#include <type_traits>

#include <quan/meta/numbits.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/max.hpp>
#include <quan/sign.hpp>
#include <quan/abs.hpp>
#include <quan/gcd.hpp>

#include <quan/asm/gcd.hpp>
#include <quan/asm/get_bit.hpp>
#include <quan/asm/extended_mul.hpp>
#include <quan/asm/extended_divide.hpp>

namespace quan{

   /*
      rational which  can use full size of T without overflow

      TODO optimisation :  if ( 2*sizeof(T)) <= sizof(intmax_t)
      then use larger type not extended reg
   */

   template <typename T>
   struct rational{
      typedef T int_type;
      constexpr rational()
      :  num{static_cast<T>(0U)},
         den{static_cast<T>(1U)}{}
      constexpr rational(rational const &) = default;
      constexpr rational(rational &&) = default;
      constexpr rational(T const & n, T const & d) 
      :  num{static_cast<T>((n * quan::sign(d)) / quan::gcd(n,d))},
         den{static_cast<T>(quan::abs(d) / quan::gcd(n,d))}
      {}
      constexpr rational & operator=(rational const &) = default;
      constexpr rational & operator=(rational &&) = default;

      constexpr T nume() const { return num;}
      constexpr T denom() const { return den;}

      T num;
      T den;
private:
      friend constexpr rational abs( rational const & in)
      {
         return rational{quan::abs(in.num),in.den};
      }

      friend constexpr int sign(rational const & in) 
      {
         return quan::sign(in.num);
      }

      static constexpr rational
      ll_multiply(rational const & lhs, rational const & rhs)
      {
         // unsigned ----------------------
         typedef typename quan::meta::to_unsigned<T>::type uT;

         auto const n0 = quan::asm_::extended_mul(static_cast<uT>(lhs.num),static_cast<uT>(rhs.num)); 
         auto const d0 = quan::asm_::extended_mul(static_cast<uT>(lhs.den),static_cast<uT>(rhs.den));
         auto const gcd0 = gcd(n0,d0);

         auto const n = extended_divide_unsigned(n0,gcd0);
         auto const d = extended_divide_unsigned(d0,gcd0);
         //unsigned----------------------------

         assert( (n.hi == 0) && "overflow in result numerator");
         assert( (d.hi == 0) && "overflow in result denominator");
         assert( (n.lo <= static_cast<uT>(quan::meta::max_<T>::value)) && "overflow in result numerator" );
         assert( (d.lo <= static_cast<uT>(quan::meta::max_<T>::value)) && "overflow in result denominator");

         return {static_cast<T>(n.lo),static_cast<T>(d.lo)};
      }

      friend constexpr rational operator * (rational const & lhs, rational const & rhs)
      {
         rational const abs_res = ll_multiply(abs(lhs),abs(rhs));
         return {
            static_cast<T>(abs_res.num * sign(lhs) * sign(rhs)),abs_res.den
         }; 
      }

   };
} // quan

#endif // QUAN_RATIONAL_HPP_INCLUDED
