#ifndef QUAN_ASM_GET_MSB_HPP_INCLUDED
#define QUAN_ASM_GET_MSB_HPP_INCLUDED

#include <quan/meta/numbits.hpp>
#include <type_traits>
#include <quan/where.hpp>
#include <quan/asm/get_bit.hpp>

namespace quan{ namespace asm_{

   template <typename I>
   inline
   typename quan::where_<
      std::is_integral<I>,
      bool 
   >::type
   get_msb( I const val)
   {
     return quan::asm_::get_bit< quan::meta::numbits<I>::value - 1 >(val);
   }
}}

#endif // QUAN_GET_MSB_HPP_INCLUDED
