#ifndef QUAN_GAS_CONSTANT_HPP_INCLUDED
#define QUAN_GAS_CONSTANT_HPP_INCLUDED
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
    declaration of gas_constant.
    definition in "quan_matters/src/gas_constant.cpp"
    required to link
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>

namespace quan{

    template<typename Value_type>
    struct gas_constant_{
        typedef fixed_quantity<  
           meta::unit<
                meta::abstract_quantity<
                    meta::dimension<
                        quan::meta::dim_length<2> 
                        ,quan::meta::dim_time<-2> 
                        ,quan::meta::dim_mass<1> 
                        ,quan::meta::dim_temperature<-1> 
                        ,quan::meta::dim_substance<-1> 
                    >
                >,
                meta::conversion_factor<>
            >,
            Value_type
        > R_type;
/*
#if defined QUAN_HAS_CONSTEXPR
       static constexpr auto R = R_type{8.3145};
#else
*/
       static R_type const  R;
//#endif
    };

    struct gas_constant : gas_constant_<
            quantity_traits::default_value_type
    >{};


#ifdef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS

template<typename T>
typename gas_constant_<T>::R_type const
gas_constant_<T>::R 
= typename gas_constant_<T>::R_type(8.3145);

#endif

} //quan

#endif
