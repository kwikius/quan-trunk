#ifndef QUAN_AUX_UNITS_OUT_HPP_INCLUDED
#define QUAN_AUX_UNITS_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#include <quan/config.hpp>
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

/*
   overloaded stream output of the units of a ct_quantity
   via the units(pq) function.
*/
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <iostream>
#else
#include <quan/avr/iostream_dummy.hpp>
#endif

#include <quan/where.hpp>
#include <quan/fixed_quantity/fixed_quantity_fwd.hpp>
#include <quan/meta/abstract_quantity.hpp>
#include <quan/fixed_quantity/io/units_out.hpp>
#include <quan/meta/unit.hpp>
#include <quan/fixed_quantity/io/detail/units_out_impl.hpp>
#include <quan/fixed_quantity/io/units_ostream.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>

namespace quan{
    
    // units(pq) simply returns a fixed_quantity_units_out <..> object
    // which is what the ostream operator actually picks up.
   
    template<
        typename StaticUnit,
        typename Value_type
    >
    inline

    StaticUnit
    units(
        fixed_quantity<
            StaticUnit,
            Value_type
        > const & 
    )
    {
        return StaticUnit();
    }

    // the ostream << operator for the 
    // fixed_quantity_units_out<..> object returned by the above function

    template<
        typename AbstractQuantity,
        typename ConversionFactor,
        typename CharType
    >
    inline std::basic_ostream<CharType>& 
    operator << (  
        std::basic_ostream<CharType>& os,
        quan::meta::unit<AbstractQuantity,ConversionFactor> 
    )
    {
        //##################### COMPILE TIME ASSERTION FAILURE ############

        // only SI and anonymous fixed_quantities are allowed
        // in this function... see  below if your compilation fails here-->

        typedef quan::meta::unit<AbstractQuantity,ConversionFactor> unit;    
        typedef typename quan::meta::not_<
            quan::meta::and_<
                quan::meta::is_named_quantity<unit>,
                quan::meta::not_<
                    quan::meta::is_si<unit>
                >
            >
        >::type valid_quantity;

         static_assert((valid_quantity::value !=0),"only si quantities allowed here");

        // This assertion fails if you have included the default output facilities but
        // are trying to output a named quantity 
        // with a non SI conversion factor using the default output function.
        // non-si quantities use specific io overloads.
        // You have probably either forgotten 
        // to #include the stream output version of the header for the particular non SI quantity
         // e.g <quan/out/length.hpp>
        // or forgotten to provide an overload for the particular non SI unit
        // if you have added it
        //##################### compile time assertion failure ############

        enum{ which = ( (meta::is_named_quantity<unit >::value)
             && (quan::meta::is_si<unit>::value) )};     
        quan::detail::fixed_quantity_units_output_impl<
            unit,which
        >::put(os);
        return os;
    }
}//quan

#endif
