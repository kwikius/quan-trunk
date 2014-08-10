#ifndef QUAN_T1_QUANTITY_OUTPUT_HPP_INCLUDED
#define QUAN_T1_QUANTITY_OUTPUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    basic utility output 
    of a physical_quantity for demo purposes
   
*/
#ifndef __AVR__
#include <iostream>
#include <sstream>
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

    template < 
        typename StaticUnit,
        typename Value_type,    
        typename CharType
    >
    struct binary_op< 
        std::basic_ostream<CharType>,
        shift_left, 
        fixed_quantity<StaticUnit,Value_type>
    >{
        typedef std::basic_ostream<CharType>& type;
    };

}}//quan::meta

#endif


    

