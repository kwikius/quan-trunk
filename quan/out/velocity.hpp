#ifndef QUAN_VELOCITY_OUT_HPP_INCLUDED
#define QUAN_VELOCITY_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */
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
