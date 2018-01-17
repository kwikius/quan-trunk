#ifndef QUAN_FUSION_DOT_PRODUCT_HPP_INCLUDED
#define QUAN_FUSION_DOT_PRODUCT_HPP_INCLUDED

// Copyright Andrew Little 2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.


/*
    functor for dot_product of two input fusion::sequences
*/

#include <quan/operators/binary_operator_functors.hpp>
#include <quan/fusion/swap_args.hpp>
#include <quan/meta/static_numeric_concept.hpp>
#include <quan/fusion/static_value/static_value.hpp>
#include <boost/fusion/sequence/container/vector.hpp>
#include <boost/fusion/sequence/conversion/as_vector.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
#include <boost/fusion/algorithm/transformation/transform.hpp>
#include <boost/fusion/algorithm/iteration/fold.hpp>
#include <boost/fusion/sequence/view/iterator_range.hpp>
#include <boost/ref.hpp>

namespace quan{ namespace fusion{

    namespace detail{
        
        template <typename T>
        struct zero_of{
            typedef quan::fusion::static_value< T, quan::meta::rational<0> > type;
        };

        template <typename R, typename S>
        struct zero_of<
            quan::fusion::static_value<R,S>
        >{
            typedef typename quan::fusion::static_value<
                R, quan::meta::rational<0> 
            > type;
        };
            
        template <typename SeqL, typename SeqR>
        struct result_of_dot_product{
            typedef  typename boost::fusion::result_of::transform<
                    SeqL,SeqR,quan::operator_times
                >::type raw_multiplied_sequence;
            typedef  typename boost::fusion::result_of::as_vector<
                raw_multiplied_sequence
            >::type multiplied_sequence;
            
            typedef typename boost::fusion::result_of::fold<
                multiplied_sequence,
                typename zero_of<
                    typename boost::fusion::result_of::value_at_c<multiplied_sequence,0>::type
                >::type ,
                quan::fusion::swap_args<quan::operator_plus>
            >::type type;

        };
        struct rt_dot_product{
            template <typename SeqL, typename SeqR>
            typename result_of_dot_product<SeqL, SeqR>::type
            operator()(SeqL const & lhs, SeqR const & rhs)const
            {   /*  
                typedef typename result_of_dot_product<
                    const SeqL,const SeqR
                >::raw_multiplied_sequence multiplied_seq_type;
                multiplied_seq_type  mult = boost::fusion::transform(lhs,rhs,quan::operator_times());
               
                typedef typename result_of_dot_product<SeqL,SeqR>::type result_type;
                
                typedef typename boost::fusion::result_of::next<
                    typename boost::fusion::result_of::begin<multiplied_seq_type>::type
                >::type next_type;
                
                typedef typename boost::fusion::result_of::end<
                    multiplied_seq_type
                >::type end_type;
                typedef boost::fusion::iterator_range<next_type,end_type> range_type;
                range_type range_minus_first = range_type(
                    boost::fusion::next(boost::fusion::begin(mult)),
                    boost::fusion::end(mult)
                );
                // static values may be passed in and need to
                // be converted for the result_type
                quan::fusion::to_runtime runtime;
                result_type result = runtime(boost::fusion::deref(boost::fusion::begin(mult)));
               // std::cout <<  "-------------\n";
               // std::cout << typeid(result).name() <<'\n';
               // std::cout << 
               // typeid( boost::fusion::deref(boost::fusion::begin(mult))).name() <<'\n';
                boost::fusion::fold(
                    range_minus_first,
                    boost::ref(result),
                    quan::fusion::swap_args<quan::operator_plus_equals>()
                );
                return result;
                */
                
                 //alternative "functional" version
                    // may actually be quicker... needs testing
                typedef typename result_of_dot_product<SeqL,SeqR>::type result_type;
                return  boost::fusion::fold(
                    boost::fusion::transform(lhs,rhs,quan::operator_times()),
                    result_type(0),
                    quan::fusion::swap_args<quan::operator_plus>()
                );
            } 
            typedef rt_dot_product type;  
        };
        struct ct_dot_product{
            template <typename SeqL, typename SeqR>
            typename result_of_dot_product<SeqL,SeqR>::type
            operator()(SeqL const &, SeqR const& )const
            {
                return typename result_of_dot_product<SeqL,SeqR>::type();
            }   
            typedef ct_dot_product type;
        };
    }

    struct dot_product{
        
        template <typename SeqL, typename SeqR>
        struct result{
            typedef typename detail::result_of_dot_product<SeqL,SeqR>::type type;
            // sort actual add func to use here
            // if result is static,job should be done here.
            typedef typename  boost::mpl::if_<
                quan::fusion::is_static_value<type>,
                detail::ct_dot_product,
                detail::rt_dot_product
            >::type function;     
        };
        
        template <typename SeqL, typename SeqR>
        typename result<SeqL,SeqR>::type
        operator()(SeqL const & lhs, SeqR const & rhs)const
        {
            typename result<SeqL,SeqR>::function f;
            return f(lhs,rhs);
        }   
    };

    struct lazy_dot_product{
        


    };
}}//quan::fusion


#endif
