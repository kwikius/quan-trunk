#ifndef QUAN_ASM_EXTENDED_MODULUS_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_MODULUS_HPP_INCLUDED

#include <cstdint>
#include <cassert>
#include <quan/meta/numbits.hpp>
#include <quan/asm/get_bit.hpp>
#include <quan/asm/extended_reg.hpp>

/*
   https://en.wikipedia.org/wiki/Division_algorithm#Long_division
*/

namespace quan{ namespace asm_{

   /*
      T is an unsigned type
      extended_reg is assumed positive
      result always positive
   */

   template <typename T>
   inline
   quan::asm_::extended_reg<T> 
   extended_modulus_unsigned ( quan::asm_::extended_reg<T> const & n, T const & d)
   {
      static_assert(std::is_unsigned<T>::value,"");
     // std::cout << "umu1\n";
      if ( n.hi == 0){
         return {T{0},static_cast<T>(n.lo%d),1};
      }else{

         quan::asm_::extended_reg<T> q; // quotient
         quan::asm_::extended_reg<T> r; // remainder

         int constexpr msb = quan::meta::numbits<T>::value * 2 - 1;

         for (int i = msb ; i >= 0 ; --i){
            r.shift_left();
            if( n.get_bit(i)  ){
               r.lo |= 1;
            }
            if( r >= d){
               r -= d;
               q.set_bit(i);
            }
         }
         return r;  
      }
   }

   /*
      T is an unsigned type
      extended_reg n , d  are assumed positive
      result always positive
   */

   template <typename T>
   inline
   quan::asm_::extended_reg<T> 
   extended_modulus_unsigned ( quan::asm_::extended_reg<T> const & n, quan::asm_::extended_reg<T> const & d)
   {
      static_assert(std::is_unsigned<T>::value,"");
     // std::cout << "umu\n";
      if (d.hi == 0){
         return extended_modulus_unsigned(n,d.lo);
      }else{

         quan::asm_::extended_reg<T> q; // quotient
         quan::asm_::extended_reg<T> r; // remainder

         int constexpr msb = quan::meta::numbits<T>::value * 2 - 1;

         for (int i = msb ; i >= 0 ; --i){
            r.shift_left();
            if( n.get_bit(i)  ){
               r.lo |= 1;
            }
            if( r >= d){
               r -= d;
               q.set_bit(i);
            }
         }
         return r;  
      }
   }

   // signed using extended_reg<unsigned_type> / signed_type

}}//quan::asm

#endif // QUAN_ASM_EXTENDED_MODULUS_HPP_INCLUDED
