#ifndef QUAN_BIGINT_BINARY_OPERATION_HPP_INCLUDED
#define QUAN_BIGINT_BINARY_OPERATION_HPP_INCLUDED
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

namespace quan{

   struct big_rational;
   struct bigint;

}

namespace quan{ namespace meta{

   namespace impl {

      template <typename Op>
      struct binary_op_impl<
         quan::bigint,Op, quan::bigint,
         typename quan::where_<
            or_<
               is_additive_operator<Op>,
               is_shift_operator<Op>,
               is_multiplicative_operator<Op>,
               is_bit_operator<Op>
            >
         >::type
      >{
         typedef quan::bigint type;
      };
   } // impl

}}

#endif // QUAN_BIGINT_BINARY_OPERATION_HPP_INCLUDED
