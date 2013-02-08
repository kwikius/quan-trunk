#ifndef QUAN_DETAIL_CALC_TRIPLE_HPP_INCLUDED
#define QUAN_DETAIL_CALC_TRIPLE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace detail{

    // convenient holder for The exponent and multipliers in a calculation
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct calc_triple{
        typedef Exponent exponent;
        typedef Multiplier_L multiplier_L;
        typedef Multiplier_R multiplier_R;

        typedef calc_triple type;
    };

}}//quan::detail

#endif

