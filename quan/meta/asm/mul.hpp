#ifndef QUAN_META_ASM_MUL_HPP_INCLUDED
#define QUAN_META_ASM_MUL_HPP_INCLUDED

#include <quan/meta/asm/unsigned_mul.hpp>
#include <quan/meta/asm/signed_mul.hpp>

namespace quan{ namespace meta{ namespace asm_{

   template <typename I, I lhs, I rhs>
   struct mul : quan::meta::eval_if<
      std::is_signed<I>,
      signed_mul<I,lhs,rhs>,
      unsigned_mul<I,lhs,rhs>
   >::type{};
}}}
#endif


