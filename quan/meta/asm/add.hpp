#ifndef QUAN_META_ASM_ADD_HPP_INCLUDED
#define QUAN_META_ASM_ADD_HPP_INCLUDED

#include <quan/meta/asm/unsigned_add.hpp>
#include <quan/meta/asm/signed_add.hpp>

namespace quan{ namespace meta{ namespace asm_{

   template <typename I, I lhs, I rhs>
   struct add : quan::meta::eval_if<
      std::is_signed<I>,
      signed_add<I,lhs,rhs>,
      unsigned_add<I,lhs,rhs>
   >::type{};
}}}
#endif


