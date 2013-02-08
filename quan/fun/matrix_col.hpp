#ifndef QUAN_FUN_MATRIX_COL_HPP_INCLUDED
#define QUAN_FUN_MATRIX_COL_HPP_INCLUDED

#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/seq_arg_type.hpp>

namespace quan{ namespace fun{

    template <int N, typename Matrix>
    struct matrix_col;

    template <int N, typename Matrix>
    struct is_fun_sequence_impl<matrix_col<N,Matrix> > : std::true_type{};

    template <int N, typename Matrix>
    struct size_seq_impl<matrix_col<N,Matrix> > : quan::meta::int32<Matrix::rows>{};
 
    template<int N, typename Matrix>
    struct matrix_col{
      typedef typename Matrix::elements_type::access_type access_type;
      typedef typename seq_arg_type<Matrix>::type arg_type;
      arg_type m_matrix;
      matrix_col(arg_type matrix_in) : m_matrix( matrix_in){}
    };

    template <int I, int N, typename Matrix, typename F>
    struct at_seq_impl<I,matrix_col<N,Matrix>,F>{
      typedef at_seq<
         (N + Matrix::cols *I),
         typename Matrix::elements_type,
         as_value
      > at_seq_type;

      typedef at_seq<
         (N + Matrix::cols *I),
         typename Matrix::elements_type,
         as_ref
      > at_seq_ref_type;

         typedef at_seq<
         (N + Matrix::cols *I),
         typename Matrix::elements_type,
         as_const_ref
      > at_seq_const_ref_type;

      typedef typename at_seq_type::type type;
   
      typename at_seq_const_ref_type::type operator()( matrix_col<N,Matrix>const & in)const
      {
         at_seq_const_ref_type at;
         return at(in.m_matrix.elements);
      }

      typename at_seq_ref_type::type operator()( matrix_col<N,Matrix>& in)const
      {
         at_seq_ref_type at;
         return at(in.m_matrix.elements);
      }
      
    };

   /* template<int N, typename Matrix>
    struct matrix_col<N,Matrix,F,3> : of_vector::vector3<
        typename of_vector::at_c<N ,F>::template result<typename Matrix::elements_type>::type,
        typename of_vector::at_c<(N + Matrix::cols),F>::template result<typename Matrix::elements_type>::type,
        typename of_vector::at_c<(N + Matrix::cols * 2) ,F>::template result<typename Matrix::elements_type>::type,
        F
    >{
        typedef of_vector::vector3<
            typename of_vector::at_c<N,F>::template result<typename Matrix::elements_type>::type,
            typename of_vector::at_c<(N + Matrix::cols),F>::template result<typename Matrix::elements_type>::type,
            typename of_vector::at_c<(N + Matrix::cols * 2),F>::template result<typename Matrix::elements_type>::type,
            F
        > vector_type;
        matrix_col(Matrix & m) : vector_type(
            of_vector::at_c<
                N,
                typename of_vector::detail::seq_compatible_ref<Matrix>::type
            >()(m.elements),
            of_vector::at_c<
                (N + Matrix::cols),
                typename of_vector::detail::seq_compatible_ref<Matrix>::type
            >()(m.elements),
            of_vector::at_c<
                (N + Matrix::cols * 2),
                typename of_vector::detail::seq_compatible_ref<Matrix>::type
            >()(m.elements)
        ){}
        
    };*/

}}

#endif
