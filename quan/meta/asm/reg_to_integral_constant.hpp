#ifndef QUAN_META_ASM_CONV_REG_TO_INTEGRAL_CONSTANT_HPP_INCLUDED
#define QUAN_META_ASM_CONV_REG_TO_INTEGRAL_CONSTANT_HPP_INCLUDED
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

#include <type_traits>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/sized_unsigned_int.hpp>
#include <quan/meta/sized_signed_int.hpp>
#include <quan/meta/asm/nibble_shift.hpp>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/meta/integer_max.hpp>

namespace quan{ namespace meta{ namespace asm_{

   namespace detail{

      template <typename Reg>
      struct reg_to_unsigned_integral_constant_detail_with_hi_good{
         
         typedef typename quan::meta::sized_unsigned_int<
            (sizeof(typename Reg::value_type) * 2)
         >::type uint_type;
         static const uint_type value 
         = static_cast<uint_type>(Reg::lo_reg) 
            + (static_cast<uint_type>(Reg::hi_reg) << (nibble_shift<uint_type>::value));

         typedef std::integral_constant<uint_type,value> type;
      };
    
      template <typename Reg>
      struct reg_to_unsigned_integral_constant_detail_with_hi 
      : quan::meta::eval_if<
         std::is_integral<
            typename quan::meta::sized_unsigned_int<
               (sizeof(typename Reg::value_type) *2)
            >::type
         >,
         reg_to_unsigned_integral_constant_detail_with_hi_good<Reg>,
         quan::undefined
      >::type{};

      template <typename Reg>
      struct reg_to_unsigned_integral_constant_detail_no_hi 
      : std::integral_constant<typename Reg::value_type, (Reg::lo_reg)>{};

      //reg is signed
      template <typename Reg>
      struct reg_to_unsigned_integral_constant_detail : quan::meta::eval_if_c<
         ((Reg::hi_reg) == 0),
         reg_to_unsigned_integral_constant_detail_no_hi<Reg>,
         reg_to_unsigned_integral_constant_detail_with_hi<Reg>
      >::type{};

      template <typename Reg>
      struct  reg_to_signed_integral_constant_detail_big_good{
         typedef typename quan::meta::sized_unsigned_int<
            (sizeof(typename Reg::value_type) *2)
         >::type uint_type;

         static const uint_type unsigned_value 
         = static_cast<uint_type>(Reg::lo_reg)
             + (static_cast<uint_type>(Reg::hi_reg) << (nibble_shift<uint_type>::value));

         typedef typename quan::meta::unsigned_to_signed<uint_type>::type int_type;
         typedef typename quan::meta::if_c<
            (unsigned_value > (quan::meta::integer_max<int_type>::value)),
            quan::undefined,
            std::integral_constant<
               int_type,( static_cast<int_type>(unsigned_value) * (Reg::sign))
            >
         >::type type;
      };

      template <typename Reg>
      struct  reg_to_signed_integral_constant_detail_big :
      quan::meta::eval_if<
         std::is_integral<
            typename quan::meta::sized_signed_int<
               (sizeof(typename Reg::value_type) *2)
            >::type
         >,
         reg_to_signed_integral_constant_detail_big_good<Reg>,
         quan::undefined
      >::type{};

      template <typename Reg>
      struct  reg_to_signed_integral_constant_detail_small{
         typedef typename quan::meta::unsigned_to_signed<typename Reg::value_type>::type int_type;
         typedef std::integral_constant<int_type,static_cast<int_type>(Reg::lo_reg) * (Reg::sign)> type;
      };

      template <typename Reg>
      struct reg_to_signed_integral_constant_detail : quan::meta::eval_if_c<
         (((Reg::hi_reg) != 0) 
         || ( (Reg::lo_reg) > (quan::meta::integer_max<
               typename quan::meta::unsigned_to_signed<typename Reg::value_type>::type
               >::value))) ,
         reg_to_signed_integral_constant_detail_big<Reg>,
         reg_to_signed_integral_constant_detail_small<Reg>
      >::type{};

   }//detail

      //positive values are unsigned
      //negative values are signed
      //out of range value gives quan::undefined
      template <typename Reg>
      struct convert_reg_to_integral_constant : quan::meta::eval_if_c< 
         ((Reg::sign) < 0),
         detail::reg_to_signed_integral_constant_detail<Reg>,
         detail::reg_to_unsigned_integral_constant_detail<Reg>
      >{};
}}}//quan::meta::asm_
#endif

