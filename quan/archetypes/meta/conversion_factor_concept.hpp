#ifndef QUAN_META_CONVERSION_FACTOR_CONCEPT_HPP_INCLUDED
#define QUAN_META_CONVERSION_FACTOR_CONCEPT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
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
// See <QUAN_ROOT/quan_matters/index.html> for documentation.

/*
    associated metafunctions for StaticUnit Concept.
    These are required to be specialised per model
*/

#include <quan/meta/bool/false.hpp>

namespace quan{namespace meta{

    template <typename T, typename where = void >
    struct is_conversion_factor : quan::meta::false_{};

    template <typename T, typename Where = void>
    struct get_nearest_si;

    template <typename T,typename Where = void>
    struct is_si;
    
    template<typename TL,typename TR,typename Where = void>
    struct get_finest_grained;

    template <typename Unit,typename Where = void>
    struct get_exponent;
    
    template <typename Unit,typename Where = void>
    struct get_multiplier;
    
    template <typename Unit_L, typename Unit_R,typename Where = void>
    struct is_math_same_conversion_factor;

}}//quan::meta

#endif
