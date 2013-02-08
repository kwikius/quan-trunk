#ifndef QUAN_META_ASM_UNSIGNED_ADD_HPP_INCLUDED
#define QUAN_META_ASM_UNSIGNED_ADD_HPP_INCLUDED

// Copyright Andrew Little 2007. All rights reserved

#include <quan/static_assert.hpp>
#include <type_traits>
#include <quan/meta/asm/lo_nibble.hpp>
#include <quan/meta/asm/hi_nibble.hpp>
#include <quan/meta/asm/extended_reg.hpp>

/*
   unsigned_add returns sum as extended reg hi lo. Always positive
*/
 
namespace quan{ namespace meta{namespace asm_{

   namespace detail{

      template <typename U, U lhs, U rhs>
      struct unsigned_add_impl{
            
         static const U pre_lo_nib_reg = lo_nibble<U,lhs>::value + lo_nibble<U,rhs>::value;
         static const U lo_nib_reg = pre_lo_nib_reg & lo_nibble_mask<U>::value;
         static const bool lo_carry = (pre_lo_nib_reg != lo_nib_reg);
         static const U pre_hi_nib_reg = hi_nibble<U,lhs>::value + hi_nibble<U,rhs>::value + lo_carry;
         static const U hi_nib_reg = pre_hi_nib_reg & lo_nibble_mask<U>::value;

         static const U reg = lo_nib_reg + (hi_nib_reg << nibble_shift<U>::value);
         static const bool carry = (pre_hi_nib_reg != hi_nib_reg);
            
      };
   }

   template <typename U, U lhs, U rhs>
   struct unsigned_add{
      QUAN_STATIC_ASSERT((std::is_unsigned<U>::value));
      typedef detail::unsigned_add_impl<U,lhs,rhs> impl;
      static const U hi = impl::carry?1:0;
      typedef extended_reg<U,impl::reg,hi,1> type;
   };

}}}//quan::meta::asm_

#endif

