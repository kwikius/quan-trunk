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
//#include <quan/fun/matrix33.hpp>
//#include <quan/fun/matrix44.hpp>
#include <quan/fun/matrix.hpp>
#include <quan/fun/dot_product_seq.hpp>
#include <quan/fun/push_back_seq.hpp>
#include <quan/fun/as_vector.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fun/matrix_row.hpp>
#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/seq_arg_type.hpp>

namespace quan{ namespace fun{

   namespace detail{
   
       template <typename Matrix1, typename Matrix2>
       struct eval_matrix_mux_dot{

      // at_seq<N,eval.. > --> at<  N/cols , N %cols >
         typedef typename seq_arg_type<Matrix1>::type lhs_type;
         typedef typename seq_arg_type<Matrix2>::type rhs_type;
         lhs_type m1;
         rhs_type m2;
         static constexpr int rows = Matrix1::rows;
         static constexpr int cols = Matrix2::cols;
         typedef quan::fun::as_value access_type;

         constexpr eval_matrix_mux_dot(lhs_type m1_in, rhs_type m2_in)
         :m1{m1_in},m2{m2_in}{}

         template <int R, int C>
         struct result{
            typedef quan::fun::matrix_row<R,Matrix1> row;
            typedef quan::fun::matrix_col<C,Matrix2> col;
            typedef typename quan::fun::dot_product_seq:: template result<
               row,col
            >::type type;
         };
       
         template <int R, int C>
         constexpr 
         typename result<R,C>::type 
         eval() const
         {
            typedef typename result<R,C>::row row;//(m1);
            typedef typename result<R,C>::col col;//(m2);
            typedef quan::fun::dot_product_seq dot;
            return dot{}(row{m1},col{m2});
         }
       };

   }//detail

   template <typename Matrix1, typename Matrix2>
   struct is_fun_sequence_impl<
      detail::eval_matrix_mux_dot<Matrix1,Matrix2> 
   > : std::true_type{};

   template <typename Matrix1, typename Matrix2>
   struct size_seq_impl<
      detail::eval_matrix_mux_dot<Matrix1,Matrix2> 
   >{
      typedef detail::eval_matrix_mux_dot<Matrix1,Matrix2> mat_init;
   
      static constexpr int value = mat_init::rows * mat_init::cols;
   };

   template <int I,typename Matrix1, typename Matrix2, typename F>
   struct at_seq_impl<
      I,
      detail::eval_matrix_mux_dot<Matrix1,Matrix2>,
      F
   >{
      
      typedef detail::eval_matrix_mux_dot<Matrix1,Matrix2> mat_init;
   
      static constexpr int row_pos = (I / mat_init::cols);
      static constexpr int col_pos = (I % mat_init::cols);

      typedef typename mat_init::template result<row_pos,col_pos>::type type;

      typedef typename mat_init::template result<row_pos,col_pos>::row row_type;
      typedef typename mat_init::template result<row_pos,col_pos>::col col_type;
      constexpr 
      type operator()(mat_init const & in)const
      {
          typedef quan::fun::dot_product_seq dot;
          return dot{}(row_type{in.m1},col_type{in.m2});
      }
   };

   template <typename Matrix1, typename Matrix2>
   struct matrix_initialiser{
      
      typedef detail::eval_matrix_mux_dot<Matrix1,Matrix2> elements_type;
      typedef typename seq_arg_type<Matrix1>::type lhs_type;
      typedef typename seq_arg_type<Matrix2>::type rhs_type;
      const static int rows = elements_type::rows;
      const static int cols = elements_type::cols;
      elements_type elements;
      constexpr 
      matrix_initialiser(lhs_type m1, rhs_type m2)
      :elements{m1,m2}{}
      typedef matrix_initialiser type;
   };
   
   namespace detail{

      template <int R, int C, typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n;

      template < typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n<0,0,Matrix1, Matrix2>{
         typedef typename eval_matrix_mux_dot<Matrix1,Matrix2>::template result<0,0>::type result_type;
         typedef typename push_back_seq<result_type,nil>::type type;
      };

      template <int R, typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n<R,0,Matrix1, Matrix2>{
         typedef typename make_matrix_mux_result_n<R-1,Matrix2::cols-1,Matrix1,Matrix2>::type prev_type;
         typedef typename eval_matrix_mux_dot<Matrix1,Matrix2>::template result<R,0>::type result_type;
         typedef typename push_back_seq<result_type,prev_type>::type type;
      };

      template <int R, int C, typename Matrix1, typename Matrix2>
      struct make_matrix_mux_result_n{
         typedef typename make_matrix_mux_result_n<R,C-1,Matrix1,Matrix2>::type prev_type;
         typedef typename eval_matrix_mux_dot<Matrix1,Matrix2>::template result<R,C>::type result_type;
         typedef typename quan::fun::push_back_seq<result_type,prev_type>::type type;
      };
      
   }//detail
   
   template <typename Matrix1, typename Matrix2>
   struct make_matrix_mux_result{
 
      typedef typename detail::make_matrix_mux_result_n<
         Matrix1::rows -1,Matrix2::cols-1,
         Matrix1,Matrix2
      >::type cons_type;
      typedef typename as_vector<cons_type>::type elements_type;
      typedef quan::fun::matrix<Matrix1::rows,Matrix2::cols,elements_type> type;
   };
   
}}//quan::fun
#endif
