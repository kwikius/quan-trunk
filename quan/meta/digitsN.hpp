#ifndef QUAN_DIGITS_N_HPP_INCLUDED
#define QUAN_DIGITS_N_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    The number of digits in IntegerType when raised to base N.
    Only implemented for base 10
*/


#include <quan/where.hpp>
#include <limits>

namespace quan{ namespace meta{

    template< 
        int Base, 
        typename IntegerType,
        typename Enable = void
    >
    struct digits;

    template <typename IntegerType>
    struct digits<
            10, 
            IntegerType , 
            typename quan::where_c<
                std::numeric_limits<IntegerType>::is_specialized
            >::type
    >{
        static const int value = std::numeric_limits<IntegerType>::digits10;
    };

}}//quan::meta

#endif
