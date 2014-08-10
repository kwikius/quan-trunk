#ifndef QUAN_GRAVITATIONAL_CONSTANT_HPP_INCLUDED
#define QUAN_GRAVITATIONAL_CONSTANT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    gravitational constant declaration
    note:
    requires compilation of <quan_matters/src/gravitational_constant.cpp>
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
    struct gravitational_constant_{
        typedef  fixed_quantity< 
            meta::unit< 
                meta::abstract_quantity<
                    meta::dimension<
                        meta::rational<3>,
                        meta::rational<-2>,
                        meta::rational<-1>,
                        meta::rational<0>,
                        meta::rational<0>,
                        meta::rational<0>,
                        meta::rational<0> 
                    >
                >,
                meta::conversion_factor<
                    meta::rational<-11>
                >
            >,
            typename std::add_const<Value_type>::type
        > G_type;
   
        static G_type const G;
    };

    struct gravitational_constant : gravitational_constant_<
        quantity_traits::default_value_type
    >{};

#ifdef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
template<typename T>
typename gravitational_constant_<T>::G_type const 
gravitational_constant_<T>::G(static_cast<T>(6.6726));
#endif

} //quan

#endif

