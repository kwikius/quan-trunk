#ifndef QUAN_FUN_MATRIX_HPP_INCLUDED
#define QUAN_FUN_MATRIX_HPP_INCLUDED
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
#include <quan/fun/at_matrix.hpp>
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/fun/access_type_seq.hpp>
#include <quan/where.hpp>
#include <utility>

namespace quan {namespace fun{

    template <int R, int C, typename Seq> struct matrix;

    template <int R, int C, typename Seq>
    struct matrix{
        typedef matrix type;
        static constexpr int rows = R;
        static constexpr int cols = C;
        typedef typename access_type_seq<Seq>::type access_type;
        typedef Seq elements_type;
        Seq elements;
        //check num of elements
        template <int R1, int C1, typename F = as_value>
        struct type_at{
            typedef typename at_seq<
               cols * R1 + C1, Seq, F
            >::type type;
        };  

        template <typename Seq1>
        constexpr matrix (matrix<R,C,Seq1> const & in)
        : elements(in.elements){}

        template <typename Seq1>
        constexpr matrix (matrix<R,C,Seq1> & in)
        : elements(in.elements){}

        constexpr matrix (matrix const & in)
        : elements(in.elements){}

        constexpr matrix (Seq const & in )
        : elements(in){}

        matrix & operator = ( matrix const & in)
        {
            elements = in.elements;
            return *this;
        }

        matrix & operator = ( matrix && in)
        {
            elements = in.elements;
            return *this;
        }
        
        matrix (matrix && in )
        : elements(in.elements){}

        template <int R1, int C1>
        constexpr 
        typename quan::where_c< 
            ((R1 < rows) && ( C1 < cols))
           ,typename type_at<R1,C1,as_ref>::type
        >::type
        at() &
        {
           typedef at_seq<cols * R1 + C1,elements_type,as_ref> f;
           return f{}(elements);
        }

        template <int R1, int C1>
        constexpr 
        typename quan::where_c< 
            ((R1 < rows) && ( C1 < cols))
           ,typename type_at<R1,C1,as_const_ref>::type
        >::type
        at()const &
        {
           typedef at_seq<cols * R1 + C1,elements_type,as_const_ref> f;
           return f{}(elements);
        }

        template <int R1, int C1>
        constexpr 
        typename quan::where_c< 
            ((R1 < rows) && ( C1 < cols))
           ,typename type_at<R1,C1,as_value>::type
        >::type
        at()&&
        {
           typedef at_seq<cols * R1 + C1,elements_type,as_const_ref> f;
           return f{}(elements);
        }
    };


   namespace impl {

      template <int R, int C, typename Seq>
      struct is_fun_matrix_impl<matrix<R,C,Seq> >: std::true_type{};

      template <int R, int C, typename Seq>
      struct matrix_row_size_impl<matrix<R,C,Seq> > : std::integral_constant<
         int,(matrix<R,C,Seq>::rows)
      >{};

      template <int R, int C, typename Seq>
      struct matrix_col_size_impl<matrix<R,C,Seq> > : std::integral_constant<
         int,(matrix<R,C,Seq>::cols)
      >{};

   }// impl
    
}}//quan::fun

#endif
