#ifndef QUAN_FUN_MATRIX_AS_SEQUENCE_HPP_INCLUDED
#define QUAN_FUN_MATRIX_AS_SEQUENCE_HPP_INCLUDED

#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/matrix.hpp>

namespace  quan { namespace fun {

   template <typename Matrix>
      struct matrix_as_sequence{
      static_assert(quan::fun::is_fun_matrix<Matrix>::value,"");
      constexpr matrix_as_sequence(Matrix const & m) : m_matrix{m}{}
      typedef matrix_as_sequence type;
      typedef quan::fun::as_value access_type;
      Matrix const & m_matrix;
   };

   template <typename Matrix>
   struct is_fun_sequence_impl<quan::fun::matrix_as_sequence<Matrix> > : std::true_type{};

   template <typename Matrix>
   struct size_seq_impl<quan::fun::matrix_as_sequence<Matrix> > 
   : quan::meta::int32<(matrix_row_size<Matrix>::value * matrix_col_size<Matrix>::value)>{};

   template <int I, typename AtF, typename Matrix>
   struct at_seq_impl<I,quan::fun::matrix_as_sequence<Matrix>,AtF>{
      static_assert(quan::fun::is_fun_matrix<Matrix>::value,"");
      typedef quan::fun::matrix_as_sequence<Matrix> mat_seq_type;
      static constexpr int row_pos = (I / matrix_col_size<Matrix>::value);
      static constexpr int col_pos = (I % matrix_col_size<Matrix>::value);

      typedef typename quan::fun::at_matrix<row_pos,col_pos,Matrix, as_value>::type type;

      constexpr type operator()(mat_seq_type const & mat_seq) const
      {
         typedef quan::fun::at_matrix<row_pos,col_pos,Matrix, as_value> fun;
         return fun{}(mat_seq.m_matrix);
      }
   };

}}

#endif // QUAN_FUN_MATRIX_AS_SEQUENCE_HPP_INCLUDED
