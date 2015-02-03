#ifndef QUAN_ANGLE_ANGLE_FWD_HPP
#define QUAN_ANGLE_ANGLE_FWD_HPP
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
    forward decl of angles types
*/
#include <quan/meta/is_scalar.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{
 
    //radians,steradians etc
    template <
        typename Extent,    // to power 1 -1, 2 etc
        typename ValueType
    >
    class mathematic_angle;

    namespace meta{
       template <
        typename Extent,    // to power 1 -1, 2 etc
        typename ValueType
    > struct is_scalar<
        quan::mathematic_angle<Extent,ValueType>
    > : quan::meta::true_{};

   }//meta
    // degree, minutes, seconds etc
    template<
        typename Extent,    // to power 1 -1, 2 etc
        typename Fraction,  // a compile time fraction of a revolution
        typename ValueType
    >
    class fraction_of_revolution;

    namespace meta{
       template <
        typename Extent,    // to power 1 -1, 2 etc
        typename Fraction,
        typename ValueType
    > struct is_scalar<
        quan::fraction_of_revolution<Extent,Fraction,ValueType>
    > : quan::meta::true_{};

   }//meta

}//quan

#endif
