#ifndef QUAN_META_UNIT_HPP_INCLUDED1
#define QUAN_META_UNIT_HPP_INCLUDED1
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    meta::unit is the implementation supplied model of StaticUnit
*/

#include <quan/config.hpp>
#include <quan/meta/unit_fwd.hpp>
#include <quan/archetypes/meta/static_unit_concept.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/si_unit_system.hpp>
#include <quan/static_assert.hpp>
#include <quan/meta/not.hpp>
#include <type_traits>
#include <quan/meta/if.hpp>
#include <type_traits>

namespace quan{ namespace meta{

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct unit{
        typedef StaticAbstractQuantity      abstract_quantity;
        typedef StaticConversionFactor      conversion_factor;
        typedef unit                        type;
    };

    template <
        typename StaticAbstractQuantity_L,
        typename StaticConversionFactor_L,
        typename StaticAbstractQuantity_R,
        typename StaticConversionFactor_R
    >
    struct dimensionally_equivalent<
        unit<
            StaticAbstractQuantity_L,
            StaticConversionFactor_L
        >,
        unit<
            StaticAbstractQuantity_R,
            StaticConversionFactor_R
        >
    > : dimensionally_equivalent<
        StaticAbstractQuantity_L,
        StaticAbstractQuantity_R
      >{};

    template <
         typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct name_anonymous_unit<
       unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    >{
         QUAN_STATIC_ASSERT(
            (not_<
               is_named_quantity<
                  unit<
                     StaticAbstractQuantity,
                     StaticConversionFactor
                  >
               >
            >::value));
         typedef unit<
            typename name_anonymous_abstract_quantity<
               StaticAbstractQuantity
            >::type,
            StaticConversionFactor
         > type;
     };

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct allow_implicit_unit_conversions<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    >
#ifdef QUAN_DISALLOW_IMPLICIT_UNIT_CONVERSIONS
    : std::false_type{};
#else
    : std::true_type{};
#endif

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct is_dimensionless<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : is_dimensionless<StaticAbstractQuantity>{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct make_anonymous<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : unit<
        typename make_anonymous<
            StaticAbstractQuantity
        >::type,
        StaticConversionFactor
    >{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct get_quantity_system<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : get_quantity_system<StaticAbstractQuantity>{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct is_si<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : and_<
        is_si<StaticConversionFactor>,
        std::is_same<
            typename get_quantity_system<
                StaticAbstractQuantity
            >::type,
            si_unit_system
        >
    >{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct is_named_quantity<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : is_named_quantity<StaticAbstractQuantity>{};

     template <
        typename StaticAbstractQuantity_L,
        typename StaticConversionFactor_L,
        typename StaticAbstractQuantity_R,
        typename StaticConversionFactor_R
    >
    struct is_same_quantity<
        unit<
            StaticAbstractQuantity_L,
            StaticConversionFactor_L
        >,
        unit<
            StaticAbstractQuantity_R,
            StaticConversionFactor_R
        >
    > : is_same_quantity<
        StaticAbstractQuantity_L,
        StaticAbstractQuantity_R
    >{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct get_named_quantity_traits<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : get_named_quantity_traits<
            StaticAbstractQuantity
    >{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct get_nearest_si<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : unit<
        StaticAbstractQuantity,
        typename get_nearest_si<StaticConversionFactor>::type
    >{};

    template <
        typename StaticAbstractQuantity,
        typename ConversionFactorL,
        typename ConversionFactorR
    >
    struct get_finest_grained<
        quan::meta::unit<
            StaticAbstractQuantity,
            ConversionFactorL
        >,
        quan::meta::unit<
            StaticAbstractQuantity,
            ConversionFactorR
        >
    > : if_<
            std::is_same<
                typename get_finest_grained<
                    ConversionFactorL,
                    ConversionFactorR
                >::type,
                ConversionFactorL
            >,
            quan::meta::unit<
                StaticAbstractQuantity,
                ConversionFactorL
            >,
            quan::meta::unit<
                StaticAbstractQuantity,
                ConversionFactorR
            >
    >{};

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct get_conversion_factor<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : StaticConversionFactor{};

    #define QUAN_META_GET_DIMENSION(Q) \
    template <typename StaticAbstractQuantity,typename StaticConversionFactor>\
    struct  QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension) <\
        unit<StaticAbstractQuantity,StaticConversionFactor>\
    > : QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension)<StaticAbstractQuantity>{};

    QUAN_META_GET_DIMENSION(length)
    QUAN_META_GET_DIMENSION(time)
    QUAN_META_GET_DIMENSION(mass)
    QUAN_META_GET_DIMENSION(temperature)
    QUAN_META_GET_DIMENSION(current)
    QUAN_META_GET_DIMENSION(substance)
    QUAN_META_GET_DIMENSION(intensity)

    #undef QUAN_META_GET_DIMENSION

    template<
        typename StaticAbstractQuantity_L,
        typename StaticConversionFactor_L,
        typename Op,
        typename StaticAbstractQuantity_R,
        typename StaticConversionFactor_R
    >
    struct  binary_op<
        unit<
            StaticAbstractQuantity_L,
            StaticConversionFactor_L
        >,
        Op,
        unit<
            StaticAbstractQuantity_R,
            StaticConversionFactor_R
        >
    > : unit<
        typename binary_op<
            StaticAbstractQuantity_L,
            Op,
            StaticAbstractQuantity_R
        >::type,
        typename binary_op<
            StaticConversionFactor_L,
            Op,
            StaticConversionFactor_R
        >::type
     >{};

    template<
         typename StaticAbstractQuantity,
         typename StaticConversionFactor,
         typename Exponent
    >
    struct binary_op<
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >,
        pow,
        Exponent
    > : unit<
         typename  binary_op<
             StaticAbstractQuantity,
             pow,
             Exponent
         >::type,
         typename binary_op<
             StaticConversionFactor,
             pow,
             Exponent
         >::type
     >{};

    template<
      typename StaticAbstractQuantity,
      typename StaticConversionFactor,
      typename Op
    >
    struct unary_operation<
        Op,
        unit<
            StaticAbstractQuantity,
            StaticConversionFactor
        >
    > : unit<
        typename unary_operation<
            Op,
            StaticAbstractQuantity
        >::type,
        typename unary_operation<
            Op,
            StaticConversionFactor
        >::type
    >{};

} }//quan::meta

#endif
