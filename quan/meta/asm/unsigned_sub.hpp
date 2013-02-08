#ifndef QUAN_META_ASM_UNSIGNED_SUB_HPP_INCLUDED
#define QUAN_META_ASM_UNSIGNED_SUB_HPP_INCLUDED

// Copyright Andrew Little 2007. All rights reserved

#include <quan/static_assert.hpp>
#include <type_traits>
#include <quan/meta/asm/lo_nibble.hpp>
#include <quan/meta/asm/hi_nibble.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/asm/extended_reg.hpp>

/*
   unsigned_sub returns extended reg as abs(diff(lhs,rhs)) with sign
*/

namespace quan{ namespace meta{namespace asm_{

   namespace detail{

      template <typename U, U lhs, U rhs>
      struct unsigned_sub_impl{

         static const int sign = ( rhs <= lhs)?1:-1;
         static const U lhs_ = (sign >0)?lhs:rhs;
         static const U rhs_ = (sign >0)?rhs:lhs;
         static const U value = lhs_ - rhs_;
         typedef quan::meta::asm_::extended_reg<U,value,0,sign> type;
      };
   }

   template <typename U, U lhs, U rhs>
   struct unsigned_sub{
      QUAN_STATIC_ASSERT((std::is_unsigned<U>::value));
      typedef typename detail::unsigned_sub_impl<U,lhs,rhs>::type type;
     // typedef extended_reg<U,impl::value,0,impl::sign> type;
      
   };

}}}//quan::meta::asm_

#endif

