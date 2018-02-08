#ifndef QUAN_FUN_MATRIX_OPS_HPP_INCLUDED
#define QUAN_FUN_MATRIX_OPS_HPP_INCLUDED
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
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/fun/make_matrix_mux_result.hpp>

namespace quan{ namespace fun{

    template <int R, int C, typename Seq> struct matrix;
}}

namespace quan{ namespace meta{

   namespace impl{

      template <typename MatL, typename MatR>
      struct binary_op_impl<
         MatL, quan::meta::times,MatR,
         typename quan::where_<
            quan::meta::and_<
               quan::fun::are_fun_matrices<MatL,MatR>,
               std::integral_constant<
                  bool,
                  (quan::fun::matrix_col_size<MatL>::value
                  == quan::fun::matrix_row_size<MatR>::value)
               >
            >
         >::type
      > : quan::fun::make_matrix_mux_result<MatL,MatR>{};

   } //impl

}}//quan::meta::

namespace quan{ namespace fun{

   template <typename MatL, typename MatR>
   inline constexpr
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_matrices<MatL,MatR>
         ,std::integral_constant<
            bool,
            (quan::fun::matrix_col_size<MatL>::value
            == quan::fun::matrix_row_size<MatR>::value)
         >
      >,
      typename quan::meta::binary_op<
         MatL,quan::meta::times,MatR
      >::type
   >::type
   operator*(MatL const & lhs, MatR const & rhs)
   {
      typedef quan::fun::detail::matrix_mux_initialiser<
         MatL, MatR
      > initialiser;

     // typedef quan::fun::matrix_initialiser<MatL,quan::meta::times, MatR>::type initialiser;

      typedef typename quan::meta::binary_op<
         MatL,quan::meta::times,MatR
      >::type result_type;
      return result_type{initialiser{lhs,rhs}};
   }
}}

#endif

