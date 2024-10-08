#ifndef QUAN_GCD_HPP_INCLUDED
#define QUAN_GCD_HPP_INCLUDED
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

#include <quan/meta/binary_op.hpp>
#include <quan/abs.hpp>

namespace quan {

   namespace detail{

      template <typename TL, typename TR> 
      constexpr 
      typename quan::meta::binary_op<TL,quan::meta::divides,TR>::type
      gcd_impl(TL && n, TR &&  d)
      {
         return ( d == 0)
         ? n
         : gcd_impl(d,n % d );     
      }
   }

   template <typename TL, typename TR> 
   inline constexpr
   typename quan::meta::binary_op<TL,quan::meta::divides,TR>::type 
   gcd(TL const &  n, TR const & d)
   {
      return quan::detail::gcd_impl( quan::abs(n), quan::abs(d) );
   }
}

#endif // QUAN_GCD_HPP_INCLUDED
