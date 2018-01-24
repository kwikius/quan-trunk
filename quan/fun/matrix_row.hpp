#ifndef QUANTA_MATRIX_ROW_HPP_INCLUDED
#define QUANTA_MATRIX_ROW_HPP_INCLUDED
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

/*
  matrix_row is row N of a matrix
*/

namespace quan{ namespace fun{

    template <int N, typename Matrix>
    struct matrix_row;

    template <int N, typename Matrix>
    struct is_fun_sequence_impl<matrix_row<N,Matrix> > : std::true_type{};

    template <int N, typename Matrix>
    struct size_seq_impl<matrix_row<N,Matrix> > : quan::meta::int32<Matrix::cols>{};
 
    template<int N, typename Matrix>
    struct matrix_row{

      typedef typename Matrix::elements_type::access_type access_type;
      typedef typename seq_arg_type<Matrix>::type arg_type;
      arg_type m_matrix;
      matrix_row(arg_type matrix_in) : m_matrix( matrix_in){}
    };

    template <int I, int N, typename Matrix, typename F>
    struct at_seq_impl<I,matrix_row<N,Matrix>,F>{
      typedef at_seq<
         ((Matrix::cols * N) +I),
         typename Matrix::elements_type,
         as_value
      > at_seq_type;

      typedef at_seq<
         ((Matrix::cols * N) +I),
         typename Matrix::elements_type,
         as_ref
      > at_seq_ref_type;

      typedef at_seq<
         ((Matrix::cols * N) +I),
         typename Matrix::elements_type,
         as_const_ref
      > at_seq_const_ref_type;

      typedef typename at_seq_type::type type;
   
      typename at_seq_const_ref_type::type operator()( matrix_row<N,Matrix>const & in)const
      {
         at_seq_const_ref_type at;
         return at(in.m_matrix.elements);
      }

      typename at_seq_ref_type::type operator()( matrix_row<N,Matrix>& in)const
      {
         at_seq_const_ref_type at;
         return at(in.m_matrix.elements);
      }
      
    };

}}//quan::fun

#endif
