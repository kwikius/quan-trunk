#ifndef QUAN_FUN_MAKE_MATRIX_MUX_RESULT_HPP_INCLUDED
#define QUAN_FUN_MAKE_MATRIX_MUX_RESULT_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/meta/type_sequence.hpp>
#include <quan/fun/matrix.hpp>
#include <quan/fun/dot_product_seq.hpp>
#include <quan/fun/as_vector.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/seq_arg_type.hpp>

namespace quan{ namespace fun{

   namespace detail{

       template<int R, int C, typename Matrix1, typename Matrix2>
       struct matrix_mux_row_col_result{
            typedef quan::fun::matrix_row<R,const Matrix1> row;
            typedef quan::fun::matrix_col<C,const Matrix2> col;
            typedef typename quan::fun::dot_product_seq:: template result<
               row,col
            >::type type;
       };

       template <typename Matrix1, typename Matrix2>
       struct matrix_mux_initialiser{

         template <int R, int C>
         struct result{
            typedef typename quan::fun::detail::matrix_mux_row_col_result<
               R,C,Matrix1,Matrix2
            >::type type;
         };
         typedef typename quan::meta::strip_cr<Matrix1>::type lhs_type;
         typedef typename quan::meta::strip_cr<Matrix2>::type rhs_type;

       //  typedef typename seq_arg_type<Matrix1>::type lhs_type;
        // typedef typename seq_arg_type<Matrix2>::type rhs_type;

         static constexpr int rows = matrix_row_size<Matrix1>::value;
         static constexpr int cols = matrix_col_size<Matrix2>::value;
         typedef quan::fun::as_value access_type;

         constexpr matrix_mux_initialiser(lhs_type const & lhs_in, rhs_type const & rhs_in)
         :lhs{lhs_in},rhs{rhs_in}{}

         lhs_type const & lhs;
         rhs_type const & rhs;
       };

   }//detail

   template <typename Matrix1, typename Matrix2>
   struct is_fun_sequence_impl<
      detail::matrix_mux_initialiser<Matrix1,Matrix2> 
   > : std::true_type{};

   template <typename Matrix1, typename Matrix2>
   struct size_seq_impl<
      detail::matrix_mux_initialiser<Matrix1,Matrix2> 
   >{
      typedef detail::matrix_mux_initialiser<Matrix1,Matrix2> mat_init;
   
      static constexpr int value = mat_init::rows * mat_init::cols;
   };

   template <int I,typename Matrix1, typename Matrix2, typename F>
   struct at_seq_impl<
      I,
      detail::matrix_mux_initialiser<Matrix1,Matrix2>,
      F
   >{
      
      typedef detail::matrix_mux_initialiser<Matrix1,Matrix2> mat_init;
   
      static constexpr int row_pos = (I / mat_init::cols);
      static constexpr int col_pos = (I % mat_init::cols);

      typedef quan::fun::matrix_row<row_pos,const Matrix1> row_type;
      typedef quan::fun::matrix_col<col_pos,const Matrix2> col_type;

      typedef typename mat_init::template result<row_pos,col_pos>::type type;

      constexpr 
      type operator()(mat_init const & in)const
      {
          typedef quan::fun::dot_product_seq dot;
          return dot{}(row_type{in.lhs},col_type{in.rhs});
      }
   };

   namespace detail{

      template <int R, int C, typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n;

      template < typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n<0,0,Matrix1, Matrix2>{
         typedef typename quan::fun::detail::matrix_mux_row_col_result<0,0,Matrix1, Matrix2>::type result_type;
         typedef quan::meta::type_sequence<result_type> type;
      };

      template <int R, typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n<R,0,Matrix1, Matrix2>{
         typedef typename make_matrix_mux_result_n<R-1,Matrix2::cols-1,Matrix1,Matrix2>::type prev_type;
         typedef typename quan::fun::detail::matrix_mux_row_col_result<R,0,Matrix1, Matrix2>::type result_type;
         typedef typename quan::meta::push_back<prev_type,result_type>::type type;
      };

      template <int R, int C, typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n{
         typedef typename make_matrix_mux_result_n<R,C-1,Matrix1,Matrix2>::type prev_type;
         typedef typename quan::fun::detail::matrix_mux_row_col_result<R,C,Matrix1, Matrix2>::type result_type;
         typedef typename quan::meta::push_back<prev_type,result_type>::type type;
      };
      
   }//detail
   
   template <typename Matrix1, typename Matrix2>
   struct make_matrix_mux_result{
 
      typedef typename detail::make_matrix_mux_result_n<
         Matrix1::rows -1,Matrix2::cols-1,
         Matrix1,Matrix2
      >::type meta_elements_type;

      typedef quan::fun::matrix<
         Matrix1::rows,Matrix2::cols
         ,typename as_vector<meta_elements_type>::type
      > type;
   };
   
}}//quan::fun
#endif
