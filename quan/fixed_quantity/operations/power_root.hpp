#ifndef QUAN_FIXED_QUANTITY_POWER_ROOT_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_POWER_ROOT_HPP_INCLUDED
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
    power and root functions for inbuilts and fixed_quantity
    for inbuilts pow<N>(v) to bring in to line with
*/
#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/identity.hpp>

#if defined  QUAN_AVR_NO_CPP_STDLIB
  #include <math.h>
#else
#include <cmath>
#endif

namespace quan { 

    namespace meta{

         namespace detail{

            template <
               typename Exp,
               typename StaticUnit,
               typename NumericType
            >
            struct pow_binary_operation_impl{
               typedef typename quan::meta::binary_op<
                  StaticUnit,
                  pow,
                  Exp
               >::type def_unit;
               typedef typename eval_if<
                  and_<
                     not_<is_named_quantity<def_unit> >,
                     is_si<def_unit>
                  >,
                  name_anonymous_unit<def_unit>,
                  def_unit
               >::type mod_units;
               typedef typename quan::fixed_quantity <
                  mod_units,
                  typename binary_op<
                     NumericType,
                     pow,
                     Exp
                  >::type
               >::type type;
            };
         }
 
       namespace impl{
        template <
            int64_t N,
            int64_t D,
            typename StaticUnit,
            typename NumericType
        >
        struct binary_op_impl<
            fixed_quantity<
                StaticUnit,
                NumericType
            >,
            pow,
            rational<N,D>
        >{
            typedef typename rational<N,D>::type exp;

            typedef typename eval_if<
               eq_<exp,rational<0> >
                  ,identity<int>
               ,eq_<exp,rational<1> >
                  ,identity<
                     fixed_quantity<
                        StaticUnit,
                        NumericType
                     >
                  >
               ,detail::pow_binary_operation_impl<
                  exp,
                  StaticUnit,
                  NumericType
               >
            >::type type;  
  
        };
      } // impl

    }// meta

   /* template<int64_t N> struct deduced_int{};
    template<int64_t N, int64_t D> struct deduced_fraction{};*/

    template <
        int64_t N,
        int64_t D
    >
    QUAN_CONSTEXPR inline
    double
    pow( double const& v)
    {
#ifndef QUAN_AVR_NO_CPP_STDLIB  
        return std::pow(
#else   
        return ::pow(
#endif
             v ,
            static_cast<double>( N ) / D
        );      
    }
    template <
        int64_t N,
        int64_t D
    >
    QUAN_CONSTEXPR inline
    double
    pow( int64_t const& v)
    {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           return std::pow(
#else
          return ::pow(
#endif
            static_cast<double>( v ),
            static_cast<double>( N ) / D
        );         
    }

        template <
        int64_t N,
        int64_t D
    >
    QUAN_CONSTEXPR inline 
    double
    pow( int32_t const& v)
    {
 #ifndef QUAN_AVR_NO_CPP_STDLIB
           return std::pow(
#else
          return ::pow(
#endif
            static_cast<double>( v ),
            static_cast<double>( N ) / D
        );         
    }

    namespace detail{

        template <
           typename Q,
           typename Rational
        >
        struct pow_fixed_quantity_impl{
            typedef typename quan ::meta::get_nearest_si<
               Q
            >::type coherent_pq;
            typedef typename quan ::meta::binary_op<
                coherent_pq,
                quan ::meta::pow,
                typename Rational::type
            >::type result_type;
            QUAN_CONSTEXPR result_type operator()(Q const & in) const
            {
              //  coherent_pq t = in;
                return result_type{
                    quan ::pow<
                        Rational::numerator,Rational::denominator
                    >(coherent_pq{in}.numeric_value())
                };
            }
        };

        template <
           typename Q
        >
        struct pow_fixed_quantity_impl<
            Q, quan ::meta::rational<0>
        >{
            typedef int result_type;
            QUAN_CONSTEXPR result_type operator()(Q const & in) const
            {
                return 1;
            }
        };

        template <
           typename Q
        >
        struct pow_fixed_quantity_impl<
            Q,quan ::meta::rational<1>
        >{
            typedef Q result_type;
            QUAN_CONSTEXPR result_type operator()(Q const & in) const
            {
                return in;
            }
        };


        template <
           typename Q
        >
        struct pow_fixed_quantity_impl<
            Q,quan ::meta::rational<2>
        >{
            typedef  typename quan::meta::binary_op<
                Q, quan::meta::pow, quan::meta::rational<2>
            >::type result_type;
            QUAN_CONSTEXPR result_type operator()(Q const & in) const
            {
               return in * in;
            }
        };

        template <
           typename Q
        >
        struct pow_fixed_quantity_impl<
            Q,quan ::meta::rational<3>
        >{
            typedef  typename quan::meta::binary_op<
                Q, quan::meta::pow, quan::meta::rational<3>
            >::type result_type;
            QUAN_CONSTEXPR result_type operator()(Q const & in) const
            {
                return in * in * in;
            }
        };

    }//detail

    template <
        int64_t N,
        int64_t D,
        typename StaticUnit,
        typename NumericType
    >
    inline QUAN_CONSTEXPR
    typename meta::binary_op<
        fixed_quantity<
            StaticUnit,
            NumericType
        >,
        meta::pow,
        meta::rational<N,D>
    >::type
    pow(
        fixed_quantity<
            StaticUnit,
            NumericType
        > const & pq 
    )
    {   
        typedef fixed_quantity<
                StaticUnit,
                NumericType
        > orig_quantity_type;
        typedef detail::pow_fixed_quantity_impl<
            orig_quantity_type,
            typename meta::rational<N,D>::type
        > pow_impl;
       // typename pow_impl::result_type result
        return pow_impl{}(pq);
       // return result;
    }

    template <
        int64_t N,
        typename T
    >
    inline QUAN_CONSTEXPR
    typename meta::binary_op<
        T, 
        meta::pow,
        meta::rational<N,1>
    >::type
    pow( T const & t)
    {
         return quan ::pow<N,1>(t);
    }

    template <typename T>
    inline QUAN_CONSTEXPR
    typename meta::binary_op<
        T,
        meta::pow,
        meta::rational<1,2>
    >::type
    sqrt(T const & v)
    {
      return quan ::pow<1,2>(v);
    }
  
#ifdef QUAN_TR1_COMPLIANT

    template <typename T>
    inline QUAN_CONSTEXPR
    typename meta::binary_op<
        T,
        meta::pow,
        meta::rational<1,3>
    >::type
    cbrt(T const & v)
    {
      return quan ::pow<1,3>(v);
    }

#endif
  
} //quan

#endif

