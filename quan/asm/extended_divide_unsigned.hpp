#ifndef QUAN_ASM_EXTENDED_DIVIDE_UNSIGNED_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_DIVIDE_UNSIGNED_HPP_INCLUDED

#include <cstdint>
#include <cassert>
#include <quan/meta/numbits.hpp>
#include <quan/asm/get_bit.hpp>
#include <quan/asm/extended_reg.hpp>

/*
   https://en.wikipedia.org/wiki/Division_algorithm#Long_division
*/

namespace quan{ namespace asm_{

   template <typename T>
   inline
   quan::asm_::extended_reg<T> 
   extended_divide_unsigned ( quan::asm_::extended_reg<T> const & n, T const & d)
   {
      static_assert(std::is_unsigned<T>::value,"");

      if ( n.hi == 0){
         return {T{0},static_cast<T>(n.lo/d),1};
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
         return q;  
      }
   }

}}//quan::asm


#endif // QUAN_ASM_EXTENDED_DIVIDE_UNSIGNED_HPP_INCLUDED
