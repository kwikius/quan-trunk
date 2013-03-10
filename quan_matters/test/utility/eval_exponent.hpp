#ifndef QUAN_META_EVAL_EXPONENT_HPP_INCLUDED
#define QUAN_META_EVAL_EXPONENT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
Only used by testing
    evaluate a rational as an exponent to base 10
*/

#include <quan_matters/test/utility/coherent_exponent.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/digits10.hpp>
#ifndef __AVR__
#include <limits>
#else
#include <limits.h>
#endif

namespace quan{ namespace meta{namespace detail{

template <typename Exponent,typename ResultType, bool Negate>
struct pos_neg_eval_exponent;

// dont negate and return exp
template <typename Exponent, typename ResultType>
struct pos_neg_eval_exponent<Exponent, ResultType,false>
{
    typedef typename quan::detail::coherent_exponent<
         Exponent::numerator, Exponent::denominator
    >::template eval<
       ResultType
    > eval;
    ResultType operator()()
    {
       eval ev;
       ResultType  result = ev(); 
       return result;
    }
};

//negate and return 1/exp
template <typename Exponent, typename ResultType>
struct pos_neg_eval_exponent<Exponent, ResultType,true>
{
    typedef typename quan::detail::coherent_exponent<
         Exponent::numerator, Exponent::denominator
    >::template eval<
       ResultType
    > eval;
    
    ResultType operator()()
    {
       eval ev;
       ResultType  result = 1 / ev(); 
       return result;
    }
};

template <typename Exponent>
struct eval_exponent_impl {

    const static bool reverse_calc 
    = lt_<
        Exponent,
        quan::meta::rational<0>
    >::value;
  
    typedef typename if_c<
        reverse_calc,
        typename quan::meta::unary_operation<
            quan::meta::negate,
            Exponent
        >::type,
        Exponent            
    >::type exponent;

    typedef typename quan::detail::coherent_exponent<
         exponent::numerator, exponent::denominator
    >::template eval<
        typename if_<
            gt_< 
                exponent , 
                quan::meta::rational<
                   quan::meta::digits10<int64_t>::value //std::numeric_limits<int64_t>::digits10
                >
            >,
            QUAN_FLOAT_TYPE,
            int64_t
        >::type
    > dummy;
     // if its a rational then the result type must be float
    typedef typename if_c<
        (reverse_calc ||( (exponent::numerator !=0 ) && (exponent::denominator!=1))),
        QUAN_FLOAT_TYPE,
        typename dummy::result_type
    >::type result_type;

    typedef pos_neg_eval_exponent<exponent,result_type, reverse_calc> eval;
    
};

}}}//quan::meta::detail

namespace quan{namespace meta{

    template <typename Exponent>
    struct eval_exponent {
        typedef typename detail::eval_exponent_impl<Exponent>::eval eval;
        typedef typename detail::eval_exponent_impl<Exponent>::result_type result_type;   
    };

}}//quan::meta

#endif
