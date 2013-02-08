#ifndef GENERIC_BINARY_OPERATOR_PARAMETERS_HPP_INCLUDED
#define GENERIC_BINARY_OPERATOR_PARAMETERS_HPP_INCLUDED

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Information about binary operators, associativity, precedence
    etc.
*/
#include <quan/config.hpp>

namespace quan { namespace meta{
    
    struct binary_operator_parameters{
       enum assoc {left_associative,right_associative};
        
        enum{     
            assignment_expression = 1,
            conditional_expression=2,
            logical_or_expression=3,
            logical_and_expression=4,
            inclusive_or_expression=5,
            exclusive_or_expression=6,
            and_expression=7,
            equality_expression=8, 
            relational_expression=9,
            shift_expression=10,
            additive_expression=11,
            multiplicative_expression=12,
            pow_expression = 13
        };
        
    };        

} }//quan::meta

#endif
