#ifndef QUAN_GAS_CONSTANT_HPP_INCLUDED
#define QUAN_GAS_CONSTANT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
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
                        meta::rational<2>,
                        meta::rational<-2>,
                        meta::rational<1>,
                        meta::rational<-1>,
                        meta::rational<0>,
                        meta::rational<-1>,
                        meta::rational<0> 
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
