#ifndef QUAN_FUSION_SWAP_ARGS_HPP_INCLUDED
#define QUAN_FUSION_SWAP_ARGS_HPP_INCLUDED

// Copyright Andrew Little 2006
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    swap args of a function Only done for 2 arg function so far.
*/

#include <quan/fusion/num_args.hpp>
#include <quan/fusion/static_value/static_value_def.hpp>
#include <boost/ref.hpp>

namespace quan{namespace fusion{

    namespace detail{
    
        template <typename F, bool IsAssignmentFunction>
        struct swap_2_args;
        
        template <typename BinaryFunction>
        struct swap_2_args<BinaryFunction,false>{

            template <typename Rhs, typename Lhs>
            struct result{
                typedef typename BinaryFunction:: template result<
                    Rhs,Lhs
                >::type type;
            };
            template <typename Rhs, typename Lhs>
            typename result<Rhs,Lhs>::type
            operator()( Rhs const & rhs, Lhs const & lhs )const
            {
                BinaryFunction f;
                return f(lhs,rhs);
            }
        };
        
        template <typename AssignmentFunction>
        struct swap_2_args<AssignmentFunction,true>{

            template <typename Rhs, typename Lhs>
            struct result{
                BOOST_MPL_ASSERT((boost::is_reference_wrapper<Lhs>));
                BOOST_MPL_ASSERT((boost::mpl::not_<
                    boost::is_const<typename Lhs::type> 
                >));
                typedef Lhs type;
            };
            template <typename Rhs, typename Lhs>
            typename result<Rhs,Lhs>::type
            operator()( Rhs const & rhs, Lhs  lhs)const
            {
                quan::fusion::to_runtime to_runtime;
                AssignmentFunction f;
                return boost::ref(f(lhs.get(),to_runtime(rhs)));
            }
        };
        
        template <typename F, int N>
        struct swap_args;
        template <typename F>
        struct swap_args<F,2> : swap_2_args<
            F, 
            quan::meta::is_assignment_operator<typename F::operator_key>::value
        >{};
    
    }//detail
    
    template <typename F> struct swap_args : detail::swap_args<
        F,
        num_args<F>::value
    >{};

}}//quan::fusion

#endif

