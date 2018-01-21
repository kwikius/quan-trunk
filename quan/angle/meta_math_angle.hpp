#ifndef QUAN_ANGLE_META_MATH_ANGLE_HPP_INCLUDED
#define QUAN_ANGLE_META_MATH_ANGLE_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/angle/angle_fwd.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/is_angle_value_type.hpp>
#include <quan/where.hpp>

namespace quan{namespace meta{

    namespace impl {
//r + r
    template<
        typename Value_typeA,
        typename Extent,
        typename Value_typeB
    >
    struct binary_op_impl<
         quan::mathematic_angle<Extent,Value_typeA>,
         plus,
         quan::mathematic_angle<Extent,Value_typeB>
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_typeA,
                plus,
                Value_typeB
            >::type
        >::type  type;

    };

   // r - r
    template<
        typename Value_typeA,
        typename Extent,
        typename Value_typeB
    >
    struct binary_op_impl<
            quan::mathematic_angle<Extent,Value_typeA>,
            minus,
            quan::mathematic_angle<Extent,Value_typeB>
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_typeA,
                minus,
                Value_typeB
            >::type
        >::type  type;

    };

#ifndef QUAN_NO_MATH_ANGLE_NUMERIC_CONVERSION
// rad + double etc
    template<
        typename Value_typeA,
        typename Extent,
        typename Value_typeB
    >
    struct binary_op_impl<
      quan::mathematic_angle<Extent,Value_typeA>,
      plus,
      Value_typeB,
      typename quan::where_<
         is_angle_value_type<Value_typeB>
      >::type
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_typeA,
                plus,
                Value_typeB
            >::type
        >::type  type;

    };

    template<
        typename Value_typeA,
        typename Extent,
        typename Value_typeB
    >
    struct binary_op_impl<
      Value_typeA,
      plus,
      quan::mathematic_angle<Extent,Value_typeB>,
      typename quan::where_<
         is_angle_value_type<Value_typeA>
      >::type
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_typeA,
                plus,
                Value_typeB
            >::type
        >::type  type;

    };

// rad - double etc
    template<
        typename Value_typeA,
        typename Extent,
        typename Value_typeB
    >
    struct binary_op_impl<
            quan::mathematic_angle<Extent,Value_typeA>,
            minus,
            Value_typeB,
            typename quan::where_<
               is_angle_value_type<Value_typeB>
            >::type
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_typeA,
                minus,
                Value_typeB
            >::type
        >::type  type;

    };

   template<
        typename Value_typeA,
        typename Extent,
        typename Value_typeB
    >
    struct binary_op_impl<
      Value_typeA,
      minus,
      quan::mathematic_angle<Extent,Value_typeB>,
      typename quan::where_<
         is_angle_value_type<Value_typeA>
      >::type
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_typeA,
                minus,
                Value_typeB
            >::type
        >::type  type;

    };
#endif
// ra * rb
    template<
        typename ExtentA,
        typename Value_typeA,
        typename ExtentB,
        typename Value_typeB
    >
    struct binary_op_impl<
            quan::mathematic_angle<ExtentA,Value_typeA>,
            times,
            quan::mathematic_angle<ExtentB,Value_typeB>
    >
    {
        typedef  typename quan::mathematic_angle<
            typename binary_op<
                ExtentA,
                plus,
                ExtentB
            >::type,
            typename binary_op<
                Value_typeA,
                times,
                Value_typeB
            >::type
        >::type  type;

    };
// r * v
    template<
        typename Extent,
        typename Value_type,
        typename Value_type1
    >
    struct binary_op_impl<
            quan::mathematic_angle<Extent,Value_type>,
            times,
            Value_type1,
            typename quan::where_<
               is_angle_value_type<Value_type1>
            >::type
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_type,
                times,
                Value_type1
            >::type
        >::type  type;
    };
// v * r
    template<
        typename Value_type1,
        typename Extent,
        typename Value_type
    >
    struct binary_op_impl<
            Value_type1,
            times,
            quan::mathematic_angle<Extent,Value_type>,
            typename quan::where_<
                is_angle_value_type<Value_type1>
            >::type
    >
    {
        typedef  typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_type1,
                times,
                Value_type
            >::type
        >::type  type;
    };
// ra / rb
    template<
        typename ExtentA,
        typename Value_typeA,
        typename ExtentB,
        typename Value_typeB
    >
    struct binary_op_impl<
            quan::mathematic_angle<ExtentA,Value_typeA>,
            divides,
            quan::mathematic_angle<ExtentB,Value_typeB>
    >
    {
        typedef  typename quan::mathematic_angle<
            typename binary_op<
                ExtentA,
                minus,
                ExtentB
            >::type,
            typename binary_op<
                Value_typeA,
                divides,
                Value_typeB
            >::type
        >::type  type;

    };
// r / v
    template<
        typename Extent,
        typename Value_type,
        typename Value_type1
    >
    struct binary_op_impl<
            quan::mathematic_angle<Extent,Value_type>,
            divides,
            Value_type1,
            typename quan::where_<
                is_angle_value_type<Value_type1>
            >::type
    >
    {
        typedef typename quan::mathematic_angle<
            Extent,
            typename binary_op<
                Value_type,
                divides,
                Value_type1
            >::type
        >::type  type;

    };

// v / r
    template<
        typename Value_type1,
        typename Extent,
        typename Value_type
    >
    struct binary_op_impl<
            Value_type1,
            divides,
            quan::mathematic_angle<Extent,Value_type>,
            typename quan::where_<
                is_angle_value_type<Value_type1>
            >::type
    >
    {
        typedef typename quan::mathematic_angle<
            typename unary_operation<
                negate,
                Extent
            >::type,
            typename binary_op<
                Value_type1,
                divides,
                Value_type
            >::type
        >::type  type;

    };
    // r to power rational<int,N,D>
    template <typename Extent,typename Value_type, int N, int D>
    struct binary_op_impl<
         quan::mathematic_angle<Extent,Value_type>,
         pow,
         rational<N,D>
    >
    {
        typedef typename quan::mathematic_angle<
            typename binary_op<
                Extent,
                times,
                typename rational<N,D>::type
            >::type,
            typename binary_op<
                Value_type,
                pow,
                typename rational<N,D>::type
            >::type
        >::type type;
    };
   } // impl
}}//quan::meta

#endif
