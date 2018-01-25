#ifndef QUAN_FUN_MATRIX_COL_HPP_INCLUDED
#define QUAN_FUN_MATRIX_COL_HPP_INCLUDED
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

#include <quan/fun/at_seq.hpp>
#include <quan/fun/size_seq.hpp>
#include <quan/fun/is_fun_sequence.hpp>
#include <quan/fun/seq_arg_type.hpp>
#include <quan/fun/access_type_seq.hpp>

namespace quan{ namespace fun{

    template <int N, typename Matrix>
    struct matrix_col;

    template <int N, typename Matrix>
    struct is_fun_sequence_impl<matrix_col<N,Matrix> > : std::true_type{};

    template <int N, typename Matrix>
    struct size_seq_impl<matrix_col<N,Matrix> > : quan::meta::int32<Matrix::rows>{};
 
    template<int N, typename Matrix>
    struct matrix_col{

      typedef matrix_col type;
      typedef typename seq_arg_type<Matrix>::type arg_type;
      typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
      typedef typename quan::meta::strip_cr<typename matrix_type::elements_type>::type elements_type;
      typedef typename access_type_seq<matrix_type>::type access_type;
      
      arg_type m_matrix;
      matrix_col(arg_type matrix_in) : m_matrix( matrix_in){}
    };
#if 0
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
#endif

    template <int I, int N, typename Matrix, typename F>
    struct at_seq_impl<I,matrix_col<N,Matrix>,F>{
      typedef at_seq<
         (N + Matrix::cols *I),
         typename Matrix::elements_type,
         F
      > at_seq_type;
      typedef typename at_seq_type::type type;
      // note that the constness of the row seems not to matter here
      // possibly try 
      constexpr 
      typename at_seq_type::type operator()( matrix_col<N,Matrix>const & in)const
      {
         return at_seq_type{}(in.m_matrix.elements);
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
