#ifndef QUAN_GENERIC_BINARY_OPERATOR_PARAMETERS_HPP_INCLUDED
#define QUAN_GENERIC_BINARY_OPERATOR_PARAMETERS_HPP_INCLUDED

/*
 Copyright (c) 2005-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/
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
