#ifndef QUAN_QUANTITY_TRAITS_HPP_INCLUDED2911030401
#define QUAN_QUANTITY_TRAITS_HPP_INCLUDED2911030401
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
/*
 Copyright (c) 2006-2013 Andy Little 

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
    config,traits and scaling functions for all ct_quantities
*/

#include <quan/config.hpp>
#include <quan/meta/arithmetic_promote.hpp>
#include <quan/meta/to_arithmetic.hpp>
//#include <quan/concept_checking.hpp>
#include <quan/arithmetic_convert.hpp>

#if defined QUAN_AVR_NO_CPP_STDLIB
#include <limits.h>
#else
#include <limits>
#endif

namespace quan {

    struct quantity_traits {
        enum{
        // If you define fixed_quantities with
        // named_quantity_tag > than this value
        // then you need to write your own  
        // units functions
           max_default_named_quantity_tag = 100
        };    
        // for use as the default value_type for ct_quantities
        typedef  QUAN_FLOAT_TYPE  default_value_type;
        template <typename Value_type>
        struct  min_real{
            typedef typename quan::meta::arithmetic_promote<
                Value_type,
               default_value_type
            >::type type;
        };
      
        // converter with nearest neighbour rounding
        template<typename T, typename S>
        struct value_type_converter {


				constexpr
	
            T operator()(S const & s) const
            {
               return quan::arithmetic_convert<T>(s);
                //return s;
            }
         };

//        template<>
//        struct value_type_converter<float,double> {
//
//				constexpr float operator()(double const & s) const
//            {
//               return static_cast<float>(s);
//                //return s;
//            }
//         };
//          
    };
  
} //quan

#endif
