#ifndef QUAN_META_ASM_SUB_HPP_INCLUDED
#define QUAN_META_ASM_SUB_HPP_INCLUDED

#include <quan/meta/asm/unsigned_sub.hpp>
#include <quan/meta/asm/signed_sub.hpp>

namespace quan{ namespace meta{ namespace asm_{

   template <typename I, I lhs, I rhs>
   struct sub : quan::meta::eval_if<
      std::is_signed<I>,
      signed_sub<I,lhs,rhs>,
      unsigned_sub<I,lhs,rhs>
   >::type{};
}}}
#endif


