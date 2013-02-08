#ifndef QUAN_VELOCITY_OUT_HPP_INCLUDED
#define QUAN_VELOCITY_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/velocity.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::ft_per_h
    )
    {
        os << "ft.h-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::ft_per_min
    )
    {
        os << "ft.min-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::ft_per_s
    )
    {
        os << "ft.s-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::in_per_s
    )
    {
        os << "in.s-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::km_per_h
    )
    {
        os << "km.h-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::knot
    )
    {
        os << "knot";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::mi_per_h
    )
    {
        os << "mi.h-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::mi_per_min
    )
    {
        os << "mi.min-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::mi_per_s
    )
    {
        os << "mi.s-1";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_velocity::non_si_unit::mm_per_min
    )
    {
        os << "mm.min-1";
        return os;
    }
}}//quan::meta
#endif
