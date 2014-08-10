#ifndef QUAN_META_ASM_LO_NIBBLE_MASK_HPP_INCLUDED
#define QUAN_META_ASM_LO_NIBBLE_MASK_HPP_INCLUDED
// Copyright Andrew Little 2007
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/meta/asm/nibble_shift.hpp>
#include <quan/static_assert.hpp>

namespace quan{ namespace meta{namespace asm_{

   namespace detail{

      template <int N>
      struct lo_nibble_mask_c;

      template<>
      struct lo_nibble_mask_c<1>{
         enum {value = 0x10};
      };

      template<int N>
      struct lo_nibble_mask_c{
         enum {value = 0x10 * (lo_nibble_mask_c<N-1>::value)};
      };
      
   }

   template <typename Int>
   struct lo_nibble_mask
   : std::integral_constant<
      Int, (detail::lo_nibble_mask_c<(size_of<Int>::value)>::value -1)
   >{};
#if (defined QUAN_HAS_LONG_LONG)
   template <>
   struct lo_nibble_mask<long long>
   : std::integral_constant<
      long long , 0xffffffffLL
   >{
      QUAN_STATIC_ASSERT((sizeof(long long) == 8));
   };

   template <>
   struct lo_nibble_mask<unsigned long long>
   : std::integral_constant<
     unsigned long long , 0xffffffffLL
   >{
       QUAN_STATIC_ASSERT((sizeof(long long) == 8));
   };
#endif
}}}//quan::meta::asm_
#endif

