#ifndef QUAN_META_RATIONAL_FWD_HPP_INCLUDED1
#define QUAN_META_RATIONAL_FWD_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2003-2017 Andy Little.

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

// See QUAN_ROOT/quan_matters/doc/index.html for documentation.

#include <quan/config.hpp>
#include <quan/archetypes/meta/static_rational_concept.hpp>

namespace quan{namespace meta{

    template <int64_t N, int64_t D= 1>
    struct rational;

    // make a model of Rational
    template <int64_t N, int64_t D>
    struct is_rational<rational<N,D> > : std::true_type{};

}}//quan::meta

#endif
