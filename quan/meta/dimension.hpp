#ifndef QUAN_META_DIMENSION_HPP_INCLUDED
#define QUAN_META_DIMENSION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    dimension of a fixed_quantity in the default implementation
*/

#include <quan/meta/binary_op.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/numerator.hpp>
#include <quan/meta/unary_operation.hpp>
#include <quan/meta/binary_log_transform.hpp>
#include <quan/archetypes/meta/static_abstract_quantity_concept.hpp>
#include <quan/meta/bool.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/not.hpp>
#include <quan/meta/or.hpp>

namespace quan{namespace meta{

    template <
        typename R1,
        typename R2,
        typename R3,
        typename R4,
        typename R5,
        typename R6,
        typename R7
    >
    struct dimension{
        typedef typename R1::type d1;
        typedef typename R2::type d2;
        typedef typename R3::type d3;
        typedef typename R4::type d4;
        typedef typename R5::type d5;
        typedef typename R6::type d6;
        typedef typename R7::type d7; 
        typedef dimension<d1,d2,d3,d4,d5,d6,d7> type;
    };

    template <
        typename R1,
        typename R2,
        typename R3,
        typename R4,
        typename R5,
        typename R6,
        typename R7
    >
    struct is_dimensionless<
        dimension<R1,R2,R3,R4,R5,R6,R7>
    > : and_<
            not_<numerator<R1> >,
            not_<numerator<R2> >,
            not_<numerator<R3> >,
            not_<numerator<R4> >,
            not_<numerator<R5> >,
            not_<numerator<R6> >,
            not_<numerator<R7> >
         > {};
      
    template <
        typename D1L,
        typename D2L,
        typename D3L,
        typename D4L,
        typename D5L,
        typename D6L,
        typename D7L,
        typename D1R,
        typename D2R,
        typename D3R,
        typename D4R,
        typename D5R,
        typename D6R,
        typename D7R
    >
    struct dimensionally_equivalent<
        dimension<D1L,D2L,D3L,D4L,D5L,D6L,D7L>,
        dimension<D1R,D2R,D3R,D4R,D5R,D6R,D7R>
    > : and_<
            eq_<D1L,D1R>,
            eq_<D2L,D2R>,
            eq_<D3L,D3R>,
            eq_<D4L,D4R>,
            eq_<D5L,D5R>,
            eq_<D6L,D6R>,
            eq_<D7L,D7R>       
         >{};
     
    template <typename T>
    struct get_quantity_system;   

   struct si_unit_system;

    template <
        typename R1,
        typename R2,
        typename R3,
        typename R4,
        typename R5,
        typename R6,
        typename R7
    >
    struct get_quantity_system<
         dimension<R1,R2,R3,R4,R5,R6,R7>
    >{
        typedef si_unit_system type;
    };    

    template <
        typename D1L,
        typename D2L,
        typename D3L,
        typename D4L,
        typename D5L,
        typename D6L,
        typename D7L,
        typename Op,
        typename D1R,
        typename D2R,
        typename D3R,
        typename D4R,
        typename D5R,
        typename D6R,
        typename D7R
    >
    struct binary_op<
        dimension<
            D1L,
            D2L,
            D3L,
            D4L,
            D5L,
            D6L,
            D7L
        >,
        Op,
        dimension<
            D1R,
            D2R,
            D3R,
            D4R,
            D5R,
            D6R,
            D7R
        > 
    > : dimension <
        typename binary_log_transform<D1L,Op,D1R>::type,
        typename binary_log_transform<D2L,Op,D2R>::type,
        typename binary_log_transform<D3L,Op,D3R>::type,
        typename binary_log_transform<D4L,Op,D4R>::type,
        typename binary_log_transform<D5L,Op,D5R>::type,
        typename binary_log_transform<D6L,Op,D6R>::type,
        typename binary_log_transform<D7L,Op,D7R>::type
    >{};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7,
        typename Exp
    >
    struct binary_op<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >,
        pow,
        Exp
    > : dimension<
        typename binary_op<D1,times,Exp>::type,
        typename binary_op<D2,times,Exp>::type,
        typename binary_op<D3,times,Exp>::type,
        typename binary_op<D4,times,Exp>::type,
        typename binary_op<D5,times,Exp>::type,
        typename binary_op<D6,times,Exp>::type,
        typename binary_op<D7,times,Exp>::type
     >{};
    
    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    >
    struct unary_operation<
        reciprocal,
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    >{
        typedef dimension<
            typename unary_operation<negate,D1>::type,
            typename unary_operation<negate,D2>::type,
            typename unary_operation<negate,D3>::type,
            typename unary_operation<negate,D4>::type,
            typename unary_operation<negate,D5>::type,
            typename unary_operation<negate,D6>::type,
            typename unary_operation<negate,D7>::type
        > type;
    };

//element access
    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_length_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D1 {};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_time_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D2 {};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_mass_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D3 {};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_temperature_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D4 {};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_current_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D5 {};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_substance_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D6 {};

    template <
        typename D1,
        typename D2,
        typename D3,
        typename D4,
        typename D5,
        typename D6,
        typename D7
    > struct get_intensity_dimension<
        dimension<
            D1, D2, D3, D4, D5, D6, D7
        >
    > : D7 {};
   
}}//quan::meta

#endif
