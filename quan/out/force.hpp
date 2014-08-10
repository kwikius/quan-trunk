#ifndef QUAN_FORCE_OUT_HPP_INCLUDED
#define QUAN_FORCE_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/force.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::dyn
    )
    {
        os << "dyn";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::kgf
    )
    {
        os << "kgf";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::kip
    )
    {
        os << "kip";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::ozf
    )
    {
        os << "ozf";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::poundal
    )
    {
        os << "poundal";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::lbf
    )
    {
        os << "lbf";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_force::non_si_unit::ton_force
    )
    {
        os << "ton-force";
        return os;
    }
}}//quan::meta
#endif
