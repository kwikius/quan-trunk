#ifndef QUAN_META_ASM_DETAIL_MUL_C_IMPL_HPP_INCLUDED
#define QUAN_META_ASM_DETAIL_MUL_C_IMPL_HPP_INCLUDED

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
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/asm/in_fast_mul_range.hpp>
#include <quan/meta/asm/unsigned_mul.hpp>
#include <quan/meta/asm/abs.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <type_traits>
#include <type_traits>
#include <quan/static_assert.hpp>

namespace quan{ namespace meta{namespace asm_{

   namespace detail{

      // result regs unsigned
      template <typename T, T TL, T TR>
      struct fast_mul_impl_unsigned{
         QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
         static const T lo_reg = TL * TR;
         static const T hi_reg = 0;
         static const bool positive = true;
         typedef fast_mul_impl_unsigned type;
      };
      // result regs unsigned
      // check sign
      template <typename T, T TL, T TR>
      struct fast_mul_impl_signed{
         QUAN_STATIC_ASSERT((std::is_signed<T>::value));
         static const T signed_lo_reg = TL * TR;
         static const bool positive = signed_lo_reg >= 0;
         typedef typename signed_to_unsigned<T>::type unsigned_type;
         static const unsigned_type lo_reg = asm_::abs<T,signed_lo_reg>::value;
         static const unsigned_type hi_reg = 0;
         typedef fast_mul_impl_signed type;
      };

      template <typename T, T TL, T TR>
      struct fast_mul_impl : quan::meta::eval_if<
         std::is_signed<T>,
         fast_mul_impl_signed<T,TL,TR>,
         fast_mul_impl_unsigned<T,TL,TR>
      >::type{};
      

      template <typename T, T TL, T TR>
      struct slow_mul_impl_unsigned{
         QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
          typedef typename unsigned_mul<T,TL,TR>::type mul;
          static const T lo_reg = mul::lo_reg;
          static const T hi_reg = mul::hi_reg;
          static const bool positive = true;
         typedef slow_mul_impl_unsigned type;
      };
      
     
      template <typename T, T TL, T TR>
      struct slow_mul_impl_signed{
         QUAN_STATIC_ASSERT((std::is_signed<T>::value));
         typedef typename signed_to_unsigned<T>::type U;
         static const U UL = asm_::abs<T,TL>::value;
         static const U UR = asm_::abs<T,TR>::value;

         //typedef  mul<U,UL,UR> mul;
         typedef typename unsigned_mul<T,TL,TR>::type mul;
         static const U lo_reg = mul::lo_reg;
         static const U hi_reg = mul::hi_reg;
         static const bool tl_positive = ( TL >=0 );
         static const bool tr_positive = ( TR >=0 );
         static const bool positive = (tl_positive == tr_positive);
         typedef slow_mul_impl_signed type;
      };

      template <typename T, T TL, T TR>
      struct slow_mul_impl : quan::meta::eval_if<
         std::is_signed<T>,
         slow_mul_impl_signed<T,TL,TR>,
         slow_mul_impl_unsigned<T,TL,TR>
      >::type{};
      
   }//detail

}}}//quan::meta::asm_

#endif

