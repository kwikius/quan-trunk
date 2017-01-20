#ifndef QUAN_MAX_HPP_INCLUDED
#define QUAN_MAX_HPP_INCLUDED
/*
 Copyright (c) 2003-2015 Andy Little.

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

#if defined max
#warning "undefining max macro"
#undef max
#endif
#include <quan/meta/binary_op.hpp>

namespace quan{

   template <typename TL, typename TR>
   inline
   constexpr 
   typename quan::meta::binary_op<TL,quan::meta::minus,TR>::type 
   max( TL const & lhs, TR const & rhs) 
   {
      typedef typename quan::meta::binary_op<TL,quan::meta::minus,TR>::type result_type;
      return ( lhs > rhs ) ? static_cast<result_type>(lhs):static_cast<result_type>(rhs);
   }

}// quan

#if defined QUAN_CUSTOM_AP_PARAMS
using quan::max;
#endif

#endif // QUAN_MAX_HPP_INCLUDED
