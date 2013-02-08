#ifndef QUAN_GENERIC_BINARY_OPERATOR_EXTRA_KEYS_HPP_INCLUDED
#define QUAN_GENERIC_BINARY_OPERATOR_EXTRA_KEYS_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

//  Copyright (C) Andy Little, White Light Device 2005.

 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    operator keys for use with binary_operation 
*/
#include <quan/config.hpp>

namespace quan{ namespace meta{

    struct plus;
    struct minus;
    struct times;
    struct divides;
    struct modulus;
    struct div;

    struct logical_or;
    struct logical_and;

    struct equal_to;
    struct not_equal_to;

    struct greater;
    struct greater_equal;
    struct less_equal;
    struct less;

    struct pow;

    struct equals;
    struct plus_equals;
    struct minus_equals;
    struct times_equals;
    struct divide_equals;
    struct modulus_equals;
    struct shift_left_equals;
    struct shift_right_equals;
    struct or_equals;
    struct and_equals;
    struct xor_equals;

    struct bit_or;
    struct bit_xor;
    struct bit_and;
    struct shift_left;
    struct shift_right;
    
       
}}//quan::meta

#endif

