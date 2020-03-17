#ifndef QUAN_MAGNETIC_FLUX_DENSITY_OUT_HPP_INCLUDED
#define QUAN_MAGNETIC_FLUX_DENSITY_OUT_HPP_INCLUDED
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

#include <quan/magnetic_flux_density.hpp>
#include <quan/fixed_quantity/io/output.hpp>

namespace quan{ namespace meta{

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_magnetic_flux_density::non_si_unit::gauss
    )
    {
        os << "gauss";
        return os;
    }

    inline
    std::ostream&
    operator <<(
        std::ostream & os,
        quan::meta::components::of_magnetic_flux_density::non_si_unit::milli_gauss
    )
    {
        os << "milli_gauss";
        return os;
    }

}}//quan::meta
#endif
