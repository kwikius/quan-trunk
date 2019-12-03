#ifndef QUAN_META_UNIT_HPP_INCLUDED1
#define QUAN_META_UNIT_HPP_INCLUDED1
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
#include <quan/meta/if.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/and.hpp>
#include <quan/where.hpp>

namespace quan{ namespace meta{

    struct unit_base{ 
//      private: 
//         unit_base() = delete;
     };

    template <
        typename StaticAbstractQuantity,
        typename StaticConversionFactor
    >
    struct unit : unit_base{
        typedef StaticAbstractQuantity      abstract_quantity;
        typedef StaticConversionFactor      conversion_factor;
        typedef unit                        type;
    };

    template <typename T> 
    struct is_static_unit<T,typename quan::where_<std::is_base_of<unit_base,T> >::type> : quan::meta::true_{};

#if 1
      template <typename TL, typename TR>
      struct dimensionally_equivalent<
         TL, TR,
         typename quan::where_<
            typename quan::meta::and_<
               is_static_unit<TL>,
               is_static_unit<TR>
            >
         >::type
      > : dimensionally_equivalent<
            typename TL::abstract_quantity,
            typename TR::abstractquantity
      >{};

#else
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
#endif

#if 1

    template <typename T> 
    struct name_anonymous_unit <T,
      typename quan::where_<
         is_static_unit<T> 
      >::type
    >{
        typedef unit<
            typename name_anonymous_abstract_quantity<
               typename T::abstract_quantity
            >::type,
           typename T::conversion_factor
         > type;
    };

#else
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
#endif

#if 1
    template <typename T>
    struct allow_implicit_unit_conversions<
      T,
      typename quan::where_<
         is_static_unit<T> 
      >::type
    >
#else
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
#endif
#ifdef QUAN_DISALLOW_IMPLICIT_UNIT_CONVERSIONS
    : std::false_type{};
#else
    : std::true_type{};
#endif

#if 1
      template <typename T>
      struct is_dimensionless<
         T,
         typename quan::where_<
           is_static_unit<T> 
         >::type
       > : is_dimensionless<typename T::abstract_quantity>{};
#else
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
#endif

#if 1

#else
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
#endif


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
#if 1
    template <typename T>
    struct get_conversion_factor<
      T,
      typename quan::where_<is_static_unit<T> >::type
    >{
      typedef typename T::conversion_factor type;
    };

#else
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
#endif

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

    namespace impl{

       template<
           typename StaticAbstractQuantity_L,
           typename StaticConversionFactor_L,
           typename Op,
           typename StaticAbstractQuantity_R,
           typename StaticConversionFactor_R
       >
       struct binary_op_impl<
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
       struct binary_op_impl<
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

    } // impl

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
