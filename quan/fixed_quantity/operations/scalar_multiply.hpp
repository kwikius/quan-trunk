#ifndef QUAN_FIXED_QUANTITY_SCALAR_MUL_HPP_INCLUDED
#define QUAN_FIXED_QUANTITY_SCALAR_MUL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    multiply fixed_quantity by numeric
*/
#include <quan/config.hpp>
#include <quan/fixed_quantity/fixed_quantity.hpp>
#include <quan/meta/binary_op.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/and.hpp>

namespace quan{ namespace meta{

    template<
        typename StaticUnit,
        typename NumericType,
        typename NumericType_1
    >
    struct binary_op<
        quan::fixed_quantity<
            StaticUnit,
            NumericType
        >,
        times,
        NumericType_1,
        typename quan::where_<
            is_numeric<NumericType_1>
        >::type
    >{
        typedef typename quan::fixed_quantity<
            StaticUnit,
            typename binary_op<
                NumericType,
                times,
                NumericType_1
            >::type
        > type;
     };

    template<
            typename NumericType_1,
            typename StaticUnit,
            typename NumericType
    >
    struct binary_op<
        NumericType_1,
        times,
        quan::fixed_quantity<
            StaticUnit,
            NumericType
        >,
        typename quan::where_<
            is_numeric<NumericType_1>
        >::type
    >{
        typedef typename quan::fixed_quantity<
            StaticUnit,
            typename binary_op<
                NumericType_1,
                times,
                NumericType
            >::type
        > type;
     };            

}}//quan::meta


namespace quan{

    template<
        typename StaticUnit,
        typename NumericType,
        typename NumericType_1
    >
    inline 
    QUAN_CONSTEXPR
    typename quan::where_<
        quan::meta::is_numeric<NumericType_1>,
        typename quan::meta::binary_op<
            quan::fixed_quantity<
                StaticUnit,
                NumericType
            >,
            quan::meta::times,
            NumericType_1
        >::type
    >::type
    operator *( 
        quan::fixed_quantity<
            StaticUnit,
            NumericType
        >const & pq,
        NumericType_1 const& v)
    {
     		typedef  typename quan::meta::binary_op<
            quan::fixed_quantity<
                StaticUnit,
                NumericType
            >,
            quan::meta::times,
            NumericType_1
        >::type result_type;
     
        return result_type{ pq.numeric_value() * v };

    }

    
    template<
        typename NumericType_1,
        typename StaticUnit,
        typename NumericType
    >
    inline 
    QUAN_CONSTEXPR
    typename quan::where_<
        quan::meta::is_numeric<NumericType_1>,
        typename quan::meta::binary_op<
            NumericType_1,
            quan::meta::times,
            quan::fixed_quantity<
                StaticUnit,
                NumericType
            >
        >::type
    >::type
    operator * ( 
        NumericType_1 const & v,
        quan::fixed_quantity<
            StaticUnit,
            NumericType
        >const & pq
    )
    {
       typedef  typename quan::meta::binary_op<
            NumericType_1,
            quan::meta::times,
            quan::fixed_quantity<
                StaticUnit,
                NumericType
            >
        >::type result_type;
       return result_type{ v * pq.numeric_value() };
    }

} //quan

#endif
