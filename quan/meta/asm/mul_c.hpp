
#ifndef QUAN_META_ASM_MUL_C_HPP_INCLUDED
#define QUAN_META_ASM_MUL_C_HPP_INCLUDED

// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/asm/detail/mul_c_impl.hpp>

namespace quan{ namespace meta{namespace asm_{

   template <typename T, T TL, T TR>
   struct mul_c : quan::meta::if_<
      in_fast_mul_range<T,TL,TR>,
      detail::fast_mul_impl<T,TL,TR>,
      detail::slow_mul_impl<T,TL,TR>
   >::type{};

}}}//quan::meta::asm_

#endif

