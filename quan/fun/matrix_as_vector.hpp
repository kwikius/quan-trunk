#ifndef QUAN_FUN_MATRIX_AS_VECTOR_HPP_INCLUDED
#define QUAN_FUN_MATRIX_AS_VECTOR_HPP_INCLUDED

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

   template <typename T, typename Where = void>
   struct get_type_sequence;

   template<typename Matrix>
   struct get_type_sequence<
      Matrix
      ,typename quan::where_<quan::fun::is_fun_matrix<Matrix> >::type
   >
   {
      typedef typename detail::get_matrix_type_sequence_n<
         matrix_row_size<Matrix>::value -1, matrix_col_size<Matrix>::value-1
         ,Matrix
      >::type type;
   };
   
   template <typename Matrix>
   struct as_value_matrix{
      typedef quan::fun::matrix<
          matrix_row_size<Matrix>::value,
          matrix_col_size<Matrix>::value
         ,typename as_vector<
            typename get_type_sequence<Matrix>::type
         >::type
      > type;
   };

   template <typename Matrix>
   struct matrix_as_sequence{
     constexpr matrix_as_sequence(Matrix const & m) : m_matrix{m}{}
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

 //  } // impl

}}

#endif // QUAN_FUN_MATRIX_AS_VECTOR_HPP_INCLUDED
