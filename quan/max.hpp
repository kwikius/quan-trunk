#ifndef QUAN_MAX_HPP_INCLUDED
#define QUAN_MAX_HPP_INCLUDED
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


#if defined QUAN_CUSTOM_AP_PARAMS
#include <AP_HAL_Quan/ap_param_archetype.hpp>
#include <quan/meta/strip_cr.hpp>
#endif
#include <quan/meta/binary_op_if.hpp>
#include <quan/meta/is_valid_binary_op.hpp>

#if defined max
#warning "undefining max macro"
#undef max
#endif

#if 1

namespace quan{
   template <typename TL, typename TR>
   inline
   constexpr auto max ( TL const & lhs, TR const & rhs) -> decltype( lhs > rhs ? lhs:rhs)
   {
      return ( lhs > rhs ) ? lhs:rhs;
   }

}// quan
#else

namespace quan{

   template <typename TL, typename TR>
   inline
   constexpr typename quan::meta::binary_op_if<
      quan::meta::is_valid_binary_op<TL,quan::meta::minus,TR>,
      TL, quan::meta::minus, TR
   >::type
   max( TL const & lhs, TR const & rhs)
   {
      typedef typename quan::meta::binary_op<
         TL, quan::meta::minus, TR
      >::type result_type;
      return (( lhs > rhs ) ? result_type{lhs}:result_type{rhs});
   }

#if defined QUAN_CUSTOM_AP_PARAMS

   template <typename TL, typename TR>
   inline
   constexpr auto
   max ( TL const & lhs, TR const & rhs) 
   -> typename quan::meta::binary_op_if<
      quan::meta::and_<
         quan::is_model_of<AP_Param_Archetype, TL>,
         quan::meta::is_valid_binary_op<
            typename quan::meta::strip_cr<decltype(lhs.get())>::type,quan::meta::less,TR
         >
      >,
      typename quan::meta::strip_cr<decltype(lhs.get())>::type, quan::meta::minus, TR
   >::type
   {
      return quan::max( lhs.get(), rhs );
   }

   template <typename TL, typename TR>
   inline constexpr auto max (TL const & lhs, TR const& rhs)
   -> typename quan::meta::binary_op_if<
      quan::meta::and_<
         quan::is_model_of<AP_Param_Archetype, TR>,
         quan::meta::is_valid_binary_op<
            TL,quan::meta::less,typename quan::meta::strip_cr<decltype(rhs.get())>::type
         >
      >,
      TL,quan::meta::minus, typename quan::meta::strip_cr<decltype(rhs.get())>::type
   >::type
   {
      return quan::max( lhs, rhs.get() );
   }

#endif

}//quan

#endif

#if defined QUAN_CUSTOM_AP_PARAMS
using quan::max;
#endif

#endif
