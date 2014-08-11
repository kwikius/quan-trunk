#ifndef QUAN_META_ASM_ADD_HPP_INCLUDED
#define QUAN_META_ASM_ADD_HPP_INCLUDED
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

#include <quan/meta/asm/unsigned_add.hpp>
#include <quan/meta/asm/signed_add.hpp>

namespace quan{ namespace meta{ namespace asm_{

   template <typename I, I lhs, I rhs>
   struct add : quan::meta::eval_if<
      std::is_signed<I>,
      signed_add<I,lhs,rhs>,
      unsigned_add<I,lhs,rhs>
   >::type{};
}}}
#endif


