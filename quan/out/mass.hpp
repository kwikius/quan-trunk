#ifndef QUAN_MASS_OUT_HPP_INCLUDED
#define QUAN_MASS_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/mass.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::AT
    )
    {
        os << "AT";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::ton_long
    )
    {
        os << "ton (long)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::t
    )
    {
        os << "t";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::carat
    )
    {
        os << "carat";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::grain
    )
    {
        os << "grain";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::hundredwgt_short
    )
    {
        os << "hundredweight (long)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::hundredwgt_long
    )
    {
        os << "hundredweight (short)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::oz
    )
    {
        os << "oz";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::troy_oz
    )
    {
        os << "oz (troy)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::dwt
    )
    {
        os << "dwt";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::lb
    )
    {
        os << "lb";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::troy_lb
    )
    {
        os << "lb (troy)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_mass::non_si_unit::slug
    )
    {
        os << "slug";
        return os;
    }
}}//quan::meta
#endif
