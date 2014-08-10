#ifndef QUAN_VOLUME_OUT_HPP_INCLUDED
#define QUAN_VOLUME_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/volume.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::acre_foot
    )
    {
        os << "acre-foot";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::bbl
    )
    {
        os << "bbl";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::bu
    )
    {
        os << "bu";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::cord
    )
    {
        os << "cord";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::ft3
    )
    {
        os << "ft3";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::in3
    )
    {
        os << "in3";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::mi3
    )
    {
        os << "mi3";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::yd3
    )
    {
        os << "yd3";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::cup
    )
    {
        os << "cup";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::fl_oz_US
    )
    {
        os << "fl oz (U.S.)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::gal
    )
    {
        os << "gal";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_volume::non_si_unit::gal_US
    )
    {
        os << "gal (U.S.)";
        return os;
    }
}}//quan::meta
#endif
