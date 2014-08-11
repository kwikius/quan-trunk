#ifndef QUAN_DIGITS_N_HPP_INCLUDED
#define QUAN_DIGITS_N_HPP_INCLUDED
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
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    The number of digits in IntegerType when raised to base N.
    Only implemented for base 10
*/


#include <quan/where.hpp>
#include <limits>

namespace quan{ namespace meta{

    template< 
        int Base, 
        typename IntegerType,
        typename Enable = void
    >
    struct digits;

    template <typename IntegerType>
    struct digits<
            10, 
            IntegerType , 
            typename quan::where_c<
                std::numeric_limits<IntegerType>::is_specialized
            >::type
    >{
        static const int value = std::numeric_limits<IntegerType>::digits10;
    };

}}//quan::meta

#endif
