#ifndef QUAN_TIME_OUT_HPP_INCLUDED
#define QUAN_TIME_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/time.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::d
    )
    {
        os << "d";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::d_sid
    )
    {
        os << "d (sid)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::h
    )
    {
        os << "h";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::h_sid
    )
    {
        os << "h (sid)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::min
    )
    {
        os << "min";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::min_sid
    )
    {
        os << "min (sid)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::s_sid
    )
    {
        os << "s (sid)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::wk
    )
    {
        os << "wk";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::yr
    )
    {
        os << "yr";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::yr_sid
    )
    {
        os << "yr (sid)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_time::non_si_unit::yr_trop
    )
    {
        os << "yr (trop)";
        return os;
    }
}}//quan::meta
#endif
