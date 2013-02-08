#ifndef QUAN_FUN_MATRIX44_HPP_INCLUDED
#define QUAN_FUN_MATRIX44_HPP_INCLUDED

#include <quan/fun/vector4.hpp>
#include <quan/fun/vector16.hpp>
#include <quan/fun/is_fun_matrix.hpp>
#include <quan/meta/and.hpp>

namespace quan {namespace fun{

      template <int R, int C, typename Seq> struct matrix;

      template <int R, int C, typename Seq>
      struct is_fun_matrix<matrix<R,C,Seq> >: std::true_type{};

      template <int R, int C, typename Seq>
      struct matrix_row_size<matrix<R,C,Seq> > : std::integral_constant<
         int,(matrix<R,C,Seq>::rows)>{};

      template <int R, int C, typename Seq>
      struct matrix_col_size<matrix<R,C,Seq> > : std::integral_constant<
         int,(matrix<R,C,Seq>::cols)>{};

    template<typename Seq>
    struct matrix<4,4,Seq>{
        typedef matrix type;
        const static int rows = 4;
        const static int cols = 4;
        typedef Seq elements_type;
        Seq elements;
        //check num of elements
        template <int R1, int C1, typename F = as_value>
        struct type_at{
            typedef typename at_seq<
               rows * R1 + C1, Seq, F
            >::type type;
        };  

        matrix():elements(
            typename Seq::t0(),typename Seq::t1(),typename Seq::t2(),typename Seq::t3(),
            typename Seq::t4(),typename Seq::t5(),typename Seq::t6(),typename Seq::t7(),
            typename Seq::t8(),typename Seq::t9(),typename Seq::t10(),typename Seq::t11(),
            typename Seq::t12(),typename Seq::t13(),typename Seq::t14(),typename Seq::t15()
        ){}
        
        template <
         typename T0,typename T1,typename T2,typename T3,
         typename T4,typename T5,typename T6,typename T7,
         typename T8,typename T9,typename T10,typename T11,
         typename T12,typename T13,typename T14,typename T15
        >
        matrix(
            T0 const & t0, T1 const & t1, T2 const & t2,T3 const & t3,
            T4 const & t4, T5 const & t5,T6 const & t6, T7 const & t7, 
            T8 const & t8, T9 const & t9, T10 const & t10, T11 const & t11,
            T12 const & t12, T13 const & t13, T14 const & t14, T15 const & t15
        )
        : elements(
            t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15
         ){}

        template <typename Matrix1>
        matrix (Matrix1 const & in,
         typename quan::where_<
            quan::fun::is_fun_matrix<Matrix1>,
            void*
          >::type =0)
        : elements(in.elements){}
      
        template <typename Seq1>
        explicit  matrix (Seq1 const & in, 
         typename quan::where_<
            quan::fun::is_fun_sequence<Seq1>,
            void*
          >::type =0
        )
        : elements(in){}
        
        
        template <int R1, int C1>
        typename type_at<R1,C1,as_ref>::type
        at()
        {
            at_seq<rows * R1 + C1,elements_type,as_ref> f;
            return f(elements);
        };

        template <int R1, int C1>
        typename type_at<R1,C1,as_const_ref>::type
        at()const
        {
            at_seq<rows * R1 + C1,elements_type,as_const_ref> f;
            return f(elements);
        };
    };
    
}}//quan::fun

#endif
