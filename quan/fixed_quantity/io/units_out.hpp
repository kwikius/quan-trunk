#ifndef QUAN_T1_QUANTITY_UNITS_OUT_HPP_INCLUDED
#define QUAN_T1_QUANTITY_UNITS_OUT_HPP_INCLUDED
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
    utility "dummy" classes used for output of units of a physical quantity
    which can be overloaded for special units
    e.g "N" (newtons),"kgf" (kilograms force )
*/

#include <quan/fixed_quantity/fixed_quantity_fwd.hpp>
namespace quan{

   /* template<   
        typename AbstractQuantity,
        typename Unit
    >
    class fixed_quantity_units_out{};*/

/*
    utility class used for output of units of a physical quantity  as
    Unit::si_exponent * Unit::incoherent_mx  version
    e.g "kg.m.s-2" (newtons), "kg.m.s-2 * 9.8" (kilograms force )
*/
    template<
        typename AbstractQuantity,
        typename Unit
    > 
    class fixed_quantity_basic_units_out{};

}//quan

#endif

