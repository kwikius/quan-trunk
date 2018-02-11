#ifndef QUAN_META_IS_SCALAR_QUANTITY_HPP_INCLUDED
#define QUAN_META_IS_SCALAR_QUANTITY_HPP_INCLUDED

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
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    is T either a quantity or arithmetic
#######################################################
    Note Well: this is not the same as ssd::is_scalar
    which allows pointers etc
#################################################

    In Quan vector quantities are distinguishable because they look like:

    some_vector<Dims,quantity> my_vector_quantity;

    Otherwise they are in scalar form. Simply put, even if a quantity is,
    by nature, a vector quantity,the information is not useful uunless the 
    vector information ( magnitude and direction) is provided.
*/
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/integral_constant.hpp>
#endif

namespace quan{ namespace meta{

    template <typename T>
    struct is_scalar_quantity : std::is_arithmetic<T>{};

}}//quan::meta

#endif
