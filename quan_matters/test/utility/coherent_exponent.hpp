#ifndef QUAN_COHERENT_EXPONENT_HPP_INCLUDED
#define QUAN_COHERENT_EXPONENT_HPP_INCLUDED
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
ONLY USED by testing
    the coherent exponent represents the exponent 
    of the unit of a coherent quantity.
    e.g kilometers has a coherent exponent of 3.
    Rational exponents are also valid.
    The is_integer and is_positive are used 
    to determine how to best optimise when evaluating.
    IOW where possible an int type is returned.
*/
#include <quan/quantity_traits.hpp>
#include <quan/meta/digits10.hpp>

#include <quan_matters/test/utility/coherent_exponent_eval.hpp>


namespace quan{namespace concept_checking{
    // used to check that a coherent-exponent is computable
    namespace detail {
         template< int64_t Expnume, int64_t Expdenom>
         struct  CoherentExponentInRangeImpl{
            static const int maxd10 = quan::meta::digits10<quan::quantity_traits::default_value_type>::value;
            static const bool value 
             = ( ( Expdenom == 1) && (Expnume >= -maxd10) && (Expnume <= maxd10) )
               || ( ( Expnume <= maxd10 * Expdenom ) && ( Expnume >= - maxd10 * Expdenom ) );
/*
            = (( (Expdenom == 1 ) &&(Expnume >=  -(QUAN_MAX_PLUS1_POW10 -1)) && (Expnume <= (QUAN_MAX_PLUS1_POW10 -1))) 
                || ((Expnume <= (QUAN_MAX_PLUS1_POW10-1) * Expdenom)
                && (Expnume >= -(QUAN_MAX_PLUS1_POW10-1) * Expdenom)) )
*/
           // };
         };
    }// detail

     template< int64_t Expnume, int64_t Expdenom>
    ////////////////////////////////////////////////////////
     struct AssertCoherentExponentInRange
    ///////////////////////////////////////////////////////
     // Assertion fails if the coherent-exponent in a unit 
    // is too big or too small to be evaluated
    : Assert < (detail::CoherentExponentInRangeImpl<Expnume,Expdenom>::value)>
  {};
}}//quan::concept_checking

namespace quan{ namespace detail{

    template <int64_t N ,int64_t D>
    struct coherent_exponent : quan::concept_checking::AssertCoherentExponentInRange<N,D>
    {
         enum {numerator =  N,denominator = D };
         enum {  
            is_integer = ( denominator == 1 ),
            is_positive = ( numerator >= 0 ),
            is_zero  = ( numerator == 0)
         };
        
     //   enum{ 
        // ### Is this used anywhere ?? Why not
        //    param_check1 = (is_positive && is_integer),
         //#############
           static const bool  param_check = (is_positive? numerator:-numerator) 
            <= quan::meta::digits10<int64_t>::value;
      //  };
       
        template <typename R>
        struct eval : coherent_exponent_eval<
            R,
            numerator,
            denominator,
            param_check
        >{};
        typedef coherent_exponent type; 
    };
}}//quan::detail



 
#endif
