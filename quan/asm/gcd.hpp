#ifndef QUAN_ASM_GCD_HPP_INCLUDED
#define QUAN_ASM_GCD_HPP_INCLUDED

#include <quan/asm/extended_reg.hpp>
#include <quan/asm/extended_modulus.hpp>

namespace quan{ namespace asm_{

   namespace detail {

      template <typename T>
      inline  
      quan::asm_::extended_reg<T>
      gcd_impl(quan::asm_::extended_reg<T> const & nIn, quan::asm_::extended_reg<T> const & dIn)
      {
      #if 1
         // recursive version useful for constexpr
         return ( dIn == 0)
         ? nIn
         : gcd_impl(dIn, quan::asm_::extended_modulus_unsigned(nIn,dIn) ); 
      #else
         //non recursive version
         auto n = nIn;
         auto d = dIn;
         while ( d != 0){
            auto const temp_d = d;
            d = quan::asm_::extended_modulus_unsigned(n,d);
            n = temp_d;
         }
         return n;
      #endif
      }

   }//detail

   template <typename T>
   inline 
   quan::asm_::extended_reg<T>
   gcd(quan::asm_::extended_reg<T> const & n, quan::asm_::extended_reg<T> const & d)
   {
      typedef quan::asm_::extended_reg<T> ereg;

      return quan::asm_::detail::gcd_impl(
         ereg{n.hi,n.lo,1},
         ereg{d.hi,d.lo,1}
      );
   }

}} // quan::asm_

#endif // QUAN_ASM_GCD_HPP_INCLUDED
