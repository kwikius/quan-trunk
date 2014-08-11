#ifndef QUAN_META_ASM_SIGNED_MUL_HPP_INCLUDED
#define QUAN_META_ASM_SIGNED_MUL_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/meta/asm/unsigned_mul.hpp>
#include <type_traits>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/asm/abs.hpp>

namespace quan{ namespace meta{ namespace asm_{

   namespace detail{
      template <typename T, T lhs, T rhs>
      struct signed_mul_impl{
         
         typedef typename quan::meta::signed_to_unsigned<T>::type unsigned_type;

         static const int lhs_sign = (lhs >=0)?1:-1;
         static const int rhs_sign = (rhs >=0)?1:-1;

         static const int sign = lhs_sign * rhs_sign;

         static const unsigned_type lhs_ 
         = static_cast<unsigned_type>(quan::meta::asm_::abs<T,lhs>::value);

         static const unsigned_type rhs_ 
         = static_cast<unsigned_type>(quan::meta::asm_::abs<T,rhs>::value);

         typedef typename unsigned_mul<unsigned_type,lhs_,rhs_>::type unsigned_mul_reg;

         typedef quan::meta::asm_::extended_reg<
            unsigned_type,
            unsigned_mul_reg::lo_reg,
            unsigned_mul_reg::hi_reg,
            sign
         > type;

      };
   }

   template <typename T, T lhs, T rhs>
   struct signed_mul {
      QUAN_STATIC_ASSERT((std::is_signed<T>::value));
      typedef typename quan::meta::asm_::detail::signed_mul_impl<T,lhs,rhs>::type type;
   };
   
}}}
#endif

