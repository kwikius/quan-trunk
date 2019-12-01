#ifndef QUAN_FUN_GET_MATRIX_TYPE_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_GET_MATRIX_TYPE_SEQUENCE_HPP_INCLUDED

#include <quan/fun/matrix.hpp>
#include <quan/fun/as_vector.hpp>

#include <quan/meta/type_sequence.hpp>

namespace quan{ namespace fun{

      namespace detail{

      template <int R, int C, typename Matrix>
      struct get_matrix_type_sequence_n;

      template <typename Matrix>
      struct get_matrix_type_sequence_n<0,0,Matrix>{
         typedef typename quan::fun::at_matrix<0,0,Matrix>::type result_type;
         typedef quan::meta::type_sequence<result_type> type;
      };

      template <int R, typename Matrix>
      struct get_matrix_type_sequence_n<R,0,Matrix>{
         typedef typename get_matrix_type_sequence_n<R-1,matrix_col_size<Matrix>::value-1,Matrix>::type prev_type;
         typedef typename quan::fun::at_matrix<R,0,Matrix>::type result_type;
         typedef typename quan::meta::push_back<prev_type,result_type>::type type;
      };

      template <int R, int C, typename Matrix>
      struct get_matrix_type_sequence_n{
         typedef typename get_matrix_type_sequence_n<R,C-1,Matrix>::type prev_type;
         typedef typename quan::fun::at_matrix<R,C,Matrix>::type result_type;
         typedef typename quan::meta::push_back<prev_type,result_type>::type type;
      };
      
   }//detail

}} // quan::fun

#endif // QUAN_FUN_GET_MATRIX_TYPE_SEQUENCE_HPP_INCLUDED
