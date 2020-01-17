#ifndef QUAN_META_NUMERATOR_HPP_INCLUDED
#define QUAN_META_NUMERATOR_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

 /*
 Copyright (c) 2005 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

/*
    Get the normalised numerator of a StaticRational
*/

#include <quan/archetypes/meta/static_rational_concept.hpp>

namespace quan{namespace meta{

#if defined __cpp_concepts
    template <Rational R>
    struct numerator;
#else
    template <typename StaticRational>
    struct numerator;
#endif

    template <intmax_t N, intmax_t D>
    struct numerator<std::ratio<N,D> > : std::integral_constant<intmax_t,std::ratio<N,D>::type::num>{};

}}//quan::meta

#endif
