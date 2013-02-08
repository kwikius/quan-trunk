#ifndef QUAN_ASM_EXTENDED_SUB_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_SUB_HPP_INCLUDED

#include <quan/asm/nibble.hpp>
#include <quan/static_assert.hpp>
#include <type_traits>
#include <quan/meta/signed_unsigned.hpp>
#include <quan/asm/extended_reg.hpp>

namespace quan{ namespace asm_{

   template <typename T>
   inline 
   extended_reg<T> extended_sub_unsigned(T lhs, T rhs)
   {
       QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
       extended_reg<T> res;
       res.hi =0;
       if ( lhs >= rhs){
           res.lo = lhs - rhs;
           res.sign = extended_reg<T>::positive;
       }
       else{
          res.lo = rhs - lhs;
          res.sign = extended_reg<T>::negative;
       }  
       return res;
   }

}}//quan::asm_

#endif

