#ifndef QUAN_ABSTRACT_QUANTITY_HPP_INCLUDED
#define QUAN_ABSTRACT_QUANTITY_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2005-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/config.hpp>

#include <quan/meta/abstract_quantity_fwd.hpp>
#include <quan/meta/si_unit_system.hpp>
#include <quan/meta/get_quantity_system.hpp>
#include <quan/archetypes/meta/static_rational_concept.hpp>
#include <quan/archetypes/meta/static_abstract_quantity_concept.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/macro/cat.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/if.hpp>

namespace quan{ namespace meta{

    template< 
        typename Dimension, 
        typename NamedQuantityTraits = anonymous_quantity_traits
    >
    struct abstract_quantity{
        typedef Dimension               dimension;
        typedef NamedQuantityTraits     named_quantity_traits;
        typedef abstract_quantity       type;
    };

// associated metafunction specialisations

    template <
        typename DimensionL,
        typename QuantityIdL,
        typename DimensionR,
        typename QuantityIdR
    >
    struct dimensionally_equivalent<
        abstract_quantity<
            DimensionL,
            QuantityIdL
        >,
        abstract_quantity<
            DimensionR,
            QuantityIdR
        >
    >
    : dimensionally_equivalent<
        DimensionL,
        DimensionR
    >{};

    template< 
        typename Dimension,
        typename NamedQuantityTraits
    > struct is_dimensionless<
        abstract_quantity<
            Dimension,
            NamedQuantityTraits
        >
    > : is_dimensionless<Dimension>{};

     template< 
        typename Dimension,
        typename NamedQuantityTraits
    > 
    struct name_anonymous_abstract_quantity<
         abstract_quantity<Dimension,NamedQuantityTraits>
    > : abstract_quantity<Dimension,NamedQuantityTraits>{};

    template <
        typename Dimension, 
        typename  NamedQuantityTraits
    >
    struct get_quantity_system<
        abstract_quantity<Dimension,NamedQuantityTraits>
    > : get_quantity_system<Dimension>{};

    template <
        typename Dimension, 
        typename NamedQuantityTraits
    >
    struct is_named_quantity<
        abstract_quantity<Dimension,NamedQuantityTraits>
    > : not_<
        std::is_same< 
            NamedQuantityTraits,
            anonymous_quantity_traits
        >
    >{};

    template <
        typename Dimension, 
        typename NamedQuantityTraits
    >
    struct get_named_quantity_traits<
        abstract_quantity<Dimension,NamedQuantityTraits>
    > : NamedQuantityTraits{};

    template <
        typename DimensionL, typename NamedQuantityTraits_L,
        typename DimensionR, typename NamedQuantityTraits_R
    >
    struct is_same_quantity<
        abstract_quantity<DimensionL,NamedQuantityTraits_L>,
        abstract_quantity<DimensionR,NamedQuantityTraits_R>
    > : quan::meta::and_<
        std::is_same<
            NamedQuantityTraits_L,
            NamedQuantityTraits_R
        >,
        dimensionally_equivalent<
            DimensionL,DimensionR
        >            
    >{};

    template <typename Dimension, typename NamedQuantityTraits>
    struct make_anonymous<
        abstract_quantity<Dimension,NamedQuantityTraits>
    > : abstract_quantity<
            Dimension,anonymous_quantity_traits
    >{};

      
    #define QUAN_META_GET_DIMENSION(Q) \
    template <typename Dimension, typename NamedQuantityTraits>\
    struct  QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension) <\
        abstract_quantity<Dimension,NamedQuantityTraits>\
    > : QUAN_MACRO_CAT(QUAN_MACRO_CAT(get_,Q),_dimension)<Dimension>{};

    QUAN_META_GET_DIMENSION(length)
    QUAN_META_GET_DIMENSION(time)
    QUAN_META_GET_DIMENSION(mass)
    QUAN_META_GET_DIMENSION(temperature)
    QUAN_META_GET_DIMENSION(current)
    QUAN_META_GET_DIMENSION(substance)
    QUAN_META_GET_DIMENSION(intensity)

    #undef QUAN_META_GET_DIMENSION

    template <typename Quantity>
    struct promote_anonymous_quantity{
         typedef Quantity type;
    };
    namespace detail{
        

        // result for addition
        // if L and R are equal -->  L (==R)
        // if L is anon and R not anon --> R
        // if R is anon and L not anon --> L
        // otherwise must be neither L or R anon, but not same --> anon
        template <typename L_Traits, typename R_Traits>
        struct plus_minus_quantity_traits{
           // typedef anonymous_abstract_quantity_Traits anonymous_Traits;
            struct l_is_anonymous : std::is_same<
                L_Traits,anonymous_quantity_traits
            >::type {};
            struct r_is_anonymous : std::is_same<
                R_Traits,anonymous_quantity_traits
            >::type {} ;

            typedef typename if_<
                std::is_same<
                    L_Traits,R_Traits
                >,
                L_Traits ,
                typename if_<
                    r_is_anonymous,
                    L_Traits,
                    typename if_<
                        l_is_anonymous,
                        R_Traits,
                        anonymous_quantity_traits
                    >::type
                >::type
            >::type  type;
        };

        template <typename Lhs,typename Op, typename Rhs>
        struct transform_abstract_quantity_traits{
            typedef anonymous_quantity_traits type;
        };

        template <typename Lhs, typename Rhs>
        struct transform_abstract_quantity_traits<Lhs,plus,Rhs>
        {
            typedef typename plus_minus_quantity_traits<Lhs,Rhs>::type type;
        };
        template <typename Lhs, typename Rhs>
        struct transform_abstract_quantity_traits<Lhs,minus,Rhs>
        {
            typedef typename plus_minus_quantity_traits<Lhs,Rhs>::type type;
        };
        
    }//detail

    namespace impl{

       template <
           typename DL, typename IDL,
           typename Op,
           typename DR, typename IDR
       >
       struct binary_op_impl<
           abstract_quantity<
               DL, IDL
           >,
           Op,
           abstract_quantity<
               DR, IDR
           >
       > :  abstract_quantity<
              typename binary_op<DL,Op,DR>::type,
              typename detail::transform_abstract_quantity_traits<IDL,Op,IDR>::type
            >{};

    } // impl

    template <typename D, typename ID, typename Op>
    struct unary_operation<
        Op,
        abstract_quantity<D,ID>
    >{
        typedef typename  //detail::do_promote_abstract_quantity<
            abstract_quantity<
               typename unary_operation<Op,D>::type,
               anonymous_quantity_traits
          //  >
        >::type type;
    };

    namespace impl{
       template <
           typename Dimension, 
           typename NamedQuantityTraits,
           typename Exp
       >
       struct binary_op_impl<
           abstract_quantity<
               Dimension, NamedQuantityTraits
           >,
           pow,
           Exp
       > : if_<
            eq_one<Exp>,
            abstract_quantity<Dimension,NamedQuantityTraits>,
            abstract_quantity<
               typename binary_op<Dimension,pow,Exp>::type,
               anonymous_quantity_traits
            >
       >{};
    } // impl

}}//quan::meta

#endif
