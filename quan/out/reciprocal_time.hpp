#ifndef QUAN_RECIPROCAL_TIME_OUT_HPP_INCLUDED
#define QUAN_RECIPROCAL_TIME_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/reciprocal_time.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_reciprocal_time::non_si_unit::per_min
    )
    {
        os << "min-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_reciprocal_time::non_si_unit::per_hour
    )
    {
        os << "h-1";
        return os;
    }
}}//quan::meta
#endif
