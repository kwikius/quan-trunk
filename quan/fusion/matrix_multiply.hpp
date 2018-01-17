#ifndef QUAN_FUSION_MATRIX_MULTIPLY_HPP_INCLUDED
#define QUAN_FUSION_MATRIX_MULTIPLY_HPP_INCLUDED


// Copyright Andrew Little 2005-2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    multiply two matrices
*/

#define FUSION_MAX_VECTOR_SIZE 20
#include <quan/config.hpp>
#include <boost/fusion/sequence/container/list/cons.hpp>
#include <boost/fusion/algorithm/transformation/reverse.hpp>
#include <quan/fusion/boost/matrix_column_sequence.hpp>
#include <quan/fusion/boost/matrix_row_sequence.hpp>
#include <quan/fusion/dot_product.hpp>
#include <quan/matrix/rc_matrix_def.hpp>
#include <quan/meta/binary_operation.hpp>

namespace quan{ namespace fusion{ namespace detail{
//build the result_type
    template <typename RhsSequence>
    struct push_back_dot_product{
        template <typename LhsSequence,typename InputSequence>
        struct result{
            typedef  boost::fusion::cons<
                typename quan::fusion::dot_product::result<
                    LhsSequence,RhsSequence
                >::type,
                InputSequence
            > type;
        };
    };

    template <typename SeqOfSeq>
    struct fold_seq_of_seq_by_seq{

        template <typename Sequence, typename InputSequence>
        struct result{
            typedef typename boost::fusion::result_of::fold<
                SeqOfSeq,
                InputSequence,
                push_back_dot_product<Sequence>
            >::type type;
        };
    };

    struct matrix_mux_elements{
        template <typename SeqOfSequenceL, typename SeqOfSequenceR>
        struct result{
            typedef fold_seq_of_seq_by_seq<
                typename boost::fusion::result_of::reverse<
                    SeqOfSequenceR
                >::type 
            > const start;
            typedef typename boost::fusion::result_of::fold<
                typename boost::fusion::result_of::reverse<SeqOfSequenceL>::type,
                boost::fusion::nil,
                start
            >::type type; 
        };
    };

    template <int R, int C>
    struct eval_dot{

    template <typename Matrix1, typename Matrix2>
    struct result{
        typedef boost::fusion::matrix_row<Matrix1,R> row;
        typedef boost::fusion::matrix_column<Matrix2,C> col;
        typedef typename row::sequence_type  row_seq;
        typedef typename col::sequence_type  col_seq; 
        typedef typename quan::fusion::dot_product:: template result<
            row_seq,col_seq
        >::type type;
    };

    template <typename Matrix1, typename Matrix2>
    typename result<const Matrix1,const Matrix2>::type
    operator() (Matrix1 const & m1, Matrix2 const & m2) const
    {
        typename result< const Matrix1, const Matrix2>::row row(m1);
        typename result< const Matrix1, const Matrix2>::col col(m2);
        quan::fusion::dot_product dot;
       // std::cout << "<" << R << "," << C << ">\n"; 
        return dot(row.m_sequence,col.m_sequence);
    }
    };

    template <int R, int C, typename Matrix1, typename Matrix2,typename ResultMatrix>
    struct eval_rc;

    template < typename Matrix1, typename Matrix2,typename ResultMatrix>
    struct eval_rc<0,0,Matrix1, Matrix2,ResultMatrix>{

    void operator()(Matrix1 const & m1, Matrix2 const & m2,ResultMatrix & r)const
    {
        eval_dot<0,0> dot;
        r. QUAN_MEMBER_TEMPLATE at<0,0>() = dot(m1,m2);
    }
    };

    template <int R, typename Matrix1, typename Matrix2, typename ResultMatrix>
    struct eval_rc<R,0,Matrix1, Matrix2,ResultMatrix>{

    void operator()(Matrix1 const & m1, Matrix2 const & m2,ResultMatrix & r)const
    {
        eval_rc<R-1,Matrix2::cols-1,Matrix1, Matrix2,ResultMatrix> prev;
        prev(m1,m2,r);
        
        eval_dot<R,0> dot;
        r. QUAN_MEMBER_TEMPLATE at<R,0>() = dot(m1,m2) ;
    }
    };

    template <int R, int C, typename Matrix1, typename Matrix2, typename ResultMatrix>
    struct eval_rc{

    void operator()(Matrix1 const & m1, Matrix2 const & m2,ResultMatrix & r)const
    {
        eval_rc<R,C-1,Matrix1, Matrix2,ResultMatrix> prev;
        prev(m1,m2,r); 

        eval_dot<R,C> dot;
        r. QUAN_MEMBER_TEMPLATE at<R,C>() = dot(m1,m2) ;
    }
    };

// matrix * matrix multiply algorithm

    struct matrix_mux1{

        template <typename Matrix1, typename Matrix2>
        struct result{

            typedef boost::fusion::matrix_row_sequence<Matrix1> seqL;
            typedef boost::fusion::matrix_column_sequence<Matrix2> seqR;
            
            typedef typename boost::fusion::result_of::as_vector<
                typename matrix_mux_elements::template result<seqL,seqR>::type
            >::type elements_type;

            typedef quan::rc_matrix<Matrix1::rows,Matrix2::cols,elements_type> type;
        };

        template <typename Matrix1, typename Matrix2>
        typename result<Matrix1,Matrix2>::type
        operator()(Matrix1 const & m1, Matrix2 const & m2)const
        {
            BOOST_STATIC_ASSERT((Matrix1::cols == Matrix2::rows));
            typedef  typename result<Matrix1,Matrix2>::type result_type;
            eval_rc<
                result_type::rows -1,result_type::cols -1,Matrix1,Matrix2,result_type
            > eval;
            result_type result;
            eval(m1,m2,result);
            return result;
        }
    };

}}}//quan::fusion::detail

namespace quan{namespace meta{

     template <int RL, int CL, typename SeqL,int CR, typename SeqR>
     struct binary_operation<
        quan::rc_matrix<RL,CL,SeqL>,
        quan::meta::times,
        quan::rc_matrix<CL,CR,SeqR>
     >{
        
        typedef typename quan::fusion::detail::matrix_mux1::template result<
            quan::rc_matrix<RL,CL,SeqL>,
            quan::rc_matrix<CL,CR,SeqR>
        >::type type;
    };
    
}}//quan::meta

#if !(defined _MSC_VER && _MSC_VER ==1400 && defined QUAN_SUPPRESS_VC8_ADL_BUG)
QUAN_NS_OPEN 
#endif

    template <int RL, int CL, typename SeqL,int CR, typename SeqR>
    inline
    typename quan::meta::binary_operation<
        quan::rc_matrix<RL,CL,SeqL>,
        quan::meta::times,
        quan::rc_matrix<CL,CR,SeqR>
    >::type
    operator * ( 
        quan::rc_matrix<RL,CL,SeqL> const & lhs,
        quan::rc_matrix<CL,CR,SeqR> const & rhs
    ){
        quan::fusion::detail::matrix_mux1 mux;
        return mux(lhs,rhs);
    }

#if !(defined _MSC_VER && _MSC_VER ==1400 && defined QUAN_SUPPRESS_VC8_ADL_BUG)
QUAN_NS_CLOSE //quan
#endif


#endif
