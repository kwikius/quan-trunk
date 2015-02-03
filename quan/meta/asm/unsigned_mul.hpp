#ifndef QUAN_META_ASM_UNSIGNED_MUL_HPP_INCLUDED
#define QUAN_META_ASM_UNSIGNED_MUL_HPP_INCLUDED

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/static_assert.hpp>
#include <type_traits>
#include <quan/meta/asm/lo_nibble.hpp>
#include <quan/meta/asm/hi_nibble.hpp>
#include <quan/meta/asm/extended_reg.hpp>

namespace quan{namespace meta{namespace asm_{

   namespace detail{

      template <typename T, T Lhs, T Rhs>
      struct unsigned_mul_impl{
         static const T low  = lo_nibble<T,Lhs>::value * lo_nibble<T,Rhs>::value;
         static const T midL = lo_nibble<T,Lhs>::value * hi_nibble<T,Rhs>::value;
         static const T midR = hi_nibble<T,Lhs>::value * lo_nibble<T,Rhs>::value;
         static const T hi   = hi_nibble<T,Lhs>::value * hi_nibble<T,Rhs>::value;

         static const T lo_msb_r1 
         = (hi_nibble<T,low>::value) + (lo_nibble<T,midL>::value);

         static const T lo_msb_r2 
         = (lo_nibble<T,lo_msb_r1>::value) + (lo_nibble<T,midR>::value);

         static const T hi_lsb_r1 
         = (lo_nibble<T,hi>::value) + (hi_nibble<T,midL>::value);

         static const T hi_lsb_r2 
         = (lo_nibble<T,hi_lsb_r1>::value) + (hi_nibble<T,midR>::value);
   
         static const T hi_lsb_r3
         = (hi_nibble<T,lo_msb_r1>::value) + (lo_nibble<T,hi_lsb_r2>::value);
   
         static const T hi_lsb_r4 
         = (hi_nibble<T,lo_msb_r2>::value) + (lo_nibble<T,hi_lsb_r3>::value);

         static const T hi_msb_r1 
         = (hi_nibble<T,hi>::value) + (hi_nibble<T,hi_lsb_r1>::value);

         static const T hi_msb_r2 
         = (lo_nibble<T,hi_msb_r1>::value) + (hi_nibble<T,hi_lsb_r2>::value);

         static const T hi_msb_r3 
         = (lo_nibble<T,hi_msb_r2>::value) + (hi_nibble<T,hi_lsb_r3>::value);
    
         static const T hi_msb_r4
         = (lo_nibble<T,hi_msb_r3>::value) + (hi_nibble<T,hi_lsb_r4>::value);
        
         static const T lo_reg 
         = (lo_nibble<T,low>::value) 
          | ((lo_nibble<T,lo_msb_r2>::value) << (nibble_shift<T>::value));
         static const T hi_reg 
         = (lo_nibble<T,hi_lsb_r4>::value) 
          | ((lo_nibble<T,hi_msb_r4>::value) << (nibble_shift<T>::value));

         typedef quan::meta::asm_::extended_reg<T,lo_reg,hi_reg,1> type;

      };

   }//detail

   template <typename T, T Lhs, T Rhs>
   struct  unsigned_mul{
      QUAN_STATIC_ASSERT((std::is_unsigned<T>::value));
      typedef typename detail::unsigned_mul_impl<T,Lhs,Rhs>::type type;
   };

}}}//quan::meta::asm_

#endif

