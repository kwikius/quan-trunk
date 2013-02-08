#ifndef QUAN_T1_QUANTITY_UNITS_OUT_HPP_INCLUDED
#define QUAN_T1_QUANTITY_UNITS_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
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

