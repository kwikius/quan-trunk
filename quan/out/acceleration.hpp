#ifndef QUAN_ACCELERATION_OUT_HPP_INCLUDED
#define QUAN_ACCELERATION_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/acceleration.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_acceleration::non_si_unit::g_s
    )
    {
        os << "g";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_acceleration::non_si_unit::ft_per_s2
    )
    {
        os << "ft.s-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_acceleration::non_si_unit::Gal
    )
    {
        os << "Gal";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_acceleration::non_si_unit::in_per_s2
    )
    {
        os << "in.s-2";
        return os;
    }
}}//quan::meta
#endif
