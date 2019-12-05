#ifndef QUAN_META_CONVERSION_FACTOR_HPP_INCLUDED
#define QUAN_META_CONVERSION_FACTOR_HPP_INCLUDED
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
    meta::conversion_factor is the implementation supplied model of ConversionFactor
*/

#include <quan/config.hpp>
#include <quan/meta/conversion_factor_fwd.hpp>
#include <quan/archetypes/meta/static_numeric_concept.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/rational.hpp>
#include <quan/archetypes/meta/conversion_factor_concept.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/lt.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/int32.hpp>
#include <quan/meta/bool/true.hpp>

namespace quan{namespace meta{

    template <
        typename Exponent = rational<0>,
        typename Multiplier= rational<1>,
        typename Id = quan::meta::int32<0>
    >
    struct conversion_factor{
        typedef typename Exponent::type       exponent;
        typedef typename Multiplier::type     multiplier;
        typedef Id                            id;
        typedef conversion_factor<exponent,multiplier,id>  type;
    };

    template <typename E,typename M, typename Id>
    struct is_conversion_factor<conversion_factor<E,M,Id> > : quan::meta::true_{};

    template <
        typename Exponent,
        typename Multiplier,
        typename Id
    >
    struct get_exponent<
        conversion_factor<Exponent,Multiplier,Id>
    > : Exponent{};

    template <
        typename Exponent,
        typename Multiplier,
        typename Id
    >
    struct get_multiplier<
        conversion_factor<Exponent,Multiplier,Id>
    > : Multiplier{};
    

    template <
        typename Exponent,
        typename Multiplier,
        typename Id
    >
    struct get_nearest_si<
        conversion_factor<Exponent,Multiplier,Id>
    >{
        typedef conversion_factor<
            typename Exponent::type,
            rational<1>,
            quan::meta::int32<0>
        > type;
    };

    template <
        typename Exponent,
        typename Multiplier,
        typename Id
    > 
    struct is_si<
        conversion_factor<Exponent,Multiplier,Id>
    > : and_<
        eq_one<Multiplier>,
        eq_zero<Id>
    >{};

    template <
        typename ExponentL,
        typename MultiplierL,
        typename IdL,
        typename ExponentR,
        typename MultiplierR,
        typename IdR
    > struct get_finest_grained<
        conversion_factor<ExponentL,MultiplierL,IdL>,
        conversion_factor<ExponentR,MultiplierR,IdR>
    >{
        typedef typename conversion_factor<ExponentL,MultiplierL,IdL>::type lhs;
        typedef typename conversion_factor<ExponentR,MultiplierR,IdR>::type rhs;
        typedef typename if_<
            lt_<
                typename lhs::exponent,
                typename rhs::exponent
            >,
            lhs,
            rhs
        >::type type;
     };
     
    template <
        typename Exponent_L,
        typename Multiplier_L,
        typename Id_L,
        typename Exponent_R,
        typename Multiplier_R,
        typename Id_R
    > struct is_math_same_conversion_factor<
        conversion_factor<Exponent_L,Multiplier_L,Id_L>,
        conversion_factor<Exponent_R,Multiplier_R,Id_R>
    > : quan::meta::and_<
        eq_<Exponent_L,Exponent_R>,
        eq_<Multiplier_L,Multiplier_R>
    >{};
    
    
    namespace detail{

        template <typename Lhs , typename Rhs>
        struct plus_minus_unit{
           
            typedef typename get_finest_grained< 
                    Lhs, Rhs
            >::type finest_grained_type;

            typedef typename get_nearest_si<
                finest_grained_type
            >::type  coherent_type;

            typedef typename eval_if<
            // if one or both coherent use coherent type as result
                or_<
                    is_si<Lhs>,
                    is_si<Rhs>
                >,
                coherent_type,
                //if here both incoherent
                typename if_<  
                  // if exponent and multiplier are same
                  // select Lhs 
                  // otherwise finest grained
                     and_<   
                           eq_<
                              typename Lhs::exponent,
                              typename Rhs::exponent
                           >,
                           eq_<
                              typename Lhs::multiplier,
                              typename Rhs::multiplier
                           >
                     >,
                     Lhs, 
                     finest_grained_type
                >::type       
            >::type type;
        };

        template< 
            typename QuantityUnit,
            typename PowType
        >
        struct pow_conversion_factor{
            typedef typename eval_if<
                eq_one<PowType>,
                QuantityUnit,
                conversion_factor<
                    typename binary_op<
                        typename QuantityUnit::exponent,
                        times,
                        typename PowType::type
                    >::type,
                  rational<1>, // si 
                  quan::meta::int32<0> // si
                >
            >::type type;
        };
        
    }//detail

    namespace impl {
      //+
       template<
           typename LhsExponent,
           typename LhsMultiplier, 
           typename LhsId,
           typename RhsExponent,
           typename RhsMultiplier, 
           typename RhsId
       >
       struct binary_op_impl<
           conversion_factor<
                   LhsExponent,
                   LhsMultiplier, 
                   LhsId
           >,
           plus,
           conversion_factor<
                   RhsExponent,
                   RhsMultiplier, 
                   RhsId
           >
       > 
       : detail::plus_minus_unit<
           conversion_factor<
                   LhsExponent,
                   LhsMultiplier, 
                   LhsId
           >,
           conversion_factor<
               RhsExponent,
               RhsMultiplier, 
               RhsId
           >
       >{};
   //-
       template<
           typename LhsExponent,
           typename LhsMultiplier, 
           typename LhsId,
           typename RhsExponent,
           typename RhsMultiplier, 
           typename RhsId
       >
       struct binary_op_impl<
           conversion_factor<
                   LhsExponent,
                   LhsMultiplier, 
                   LhsId
           >,
           minus,
           conversion_factor<
                   RhsExponent,
                   RhsMultiplier, 
                   RhsId
           >
       > : detail::plus_minus_unit<
           conversion_factor<
                   LhsExponent,
                   LhsMultiplier, 
                   LhsId
           >,
           conversion_factor<
               RhsExponent,
               RhsMultiplier, 
               RhsId
           >
       >{};
   //*
       template<
           typename LhsExponent,
           typename LhsMultiplier, 
           typename LhsId,
           typename RhsExponent,
           typename RhsMultiplier, 
           typename RhsId
       >
       struct binary_op_impl<
           conversion_factor<
                   LhsExponent,
                   LhsMultiplier, 
                   LhsId
           >,
           times,
           conversion_factor<
                   RhsExponent,
                   RhsMultiplier, 
                   RhsId
           >
       >{ 
       // in multiplication
       // add exponents
       // transform multiplier and id to default
           typedef conversion_factor<
               typename binary_op<
                   LhsExponent,
                   plus,
                   RhsExponent
               >::type,
               rational<1>,
               quan::meta::int32<0>
           >  type;
       };

       template<
           typename LhsExponent,
           typename LhsMultiplier, 
           typename LhsId,
           typename RhsExponent,
           typename RhsMultiplier, 
           typename RhsId
       >
       struct binary_op_impl<
           conversion_factor<
                   LhsExponent,
                   LhsMultiplier, 
                   LhsId
           >,
           divides,
           conversion_factor<
                   RhsExponent,
                   RhsMultiplier, 
                   RhsId
           >
       >{ 
       // in division
       // subtract exponents
       // transform multiplier and id to default
       // type is always a coherent quantity
           typedef  conversion_factor<
               typename binary_op<
                   LhsExponent,
                   minus,
                   RhsExponent
               >::type,
               rational<1>,
               quan::meta::int32<0>
           > type;
       };
   //^
       template<
           typename Exponent,
           typename Multiplier, 
           typename Id,
           typename PowType
       >
       struct binary_op_impl<
           quan::meta::conversion_factor<
                   Exponent,
                   Multiplier, 
                   Id
           >,
           pow,
           PowType 
       > : detail::pow_conversion_factor<
           conversion_factor<
                   Exponent,
                   Multiplier, 
                   Id
           >,
           PowType
       >{};
   } // impl
// 1/
    template<
        typename Exponent,
        typename Multiplier, 
        typename Id
    >
    struct unary_operation<
        reciprocal,
        conversion_factor<
                Exponent,
                Multiplier, 
                Id
        >
    >{ 
        typedef conversion_factor<
            typename unary_operation<
                negate,
                Exponent
            >::type,
           rational<1>,
           quan::meta::int32<0>
        > type;
    };
           
}}//quan::meta

#endif
