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
    struct is_static_unit<
      T,
      typename quan::where_<
         std::is_base_of<unit_base,T> 
      >::type
     > : quan::meta::true_{};

#if 1
      template <typename UL, typename UR>
      struct dimensionally_equivalent<
         UL, UR,
         typename quan::where_<
            typename quan::meta::and_<
               is_static_unit<UL>,
               is_static_unit<UR>
            >
         >::type
      > : dimensionally_equivalent<
            typename UL::abstract_quantity,
            typename UR::abstract_quantity
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

    template <typename U> 
    struct name_anonymous_unit <
      U,
      typename quan::where_<
         is_static_unit<U> 
      >::type
    > : unit<
         typename name_anonymous_abstract_quantity<
            typename U::abstract_quantity
         >::type,
        typename U::conversion_factor
    >{
       static_assert(
         not_< 
            is_named_quantity<U>
         >::value,""
       );
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
    template <typename U>
    struct allow_implicit_unit_conversions<
      U,
      typename quan::where_<
         is_static_unit<U> 
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
      template <typename U>
      struct is_dimensionless<
         U,
         typename quan::where_<
           is_static_unit<U> 
         >::type
       > : is_dimensionless<typename U::abstract_quantity>{};
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

     template <typename U>
      struct make_anonymous<
         U,
         typename quan::where_<
           is_static_unit<U> 
         >::type
       > : unit< 
            typename make_anonymous<
               typename U::abstract_quantity
            >::type,
            typename U::conversion_factor
       >{};

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

#if 1

    template <typename U>
    struct get_quantity_system<
      U,
      typename quan::where_<
        is_static_unit<U> 
      >::type
    > : get_quantity_system<typename U::abstract_quantity>{};

#else
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
#endif

#if 1

    template <typename U>
    struct is_si<
      U,
      typename quan::where_<
        is_static_unit<U> 
      >::type
    > : and_<
        is_si<typename U::conversion_factor>,
        std::is_same< 
           typename get_quantity_system<
              typename U::abstract_quantity
           >::type,
           si_unit_system
        >    
    >{};

#else
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
#endif

#if 1
    template <typename U>
    struct is_named_quantity<
      U,
      typename quan::where_<
        is_static_unit<U> 
      >::type
    > : is_named_quantity<typename U::abstract_quantity>{};

#else
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
#endif

#if 1

    template <typename UL, typename UR>
    struct is_same_quantity<
       UL, UR,
      typename quan::where_<
         and_<
            is_static_unit<UL>,
            is_static_unit<UR>
         >
      >::type
    > : is_same_quantity<
        typename UL::abstract_quantity,
        typename UR::abstract_quantity
    >{};

#else
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

#endif

#if 1

    template <typename U>
    struct get_named_quantity_traits<
       U,
       typename quan::where_<
          is_static_unit<U>
       >::type
    > : get_named_quantity_traits<
         typename U::abstract_quantity
    >{};

#else
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
#endif

#if 1

   template <typename U>
   struct get_nearest_si<
     U,
     typename quan::where_<
       is_static_unit<U>
     >::type
   > : unit<
       typename U::abstract_quantity,
       typename get_nearest_si<
          typename U::conversion_factor
       >::type
   >{};

#else
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
#endif

#if 1
    template <typename UL, typename UR>
    struct get_finest_grained<UL,UR,
      typename quan::where_<
         and_<
            is_static_unit<UL>,
            is_static_unit<UR>
         >
      >::type
    > : if_<
         std::is_same<
             typename get_finest_grained<
                 typename UL::conversion_factor,
                 typename UR::conversion_factor
             >::type,
             typename UL::conversion_factor
         >,
         quan::meta::unit<
             typename UL::abstract_quantity,
             typename UL::conversion_factor
         >,
         quan::meta::unit<
             typename UR::abstract_quantity,
             typename UR::conversion_factor
         >
    >{};
   
#else
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

#endif

#if 1
    template <typename U>
    struct get_conversion_factor<
      U,
      typename quan::where_<is_static_unit<U> >::type
    >{
      typedef typename U::conversion_factor type;
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

#if 1

   #define QUAN_META_GET_DIMENSION(Q) \
   template <typename U> \
   struct QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension) <\
      U, \
      typename quan::where_<is_static_unit<U> >::type \
   > : QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension)<typename U::abstract_quantity>{};

#else
    #define QUAN_META_GET_DIMENSION(Q) \
    template <typename StaticAbstractQuantity,typename StaticConversionFactor>\
    struct  QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension) <\
        unit<StaticAbstractQuantity,StaticConversionFactor>\
    > : QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension)<StaticAbstractQuantity>{};


#endif

    QUAN_META_GET_DIMENSION(length)
    QUAN_META_GET_DIMENSION(time)
    QUAN_META_GET_DIMENSION(mass)
    QUAN_META_GET_DIMENSION(temperature)
    QUAN_META_GET_DIMENSION(current)
    QUAN_META_GET_DIMENSION(substance)
    QUAN_META_GET_DIMENSION(intensity)

    #undef QUAN_META_GET_DIMENSION

    namespace impl{
#if 1
      template<
         typename UL,
         typename Op,
         typename UR
      >
      struct binary_op_impl<
         UL,
         Op,
         UR,
         typename quan::where_<
            and_<
               is_static_unit<UL>,
               is_static_unit<UR>
            >
         >::type
       > : unit<
           typename binary_op<
               typename UL::abstract_quantity,
               Op,
               typename UR::abstract_quantity
           >::type,
           typename binary_op<
               typename UL::conversion_factor,
               Op,
               typename UR::conversion_factor
           >::type
        >{};

#else
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
#endif
#if 1
      template <typename U, typename Exponent>
      struct binary_op_impl<
         U,
         pow ,
         Exponent,
         typename quan::where_<is_static_unit<U> >::type
      > : unit<
            typename  binary_op<
                typename U::abstract_quantity,
                pow,
                Exponent
            >::type,
            typename binary_op<
                typename U::conversion_factor,
                pow,
                Exponent
            >::type
        >{};

#else
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

#endif

    } // impl

#if 1
     template <typename Op,typename U>
     struct unary_operation<
         Op,U,
         typename quan::where_<is_static_unit<U> >::type
     > : unit<
        typename unary_operation<
            Op,
           typename U::abstract_quantity
        >::type,
        typename unary_operation<
            Op,
            typename U::conversion_factor
        >::type
    >{};

#else
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
#endif

} }//quan::meta

#endif
