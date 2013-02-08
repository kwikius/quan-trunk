#ifndef QUAN_RESISTANCE_OUT_HPP_INCLUDED
#define QUAN_RESISTANCE_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/resistance.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_resistance::non_si_unit::abohm
    )
    {
        os << "abohm";
        return os;
    }
}}//quan::meta
#endif
