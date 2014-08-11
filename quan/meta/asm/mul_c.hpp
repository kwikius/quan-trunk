
#ifndef QUAN_META_ASM_MUL_C_HPP_INCLUDED
#define QUAN_META_ASM_MUL_C_HPP_INCLUDED

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

#include <quan/meta/asm/detail/mul_c_impl.hpp>

namespace quan{ namespace meta{namespace asm_{

   template <typename T, T TL, T TR>
   struct mul_c : quan::meta::if_<
      in_fast_mul_range<T,TL,TR>,
      detail::fast_mul_impl<T,TL,TR>,
      detail::slow_mul_impl<T,TL,TR>
   >::type{};

}}}//quan::meta::asm_

#endif

