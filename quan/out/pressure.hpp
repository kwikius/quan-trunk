#ifndef QUAN_PRESSURE_OUT_HPP_INCLUDED
#define QUAN_PRESSURE_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/pressure.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::atm
    )
    {
        os << "atm";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::at
    )
    {
        os << "at";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::bar
    )
    {
        os << "bar";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::cm_mercury0C
    )
    {
        os << "cm mercury (0 deg C)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::cmHg
    )
    {
        os << "cmHg";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::cm_water4C
    )
    {
        os << "cm water (4 deg C)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::cmH20
    )
    {
        os << "cmH20";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::dyn_per_cm2
    )
    {
        os << "dyn.cm-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::ftHg
    )
    {
        os << "ftHg";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::ft_water39_2F
    )
    {
        os << "ft water (39.2 deg F)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::ftH20
    )
    {
        os << "ftH20";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::gf_per_cm2
    )
    {
        os << "gf.cm-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::in_mercury32F
    )
    {
        os << "in mercury (32 deg F)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::in_mercury60F
    )
    {
        os << "in mercury (60 deg F)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::inHg
    )
    {
        os << "inHg";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::in_water39_2F
    )
    {
        os << "in water (39.2 deg F)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::inH20
    )
    {
        os << "inH20";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::kgf_per_cm2
    )
    {
        os << "kgf.cm-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::kgf_per_m2
    )
    {
        os << "kgf.m-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::kgf_per_mm2
    )
    {
        os << "kgf.mm-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::ksi
    )
    {
        os << "ksi";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::mbar
    )
    {
        os << "mbar";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::mmHg
    )
    {
        os << "mmHg";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::mmH20
    )
    {
        os << "mmH20";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::lbf_per_ft2
    )
    {
        os << "lbf.ft-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::psi
    )
    {
        os << "psi";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::poundal_per_ft2
    )
    {
        os << "poundal.ft-2";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_pressure::non_si_unit::torr
    )
    {
        os << "Torr";
        return os;
    }
}}//quan::meta
#endif
