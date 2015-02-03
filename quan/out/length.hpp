#ifndef QUAN_LENGTH_OUT_HPP_INCLUDED
#define QUAN_LENGTH_OUT_HPP_INCLUDED
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

#include <quan/length.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::fathom_us
    )
    {
        os << "fathom (U.S.)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::AU
    )
    {
        os << "AU";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::ch
    )
    {
        os << "ch";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::fathom
    )
    {
        os << "fathom";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::ft
    )
    {
        os << "ft";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::ft_us
    )
    {
        os << "ft (U.S.)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::in
    )
    {
        os << "in";
        return os;
    }

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::mil
    )
    {
        os << "mil";
        return os;
    }

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::thou
    )
    {
        os << "thou";
        return os;
    }

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::l_y_
    )
    {
        os << "l.y.";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::mi
    )
    {
        os << "mi";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::naut_mile
    )
    {
        os << "nautical mile";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::pc
    )
    {
        os << "pc";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::pica_comp
    )
    {
        os << "pica (comp)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::pica_prn
    )
    {
        os << "pica (prn)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::point_comp
    )
    {
        os << "point (comp)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::point_prn
    )
    {
        os << "point (prn)";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::rd
    )
    {
        os << "rd";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::yd
    )
    {
        os << "yd";
        return os;
    }
    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_length::non_si_unit::angstrom
    )
    {
        os << "angstrom";
        return os;
    }
}}//quan::meta
#endif
