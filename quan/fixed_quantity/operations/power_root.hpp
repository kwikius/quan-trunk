#ifndef QUAN_FIXED_QUANTITY_POWER_ROOT_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_POWER_ROOT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

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

#if defined  __AVR__
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
 
        template <
            int64_t N,
            int64_t D,
            typename StaticUnit,
            typename NumericType
        >
        struct binary_op<
            fixed_quantity<
                StaticUnit,
                NumericType
            >,
            pow,
            rational<N,D>
        >{
            typedef typename rational<N,D>::type exp;
            typedef typename eval_if<
                eq_<exp,rational<0> >,
                identity<int>,
                typename eval_if<
                   eq_<exp,rational<1> >,
                    identity<
                        fixed_quantity<
                           StaticUnit,
                           NumericType
                        >
                    >,
                    detail::pow_binary_operation_impl<
                        exp,
                        StaticUnit,
                        NumericType
                    >
                >::type
            >::type type;    
        };

    }// meta

   /* template<int64_t N> struct deduced_int{};
    template<int64_t N, int64_t D> struct deduced_fraction{};*/

    template <
        int64_t N,
        int64_t D
    >
    inline
    double
    pow( double const& v)
    {
#ifndef __AVR__  
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
    inline
    double
    pow( int64_t const& v)
    {
 #ifndef __AVR__
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
    inline
    double
    pow( int32_t const& v)
    {
 #ifndef __AVR__
           return std::pow(
#else
          return ::pow(
#endif
            static_cast<double>( v ),
            static_cast<double>( N ) / D
        );         
    }

    //template <
    //    int64_t N,
    //    int64_t D,
    //    typename T
    //>
    //inline
    //typename quan::where_<
    //    quan::meta::and_<
    //        quan::meta::is_numeric<T>,
    //       quan::meta::not_<
    //            std::is_fundamental<T>
    //        >
    //    >,
    //    typename quan::meta::binary_op<
    //        T,
    //        quan::meta::pow,
    //        quan::meta::rational<N,D>
    //    >::type
    //>::type
    //pow (T const & v)
    //{
    //    typedef typename quan::meta::binary_op<
    //        T,
    //        quan::meta::pow,
    //        quan::meta::rational<N,D>
    //    >::type result_type;
    //    result_type result 
    //    = pow(v,static_cast<T>( N ) / static_cast<T>(D)); 
    //      return result;    
    //}
    
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
            QUAN_CONSTEXPR result_type operator()(Q const & in)
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
            QUAN_CONSTEXPR result_type operator()(Q const & in)
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
            QUAN_CONSTEXPR result_type operator()(Q const & in)
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
            QUAN_CONSTEXPR result_type operator()(Q const & in)
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
            QUAN_CONSTEXPR result_type operator()(Q const & in)
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

