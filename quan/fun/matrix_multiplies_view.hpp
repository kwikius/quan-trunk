#ifndef QUAN_FUN_MATRIX_MULTIPLIES_VIEW_HPP_INCLUDED
#define QUAN_FUN_MATRIX_MULTIPLIES_VIEW_HPP_INCLUDED

#include <quan/config.hpp>
#include <quan/concepts/fusion/matrix.hpp>
#include <quan/fun/seq_arg_type.hpp>
#include <quan/fun/dot_product_seq.hpp>
#include <quan/fun/as_vector.hpp>
#include <quan/fun/matrix_col.hpp>
#include <quan/fun/matrix_row.hpp>

namespace quan{ namespace fun{

   template <typename MatrixL, typename MatrixR, typename Where = void>
   struct multiplies_view;

   template <typename MatrixL, typename MatrixR>
   struct multiplies_view<
      MatrixL, MatrixR,
      typename quan::where_<
         quan::meta::and_<
            quan::fun::are_fun_matrices<MatrixL,MatrixR>
            ,quan::meta::bool_<
               (quan::fun::matrix_col_size<MatrixL>::value
               == quan::fun::matrix_row_size<MatrixR>::value)
            >
         >   
      >::type
   >{
      typedef multiplies_view type;
      typedef typename seq_arg_type<MatrixL>::type lhs_type;
      typedef typename seq_arg_type<MatrixR>::type rhs_type;

      static constexpr int rows = quan::fun::matrix_row_size<MatrixL>::value;
      static constexpr int cols = quan::fun::matrix_col_size<MatrixR>::value;

      typedef quan::fun::as_value access_type;

      constexpr multiplies_view(lhs_type lhs_in, rhs_type rhs_in)
      :lhs{lhs_in},rhs{rhs_in}{}

      lhs_type lhs;
      rhs_type rhs;

      template <int R, int C, typename F = as_value>
      struct type_at{
         typedef quan::fun::matrix_row<R,MatrixL> row_type;
         typedef quan::fun::matrix_col<C,MatrixR> col_type;
         typedef typename quan::fun::dot_product_seq:: template result<
            row_type,col_type
         >::type type;
      };

      template <int R, int C>
      constexpr 
      typename quan::where_c< 
          ((R < rows) && ( C < cols))
           ,typename type_at<R,C,as_value>::type
      >::type
      at() const
      {
         typedef typename type_at<R,C,as_value>::row_type row_type;
         typedef typename type_at<R,C,as_value>::col_type col_type;
         typedef quan::fun::dot_product_seq dot;
         return dot{}(row_type{lhs},col_type{rhs});
      }
   };

   namespace impl {

      template <typename ML, typename MR>
      struct is_fun_matrix_impl<quan::fun::multiplies_view<ML,MR> >: std::true_type{};

      template <typename ML, typename MR>
      struct matrix_row_size_impl<quan::fun::multiplies_view<ML,MR> > : quan::fun::matrix_row_size<ML>{};

      template <typename ML, typename MR>
      struct matrix_col_size_impl<quan::fun::multiplies_view<ML,MR> > : quan::fun::matrix_col_size<MR>{};

   }// impl
}}


#endif // QUAN_FUN_MATRIX_MULTIPLIES_VIEW_HPP_INCLUDED
