#ifndef QUAN_MAGNETIC_CONSTANT_HPP_INCLUDED
#define QUAN_MAGNETIC_CONSTANT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    gravitational constant declaration
    note:
    requires compilation of "quan_matters/src/magnetic_constant.cpp"
    for linking
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/unit.hpp>
#include <quan/meta/abstract_quantity.hpp>
#include <quan/meta/dimension.hpp>
#include <quan/meta/conversion_factor.hpp>
#include <type_traits>

namespace quan {

    template <typename Value_type>
    struct magnetic_constant_{
        typedef  fixed_quantity< 
            meta::unit<  
                meta::abstract_quantity<
                    meta::dimension<
                        meta::rational<1>,
                        meta::rational<-2>,
                        meta::rational<1>,
                        meta::rational<0>,
                        meta::rational<-2>,
                        meta::rational<0>,
                        meta::rational<0> 
                    >
                >,
                meta::conversion_factor<
                    meta::rational<-7>
                >
            >,
            typename std::add_const<Value_type>::type
        > mu0_type;
   
        static mu0_type const mu0;
    };

    struct magnetic_constant : magnetic_constant_<quantity_traits::default_value_type>{};

#ifdef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<typename T>
typename magnetic_constant_<T>::mu0_type const
magnetic_constant_<T>::mu0 
= typename magnetic_constant_<T>::mu0_type(12.566370614);
#endif

} //quan

#endif
