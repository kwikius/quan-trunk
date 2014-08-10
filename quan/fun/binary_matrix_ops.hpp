#ifndef QUAN_FUN_MATRIX_OPS_HPP_INCLUDED
#define QUAN_FUN_MATRIX_OPS_HPP_INCLUDED

#include <quan/meta/binary_op.hpp>
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/fun/make_matrix_mux_result.hpp>

namespace quan{ namespace fun{

    template <int R, int C, typename Seq> struct matrix;
}}

namespace quan{ namespace meta{

   template <typename MatL, typename MatR>
   struct binary_op<
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

}}//quan::meta::

namespace quan{ namespace fun{

   template <typename MatL, typename MatR>
   inline
   typename quan::where_<
      quan::meta::and_<
         quan::fun::are_fun_matrices<MatL,MatR>,
         std::integral_constant<
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
      typedef quan::fun::detail::eval_matrix_mux_dot<
         const MatL, const MatR
      > matrix_init;
      typedef typename quan::fun::make_matrix_mux_result<
         MatL,MatR
      >::type result_type;
      return result_type(matrix_init(lhs,rhs));
   }
}}

#endif

