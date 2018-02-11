#ifndef QUAN_T1_QUANTITY_OUTPUT_HPP_INCLUDED
#define QUAN_T1_QUANTITY_OUTPUT_HPP_INCLUDED
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    basic utility output 
    of a physical_quantity for demo purposes
   
*/
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <iostream>
#include <sstream>
#include <quan/concepts/ostreamable.hpp>
#else
#include <quan/avr/iostream_dummy.hpp>
#include <quan/avr/sstream_dummy.hpp>
#endif
#include <quan/fixed_quantity/io/aux_units_out.hpp>




namespace quan{
    // This function provides output of fixed_quantities
    // Note that the units implementation is much more complex
    // than would appear from this definition.
    // See the documentation for more details
    // OTOH look at the implementation of
    // units(pq) in "quan/fixed_quantity/io/aux_units_out.hpp"
    template <
        typename StaticUnit,
        typename Value_type,
        typename CharType
    >
    inline 
    std::basic_ostream<CharType>& 
    operator << (
        std::basic_ostream<CharType>& os,
        fixed_quantity<
            StaticUnit,
            Value_type
        > const& pq 
    )
    {
        /*  
            In case where the value_type is an angle or solid angle 
            (or other than numeric)
            It may be necessary to modify this code so that
            output of the numeric_value doesnt include e.g rad etc.
            IOW the type of the named_quantity will define the output
            via the units(pq) function. To do and explain further.
            
        */
        os << pq.numeric_value() << ' ' << units(pq);
        return os;
    }

    // This function simply returns the stream output of a fixed_quantity
    // as in os << pq above, as a std::string
    template <
        typename CharType,
        typename StaticUnit,
        typename Value_type
    >
    inline 
    std::basic_string<CharType>
    units_str( 
        fixed_quantity<
            StaticUnit,
            Value_type
        > const& pq 
    )
    {
        std::basic_ostringstream<CharType> ost;
        ost << units(pq);
        return ost.str();
    }

    template <
        typename StaticUnit,
        typename Value_type
    >
    inline 
    std::string
    units_str( 
        fixed_quantity<
            StaticUnit,
            Value_type
        > const& pq 
    )
    {
        std::ostringstream ost;
        ost << units(pq);
        return ost.str();
    }
 
}//quan

//useful specialisation of binary_operation stream output

namespace quan{namespace meta{ 
   namespace impl{

    template < 
        typename StaticUnit,
        typename Value_type,    
        typename CharType
    >
    struct binary_op_impl< 
        std::basic_ostream<CharType>,
        shift_left, 
        quan::fixed_quantity<StaticUnit,Value_type>
    >{
        typedef std::basic_ostream<CharType>& type;
    };
  } // impl
}}//quan::meta

#ifndef QUAN_AVR_NO_CPP_STDLIB
namespace quan{ namespace impl{

   template < 
      typename StaticUnit,
      typename Value_type
   >
   struct is_model_of_impl<quan::Ostreamable_,quan::fixed_quantity<StaticUnit,Value_type> > : quan::meta::true_{};
}} // quan::impl

#endif

#endif


    

