#ifndef QUAN_BOLTZMANNS_CONSTANT_HPP_INCLUDED
#define QUAN_BOLTZMANNS_CONSTANT_HPP_INCLUDED
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
    declaration of boltzmanns constant.
    definition in "quan_matters/src/boltzmanns_constant.cpp"
    required to link
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/unit.hpp>
#include <quan/meta/abstract_quantity.hpp>
#include <quan/meta/dimension.hpp>
#include <quan/meta/conversion_factor.hpp>
#include <type_traits>

namespace quan{

    template<typename Value_type=double>
    struct boltzmanns_constant_{
       typedef  fixed_quantity< // boltzmanns constant
            meta::unit<
                meta::abstract_quantity<
                    meta::dimension<

                        quan::meta::dim_length<2> 
                        ,quan::meta::dim_time<-2> 
                        ,quan::meta::dim_mass<1> 
                        ,quan::meta::dim_temperature<-1> 

                    >
                >,
                meta::conversion_factor<
                    meta::rational<-23>
                >
            >,
            Value_type
        > K_type;
        static K_type const  K;
    };
    struct boltzmanns_constant 
    : boltzmanns_constant_<quantity_traits::default_value_type>{};

#ifdef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template <typename T>
typename boltzmanns_constant_<T>::K_type const
boltzmanns_constant_<T>::K 
= typename boltzmanns_constant_<T>::K_type(1.380658);
#endif

} //quan

#endif
