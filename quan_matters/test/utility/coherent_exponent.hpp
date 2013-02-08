#ifndef QUAN_COHERENT_EXPONENT_HPP_INCLUDED
#define QUAN_COHERENT_EXPONENT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

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
         template< QUAN_INT32 Expnume, QUAN_INT32 Expdenom>
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

     template< QUAN_INT32 Expnume, QUAN_INT32 Expdenom>
    ////////////////////////////////////////////////////////
     struct AssertCoherentExponentInRange
    ///////////////////////////////////////////////////////
     // Assertion fails if the coherent-exponent in a unit 
    // is too big or too small to be evaluated
    : Assert < (detail::CoherentExponentInRangeImpl<Expnume,Expdenom>::value)>
  {};
}}//quan::concept_checking

namespace quan{ namespace detail{

    template <QUAN_INT32 N ,QUAN_INT32 D>
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
            <= quan::meta::digits10<QUAN_INT32>::value;
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
