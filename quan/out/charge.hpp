#ifndef QUAN_CHARGE_OUT_HPP_INCLUDED
#define QUAN_CHARGE_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/charge.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_charge::non_si_unit::A_h
    )
    {
        os << "A.h";
        return os;
    }

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_charge::non_si_unit::mA_h
    )
    {
        os << "mA.h";
        return os;
    }

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_charge::non_si_unit::abcoulomb
    )
    {
        os << "abcoulomb";
        return os;
    }
}}//quan::meta
#endif
