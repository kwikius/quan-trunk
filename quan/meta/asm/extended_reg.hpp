#ifndef QUAN_META_ASM_EXTENDED_REG_HPP_INCLUDED
#define QUAN_META_ASM_EXTENDED_REG_HPP_INCLUDED

namespace quan{namespace meta{namespace asm_{

 template <typename U, U lsb_in, U msb_in, int sign_in >
   struct extended_reg{
      typedef U value_type;
      static const U lo_reg = lsb_in;
      static const U hi_reg = msb_in;
      static const int sign = sign_in;
      typedef extended_reg type;
   };

}}}//quan::meta::asm_

#endif

