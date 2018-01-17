#ifndef QUAN_FUSION_MATRIX_ROW_SEQUENCE_HPP_INCLUDED
#define QUAN_FUSION_MATRIX_ROW_SEQUENCE_HPP_INCLUDED

// Copyright Andrew Little 2005
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    sequence representing the rows of a matrix
*/

#include <boost/fusion/support/tag_of_fwd.hpp>
#include <boost/fusion/support/iterator_base.hpp>
#include <boost/fusion/sequence/container/vector.hpp>
#include <boost/fusion/sequence/view/iterator_range.hpp>
#include <quan/fusion/boost/advance_sequence.hpp>
#include <boost/fusion/sequence/conversion/as_vector.hpp>


#include <quan/matrix/rc_matrix_def.hpp>
#include <boost/mpl/int.hpp>

namespace boost{namespace fusion{

    struct col_sequence_tag;

    template<typename Matrix, int N>
    struct col_sequence{
        typedef boost::mpl::int_<N> col_number;
        typedef boost::fusion::col_sequence_tag ftag;
        typedef Matrix matrix_type;
        typedef typename matrix_type::elements elements;
        BOOST_STATIC_ASSERT((N < matrix_type::cols));
        typedef boost::mpl::int_<N> sequence_begin;
        typedef boost::mpl::int_<matrix_type::rows * (matrix_type::cols-1) + N +1> sequence_end;
        typedef boost::mpl::int_<matrix_type::rows> step;
        typedef typename boost::fusion::result_of::begin<
            elements
        >::type matrix_elements_begin;
       
        typedef boost::fusion::advance_iterator<
            typename boost::fusion::result_of::advance<
                matrix_elements_begin,sequence_begin
            >::type,
            step
        > start_iterator;
    
        typedef boost::fusion::advance_iterator<
            typename boost::fusion::result_of::advance<
                matrix_elements_begin,sequence_end
            >::type,
            step
        > end_iterator;
        
        typedef boost::fusion::iterator_range<
            start_iterator,end_iterator
        > range_sequence;
        typedef  typename result_of::as_vector<range_sequence>::type vector_in;
        typedef advance_sequence<vector_in,step> raw_sequence;
       
        typedef typename boost::fusion::result_of::fold<
            raw_sequence,
            vector<>,
            typename result_of::push_back<boost::mpl::_1,boost::mpl::_2>::type
        >::type sequence_type;
           
        col_sequence( Matrix & m) : m_sequence(
            sequence_type(
                fold(
                    raw_sequence(
                        as_vector(
                            range_sequence(
                                start_iterator(advance<sequence_begin>(begin.m.seq)),
                                end_iterator(advance<sequence_end>(begin.m.seq))
                            )
                        )
                    ),
                    vector0(),
                    push_back()
                )
            )
        ){}
        sequence_type m_sequence;
    };

}}//boost::fusion

namespace quan{namespace fusion{

    struct col_sequence_iterator_tag;

    template <typename ColSequence, int Pos>
    struct col_sequence_iterator
     : boost::fusion::iterator_base < col_sequence_iterator<ColSequence,Pos> >{
        typedef ColSequence col_sequence_type;
        typedef boost::mpl::int_<Pos> index;
        typedef col_sequence_iterator_tag ftag;
        typedef boost::fusion::random_access_traversal_tag category;
        col_sequence_iterator(ColSequence & cseq)
        : m_col_sequence(cseq) {}
        ColSequence& m_col_sequence;
    };

}}//quan::fusion


#endif
 