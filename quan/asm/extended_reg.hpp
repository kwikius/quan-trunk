#ifndef QUAN_ASM_EXTENDED_REG_HPP_INCLUDED
#define QUAN_ASM_EXTENDED_REG_HPP_INCLUDED

namespace quan{ namespace asm_{

   template <typename T>
   struct extended_reg{
      enum sign_enum{ undefined =0, positive = 1,negative = -1};
      T lo;
      T hi;
      int sign; // 1 == +, -1 == -
   };

}}//quan::asm_

#endif
