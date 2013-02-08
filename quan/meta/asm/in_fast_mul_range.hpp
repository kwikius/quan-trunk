#ifndef QUAN_META_ASM_IN_FAST_MUL_RANGE_HPP_INCLUDED
#define QUAN_META_ASM_IN_FAST_MUL_RANGE_HPP_INCLUDED

// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <type_traits>
#include <quan/meta/asm/abs.hpp>
#include <quan/meta/asm/lo_nibble_mask.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/if.hpp>

namespace quan{ namespace meta{ namespace asm_{

template <typename T ,T TL,T TR>
struct in_fast_mul_range_signed {
   static const T abs_lhs = abs<T,TL>::value;
   static const T abs_rhs = abs<T,TR>::value;
   static const T mask = lo_nibble_mask<T>::value;
   typedef quan::meta::bool_<(
   (abs_lhs ==1) || (abs_rhs ==1) || (TL==0) || (TR==0)
   || (
      (abs_lhs <= mask/2)&& (abs_rhs <= mask))
   || (
      (abs_rhs <= mask/2)&& (abs_lhs <= (mask)))
   )> type;
   static const bool value = type::value;
};

template <typename T ,T TL,T TR>
struct in_fast_mul_range_unsigned : quan::meta::bool_<(
   (TL ==1) || (TR==1) || (TL==0) || (TR==0)
   || (
      (TL <= (quan::meta::asm_::lo_nibble_mask<T>::value) +1)
      && 
      (TR <= (quan::meta::asm_::lo_nibble_mask<T>::value))
   ||
      (TL <= (quan::meta::asm_::lo_nibble_mask<T>::value))
      && 
      (TR <= (quan::meta::asm_::lo_nibble_mask<T>::value) +1)
   )
)>{};

template <typename T,T TL,T TR>
struct in_fast_mul_range : quan::meta::if_<
   std::is_signed<T>,
   in_fast_mul_range_signed<T,TL,TR>,
   in_fast_mul_range_unsigned<T,TL,TR>
>::type {};

}}}//quan::meta::asm_

#endif

