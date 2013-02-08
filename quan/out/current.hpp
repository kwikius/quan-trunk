#ifndef QUAN_CURRENT_OUT_HPP_INCLUDED
#define QUAN_CURRENT_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/current.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_current::non_si_unit::abampere
    )
    {
        os << "abampere";
        return os;
    }
}}//quan::meta
#endif
