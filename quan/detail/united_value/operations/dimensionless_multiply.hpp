#ifndef QUAN_DETAIL_DIMENSIONLESS_MULTIPLY_HPP_INCLUDED
#define QUAN_DETAIL_DIMENSIONLESS_MULTIPLY_HPP_INCLUDED
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
    Dimensionless multiply 
    Because the Multipliers in the units are compile time Rational numbers
    It makes sense where possible to do maths on them as
    Rationals rather than converting to floats , as  math on rationals is
    lossless in terms of precision( as long as there is no overflow)

    Testing in VC7.1 seems to suggest that overflow in compile time
    integer maths causes an error and failed compilation at least at high warning levels
    , which though its shouldnt be relied on, does add a sanity check.
    This should be tested on other compilers too.

    Currently this approach has resulted in a large number of actual 
    specialisations of the calculation dependent on :
    Is the exponent zero.
    Is the exponent a positive integer
    Is the exponent a negative integer.
    Is the exponent a rational.
    Can the exponent be evaluated at compile time.
    Can the multipliers be reduced to one at compile time.
    Can the multipliers be eliminated (as they evaluate to 1).

    All these things do have an effect on the actual type and value of the result,
    as do the order of calculations and the idea behind all this complexity is
    to get more accuracy and repeatability
    But the complexities of working out which calculation is used
    may be too great. Maybe it would be better to provide one specification
    for the calculation for consistency. Any thoughts on that would be appreciated.

    The other issue is when it is possible to do an integer only calculation,
    as runtime math on integers can cause silent overflow. It may be better
    to force a conversion to a float and then use the numeric converter
    to convert back to an integer, which will throw an exception on out of range values.
    This will be quite slow however, so maybe this option should be a macro switch.
    
    
*/

#include <quan/detail/united_value/operations/dimensioned_multiply.hpp>
#include <quan/meta/pow_c.hpp>
#include <quan/detail/pow10_exponent.hpp>
#include <quan/detail/dimless_mul_exp_only.hpp>
#include <quan/detail/dimless_mul_exp_1mux.hpp>
#include <quan/detail/dimless_mul_exp_2mux.hpp>
#include <quan/detail/calc_triple.hpp>
#include <quan/meta/eq.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#include <cstdint>
#else
#include <stdint.h>
#endif
#include <quan/meta/integer_max.hpp>

namespace quan{namespace detail{

     template <typename Triple> struct multiply_preprocess;

       // specialisation of divide preprocess for single multiplier
    // If Exp is not zero
    // and mux is not 1
    // and in range
    // then rotate exp towrds zero
    // and adjust mux to suit.
    template <typename Exponent, typename Multiplier>
    struct multiply_preprocess<calc_triple<Exponent,Multiplier, quan::undefined> >
    {
// set to 0 to prevent rotation of exp and mux in preprocess
#if 1
        const static bool do_neg_value
        =    (( quan::meta::is_integer<Exponent>::value !=0 )
                && (quan::meta::numerator<Exponent>::value < 0)
                && ( quan::meta::neq_one<Multiplier>::value)
                && ( (quan::meta::denominator<Multiplier>::value) < (quan::meta::integer_max<int32_t>::value / 10) ));

        
        const static bool do_pos_value
        =(( quan::meta::is_integer<Exponent>::value !=0 )
                && (quan::meta::numerator<Exponent>::value > 0)
                && (quan::meta::neq_one<Multiplier>::value)
                && ((quan::meta::numerator<Multiplier>::value) < (quan::meta::integer_max<int32_t>::value / 10) ));

        typedef quan::meta::bool_<do_neg_value> do_neg;
        typedef quan::meta::bool_<do_pos_value> do_pos;

        typedef calc_triple<
            typename  quan::meta::eval_if<
               do_neg
                  ,quan::meta::binary_op<
                     Exponent, quan::meta::plus,quan::meta::rational<1>
                  >
               ,do_pos
                  ,quan::meta::binary_op<
                     Exponent, quan::meta::minus,quan::meta::rational<1>
                  >
               ,Exponent
            >::type,
            typename quan::meta::eval_if< // prevent math op if maybe not in range
               do_neg
                  ,quan::meta::binary_op<
                     Multiplier, 
                     quan::meta::divides,
                     quan::meta::rational<10>
                  >
               ,do_pos
                  ,quan::meta::binary_op<
                     Multiplier, 
                     quan::meta::times,
                     quan::meta::rational<10>
                  >
               ,Multiplier
            >::type
            ,quan::undefined
        > type;
            
#else
    typedef calc_triple<Exponent,Multiplier, quan::undefined> type;
#endif       
    };

    // default divide_preprocess actually
    // calls specialisation
    // to do the real work.
    template <typename Exponent, typename Multiplier_L, typename Multiplier_R>
    struct multiply_preprocess<calc_triple<Exponent,Multiplier_L,Multiplier_R> >{

        // defer to specialise version
        // by using mpl::void_
        // Left hand multiplier
        typedef multiply_preprocess<
            calc_triple<
                Exponent,
                Multiplier_L,
                quan::undefined
            >
        > first;
        // defers to specialise version
        // by using mpl::void_
        typedef multiply_preprocess<
            calc_triple<
                typename first::type::exponent,
                Multiplier_R,
                quan::undefined
            >
        >  second;
        // now do other multiplier
        // again defer to specialised version
        typedef calc_triple<
            typename second::type::exponent,
            typename first::type::multiplier_L, 
            typename second::type::multiplier_L
        > type; 
    };

    // if here, the exponent of the partial result is non zero.
    // Decide whether the multipliers can be reduced to
    // one at compiletime

    template <
        typename Exponent, 
        typename Multiplier_L,
        typename Multiplier_R
    >
    struct dimensionless_multiply_exp_mux ;

    template <
        typename Exponent, 
        typename Multiplier
    >
    struct dimensionless_multiply_exp_mux<Exponent, Multiplier, quan::undefined>
    {
        typedef calc_triple<
            Exponent,
            Multiplier,
            quan::undefined
        > preprocessor_input;
        typedef typename multiply_preprocess<
            preprocessor_input
        >::type preprocessor_output;
       
        // Exponent may be zero
        typedef typename  quan::meta::eval_if<
            std::is_same<preprocessor_input,preprocessor_output>,
            quan::meta::eval_if<
                quan::meta::eq_zero<Exponent>,
                dimensioned_multiply_function<Multiplier>,
                dimensionless_multiply_exp_1mux<
                    Exponent,
                    Multiplier
                >
            >, // if inputs changed recurse
            dimensionless_multiply_exp_mux<
                typename preprocessor_output::exponent,
                typename preprocessor_output::multiplier_L,
                typename preprocessor_output::multiplier_R
            >
        >::type  type;
    } ;


    template <
        typename Exponent, 
        typename Multiplier_L,
        typename Multiplier_R
    >
    struct dimensionless_multiply_exp_mux {
        // If the Multipliers are multipliable at compile time
        // or the numerator of one can cancel with denominator of the other
        // or one or other is equal to 1
        // then reduce them to one multiplier.
        // rational itself will do further normalisataion on a single
        // rational multiplier and may reduce it to 1, when it can
        // be eliminated.
        typedef typename quan::meta::eval_if<
            quan::meta::and_<
                elements_in_multipliable_range<Multiplier_L>,
                elements_in_multipliable_range<Multiplier_R>
            >,
               quan::meta::binary_op<
                       Multiplier_L,quan::meta::times,Multiplier_R
               >,    
            quan::meta::eq_<
               quan::meta::numerator<Multiplier_L>,
               quan::meta::denominator<Multiplier_R>
            >,
               quan::meta::rational<
                  quan::meta::numerator<Multiplier_R>::value,
                  quan::meta::denominator<Multiplier_L>::value
               >,
            quan::meta::eq_<
               quan::meta::numerator<Multiplier_R>,
               quan::meta::denominator<Multiplier_L>
            >,
               quan::meta::rational<
                  quan::meta::numerator<Multiplier_L>::value,
                  quan::meta::denominator<Multiplier_R>::value
               >,
            quan::meta::eq_one<Multiplier_R>,
               Multiplier_L,
            quan::meta::eq_one<Multiplier_L>,
               Multiplier_R,
            quan::undefined   
        >::type compile_time_multiplier_type;

        /*typedef typename quan::meta::eval_if<
            std::is_same<
                compile_time_multiplier_type, quan::undefined 
            >,
            dimensionless_multiply_exp_2mux<Exponent,Multiplier_L,Multiplier_R>,
            dimensionless_multiply_exp_1mux<Exponent,compile_time_multiplier_type>
         >::type type;   */

    /////////////////////////////////////////////////
        typedef typename quan::meta::eval_if<
            std::is_same<
                compile_time_multiplier_type, quan::undefined 
            >,
               calc_triple<Exponent, Multiplier_L, Multiplier_R> ,
            calc_triple<Exponent,compile_time_multiplier_type, quan::undefined>
        >::type preprocessor_input;
        // apply preprocessing to normalise
        // exponent and multipliers towards zero
        typedef typename multiply_preprocess<
            preprocessor_input
        >::type preprocessor_output;  
        // if preprocessing has made mods, then recurse
        typedef typename quan::meta::eval_if<
            std::is_same<
                preprocessor_input, preprocessor_output
            >, // check whether one mux has been optimised out or not
            // If compile_time_multiplier_type == quan::undefined, then not
            quan::meta::eval_if<
               std::is_same< compile_time_multiplier_type, quan::undefined>,
                  quan::meta::eval_if<
                     quan::meta::eq_zero<Exponent>,
                        dimensioned_multiply1<Multiplier_L,Multiplier_R>,
                     dimensionless_multiply_exp_2mux<
                        Exponent,
                        Multiplier_L,
                        Multiplier_R
                     >
                  >,
               quan::meta::eq_zero<Exponent>, 
//**********
// add condition if mux ==1 for compile_time_multiplier_type?
// Looks like its checked by dimensionless_multiply_exp_1mux<
//********
                  dimensioned_multiply_function<compile_time_multiplier_type>,
               dimensionless_multiply_exp_1mux<Exponent,compile_time_multiplier_type>
              //  >
            >, // if preprocessing has modified the params,  recurse.
            // note that the version of dimensionless_divide_exp_mux
            // specialised on
            // right multiplier being mpl::void_
            // may be called here
            dimensionless_multiply_exp_mux<
                typename preprocessor_output::exponent,
                typename preprocessor_output::multiplier_L,
                typename preprocessor_output::multiplier_R
            >
       >::type type;        
////////////////////////////////////////           
    };

    /*
        If the resulting  exponent of addition of the exponents of
        StaticUnit_L and StaticUnit_r is 0 then the calc is the same as 
        dimensioned multiply,
        else 
    */
    template <typename StaticUnit_L, typename StaticUnit_R>
    struct dimensionless_multiply_helper {
        typedef typename quan::meta::binary_op<
            typename StaticUnit_L::exponent,
            quan::meta::plus,
            typename StaticUnit_R::exponent
        >::type exponent;
        typedef typename quan::meta::eval_if<
            quan::meta::eq_zero<exponent>,
               dimensioned_multiply1<
                   typename StaticUnit_L::multiplier::type, 
                   typename StaticUnit_R::multiplier::type 
               >,
            dimensionless_multiply_exp_mux<
                exponent,
                typename StaticUnit_L::multiplier::type, 
                typename StaticUnit_R::multiplier::type 
            >
        >::type type;
    };

     template <typename StaticUnit_L, typename StaticUnit_R>
     struct dimensionless_multiply1 : dimensionless_multiply_helper<
        StaticUnit_L,StaticUnit_R
     >::type{};

}}//quan::detail
#endif
