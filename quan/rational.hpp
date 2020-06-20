#ifndef QUAN_RATIONAL_HPP_INCLUDED
#define QUAN_RATIONAL_HPP_INCLUDED

#include <cstdint>
#include <cassert>
#include <type_traits>
#include <quan/meta/numbits.hpp>
#include <quan/gcd.hpp>
#include <quan/asm/gcd.hpp>
#include <quan/asm/get_bit.hpp>
#include <quan/asm/extended_mul.hpp>
#include <quan/asm/extended_divide.hpp>
#include <quan/asm/extended_modulus.hpp>

namespace quan{

   /*
      rational which doesnt overflow with intmax_t
      Much todo yet though
      currently only for unsigned
   */

   template <typename T>
   struct rational{
      // todo allow signed eventually
      static_assert(std::is_unsigned<T>::value,"");
      typedef T int_type;
      constexpr rational(): num{static_cast<T>(0U)},den{static_cast<T>(1U)}{}
      constexpr rational(rational const &) = default;
      constexpr rational(rational &&) = default;
      constexpr rational(T const & n, T const & d) 
      : num{static_cast<T>(n / quan::gcd(n,d))},
        den{static_cast<T>(d / quan::gcd(n,d))}{}

      T num;
      T den;

      friend rational operator * (rational const & lhs, rational const & rhs)
      {
         auto const n0 = quan::asm_::extended_mul(lhs.num,rhs.num); 
         auto const d0 = quan::asm_::extended_mul(lhs.den,rhs.den);
         auto const gcd0 = gcd(n0,d0);

         auto const n = extended_divide_unsigned(n0,gcd0);
         auto const d = extended_divide_unsigned(d0,gcd0);

         assert( (n.hi == 0) && (d.hi == 0) );
         return {n.lo,d.lo};
      }
   };
} // quan

#endif // QUAN_RATIONAL_HPP_INCLUDED
