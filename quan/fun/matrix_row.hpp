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
#include <quan/meta/int32.hpp>
#include <quan/fun/access_type_seq.hpp>

#include <quan/fun/at_matrix.hpp>
/*
  matrix_row is row N of a matrix
*/

namespace quan{ namespace fun{

    template <int R, typename Matrix>
    struct matrix_row;

    // make it a model of fun_sequence
    template <int R, typename Matrix>
    struct is_fun_sequence_impl<matrix_row<R,Matrix> > : std::true_type{};

    template <int R, typename Matrix>
    struct size_seq_impl<matrix_row<R,Matrix> > : matrix_col_size<Matrix>{};
 
    template<int R, typename Matrix>
    struct matrix_row{
      typedef matrix_row type;
      // calc arg type for constructor
      typedef typename seq_arg_type<Matrix>::type arg_type; 
      typedef typename quan::meta::strip_cr<Matrix>::type matrix_type;
      typedef typename quan::meta::strip_cr<typename matrix_type::elements_type>::type elements_type;
      typedef typename access_type_seq<matrix_type>::type access_type;
      
      arg_type m_matrix;
      constexpr matrix_row(arg_type matrix_in) : m_matrix( matrix_in){}
    };
#if 0
    template <int C, int R, typename Matrix, typename F>
    struct at_seq_impl<C,matrix_row<R,Matrix>,F>{
      typedef at_seq<
         ((Matrix::cols * N) + C ),
         typename Matrix::elements_type,
         F
      > at_seq_type;
      typedef typename at_seq_type::type type;
      // note that the constness of the row seems not to matter here
      // possibly try 
      constexpr 
      typename at_seq_type::type operator()( matrix_row<N,Matrix>const & in)const
      {
         return at_seq_type{}(in.m_matrix.elements);
      }
    };
#else
    template <int C, int R, typename Matrix, typename F>
    struct at_seq_impl<C,matrix_row<R,Matrix>,F>{

        typedef at_matrix<R,C,Matrix,F> at_matrix_type;
        typedef typename at_matrix_type::type type;

         constexpr 
         type operator()( matrix_row<R,Matrix>const & in)const
         {
            return at_matrix_type{}(in.m_matrix);
         }

    };

#endif

}}//quan::fun

#endif
