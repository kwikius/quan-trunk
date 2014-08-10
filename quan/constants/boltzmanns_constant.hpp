#ifndef QUAN_BOLTZMANNS_CONSTANT_HPP_INCLUDED
#define QUAN_BOLTZMANNS_CONSTANT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
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
                        meta::rational<2>,
                        meta::rational<-2>,
                        meta::rational<1>,
                        meta::rational<-1>,
                        meta::rational<0>,
                        meta::rational<0>,
                        meta::rational<0>
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
