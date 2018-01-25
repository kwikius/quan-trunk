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

namespace quan {namespace fun{

    template <int R, int C, typename Seq>
    struct matrix{
        typedef matrix type;
        const static int rows = R;
        const static int cols = C;
        typedef Seq elements_type;
        Seq elements;
        //check num of elements
        template <int R1, int C1, typename F = as_value>
        struct type_at{
            typedef typename at_seq<
               rows * R1 + C1, Seq, F
            >::type type;
        };  
/*
        matrix():elements(
            typename Seq::t0(),typename Seq::t1(),typename Seq::t2(),
            typename Seq::t3(),typename Seq::t4(),typename Seq::t5(),
            typename Seq::t6(),typename Seq::t7(),typename Seq::t8()
        ){}
        
        template <
            typename T0, typename T1, typename T2, 
            typename T3, typename T4, typename T5,
            typename T6, typename T7, typename T8
        >
        matrix(
            T0 const & t0, T1 const & t1, T2 const & t2,
            T3 const & t3, T4 const & t4, T5 const & t5,
            T6 const & t6, T7 const & t7, T8 const & t8
        )
        : elements(
            t0,t1,t2,
            t3,t4,t5,
            t6,t7,t8
         ){}
*/
        template <typename Seq1>
        matrix (matrix<R,C,Seq1> const & in)
        : elements(in.elements){}


        matrix (Seq const & in )
        : elements(in){}
        
        template <int R1, int C1>
        constexpr 
        typename type_at<R1,C1,as_ref>::type
        at()
        {
           typedef at_seq<rows * R1 + C1,elements_type,as_ref> f;
           return f{}(elements);
        };

        template <int R1, int C1>
        constexpr 
        typename type_at<R1,C1,as_const_ref>::type
        at()const
        {
           typedef at_seq<rows * R1 + C1,elements_type,as_const_ref> f;
           return f{}(elements);
        };
    };
    
}}//quan::fun

#endif
