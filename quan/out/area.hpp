#ifndef QUAN_AREA_OUT_HPP_INCLUDED
#define QUAN_AREA_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/area.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::acre
    )
    {
        os << "acre";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::a
    )
    {
        os << "a";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::b
    )
    {
        os << "b";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::circular_mil
    )
    {
        os << "circular mil";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::ha
    )
    {
        os << "ha";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::ft2
    )
    {
        os << "ft2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::in2
    )
    {
        os << "in2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::mi2
    )
    {
        os << "mi2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::mi2_us_survey
    )
    {
        os << "mi2 (U.S.)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_area::non_si_unit::yd2
    )
    {
        os << "yd2";
        return os;
    }
}}//quan::meta
#endif
