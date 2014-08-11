#ifndef QUAN_ASM_GET_BIT_HPP_INCLUDED
#define QUAN_ASM_GET_BIT_HPP_INCLUDED
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
