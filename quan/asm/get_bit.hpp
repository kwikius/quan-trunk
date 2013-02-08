#ifndef QUAN_ASM_GET_BIT_HPP_INCLUDED
#define QUAN_ASM_GET_BIT_HPP_INCLUDED

#include <quan/meta/numbits.hpp>
#include <type_traits>
#include <quan/where.hpp>

namespace quan{ namespace asm_{

   template <int B, typename I>
   inline
   typename quan::where_<
      std::is_integral<I>,
      bool 
   >::type
   get_bit( I const reg )
   {
      static_assert( B < quan::meta::numbits<I>::value,"Bit out of range");
      static I const bitmask 
      = static_cast<I>( 1 << B  );
      return ( reg & bitmask ) != 0 ;
   }

   template < typename I>
   inline
   typename quan::where_<
      std::is_integral<I>,
      bool 
   >::type
   get_bit( I const reg, int B)
   {
      assert( B < quan::meta::numbits<I>::value);
      I const bitmask 
      = static_cast<I>( 1 << B  );
      return ( reg & bitmask ) != 0 ;
   }

}}

#endif // QUAN_GET_MSB_HPP_INCLUDED
