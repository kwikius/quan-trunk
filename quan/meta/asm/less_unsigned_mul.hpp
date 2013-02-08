
#ifndef QUAN_META_ASM_LESS_UNSIGNED_MUL_HPP_INCLUDED
#define QUAN_META_ASM_LESS_UNSIGNED_MUL_HPP_INCLUDED

// Copyright Andrew Little 2007

#include <quan/meta/bool.hpp>

namespace quan{ namespace meta{ namespace asm_{

   // use with mulregs
   template <typename MulL,typename MulR>
   struct less_unsigned_mul : quan::meta::bool_<
      (
         ((MulL::hi_reg) < (MulR::hi_reg))? true
         : (((MulL::hi_reg) > (MulR::hi_reg))? false 
         : (MulL::lo_reg) < (MulR::lo_reg))
      )
   >{
      //QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
   };

}}}//quan::meta::asm_

#endif

