#ifndef QUAN_FIXED_QUANTITY_DIVIDE_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_DIVIDE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    division of fixed_quantity
*/

#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/abstract_quantity.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/detail/united_value/operations/dimensioned_divide.hpp>
#include <quan/detail/united_value/operations/dimensionless_divide.hpp>
#include <quan/meta/eval_if.hpp>

namespace quan{ namespace meta{

        template <
            typename StaticUnit_L ,
            typename NumericType_L ,
            typename StaticUnit_R ,
            typename NumericType_R
        > struct binary_op<
            fixed_quantity<
                StaticUnit_L ,
                NumericType_L
            > ,
            divides ,
            fixed_quantity<
                StaticUnit_R ,
                NumericType_R
            >
        >{
            typedef typename binary_op<
                StaticUnit_L ,
                divides ,
                StaticUnit_R 
// slightly dodgy. used in divide function
            >::type def_unit;
            typedef typename eval_if<
               and_<
                  not_<is_named_quantity<def_unit> >,
                  is_si<def_unit>
               >,
               name_anonymous_unit<def_unit>,
               def_unit
            >::type mod_units;
            typedef typename binary_op<
                NumericType_L,
                divides, 
                NumericType_R
            >::type value_type;
            typedef typename fixed_quantity<
                mod_units ,
                value_type
            >::type type;
        };
}}//quan::meta

namespace quan{ 

    template <
        typename StaticUnit_L,typename NumericType_L,
        typename StaticUnit_R,typename NumericType_R
    >
    QUAN_CONSTEXPR
    inline 
    typename quan ::meta::binary_op<
        quan ::fixed_quantity<StaticUnit_L,NumericType_L>,
        quan ::meta::divides,
        quan ::fixed_quantity<StaticUnit_R,NumericType_R>
    >::type
    operator / (
        quan ::fixed_quantity<StaticUnit_L,NumericType_L> const & lhs,
        quan ::fixed_quantity<StaticUnit_R,NumericType_R> const & rhs
    ) 
    {
        typedef typename quan ::meta::binary_op<
            quan ::fixed_quantity<StaticUnit_L,NumericType_L>,
            quan ::meta::divides,
            quan ::fixed_quantity<StaticUnit_R,NumericType_R>
        >::type result_type;
        typedef typename quan ::meta::get_conversion_factor<
            StaticUnit_L
        >::type conv_factor_L;
        typedef typename quan ::meta::get_conversion_factor<
            StaticUnit_R
        >::type conv_factor_R;
        typedef typename quan ::meta::binary_op<
                StaticUnit_L ,
                quan ::meta::divides ,
                StaticUnit_R 
        >::type result_unit;
        typedef typename quan ::meta::binary_op<
                NumericType_L ,
                quan ::meta::divides ,
                NumericType_R 
        >::type result_value_type;
        typedef typename quan::meta::eval_if<
            quan ::meta::is_dimensionless<
                result_unit 
            > ,
            quan ::detail::dimensionless_divide1<conv_factor_L,conv_factor_R>,
            quan ::detail::dimensioned_divide<
                typename quan ::meta::get_multiplier<
                    conv_factor_L
                >::type,
                typename quan ::meta::get_multiplier<
                    conv_factor_R
                >::type
            >
        >::type functor;
        typedef typename functor:: template eval<
            NumericType_L,NumericType_R
        > func_type;
        typedef typename quan ::quantity_traits:: template value_type_converter<
            result_value_type, typename func_type::result_type
        > convert_type;
    
       return  result_type {
           convert_type{} ( func_type{}(lhs.numeric_value(),rhs.numeric_value()))
        };
    }

} //quan
    

#endif
