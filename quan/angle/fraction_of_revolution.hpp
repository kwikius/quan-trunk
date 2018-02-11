#ifndef QUAN_ANGLE_FRACTION_OF_REVOLUTION_HPP_INCLUDED
#define QUAN_ANGLE_FRACTION_OF_REVOLUTION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/*
 Copyright (c) 2003 - 2013 Andy Little 

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
/*
    fraction of revolution for angles such as degrees etc
*/
#include <quan/config.hpp>
#ifdef QUAN_AVR_NO_CPP_STDLIB
#include <math.h>
#include <quan/std/tr1/is_same.hpp>
#include <quan/std/tr1/integral_constant.hpp>
#include <quan/std/tr1/is_float.hpp>
#else
#include <cmath>
#include <type_traits>
#endif

#include <quan/angle/angle_fwd.hpp>
#include <quan/meta/is_angle.hpp>

#include <quan/concept_checking.hpp>
#include <quan/constants/constant.hpp>
#include <quan/meta/is_angle_value_type.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/eval_rational.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/gt.hpp>
#include <quan/where.hpp>
#include <quan/meta/eq.hpp>
#include <quan/meta/neq.hpp>
#include <quan/arithmetic_convert.hpp>
#include <quan/meta/min_type.hpp>
#include <quan/modulus.hpp>

namespace quan{

    template<
        typename Extent,    // quan::meta::rational<N,D>
        typename ReciprocalFraction,  // quan::meta::rational<N,D>
        typename ValueType
    >
    class fraction_of_revolution{
        ValueType m_value;
    public:
        typedef typename Extent::type extent;
        typedef typename ReciprocalFraction::type fraction_type;
        typedef ValueType value_type;
        typedef fraction_of_revolution type;

QUAN_CONSTEXPR
        fraction_of_revolution(): m_value{static_cast<ValueType>(0)}{}

QUAN_CONSTEXPR
        explicit fraction_of_revolution(ValueType const& v)
        :m_value(v){}

        template < typename Value_type1>
        explicit 
QUAN_CONSTEXPR
fraction_of_revolution(Value_type1 const & v)
        :m_value{quan::arithmetic_convert<ValueType>(v)}{}

QUAN_CONSTEXPR
        fraction_of_revolution(fraction_of_revolution const& fr)
        :m_value(fr.m_value){}

        template<
            typename ReciprocalFraction1,
            typename Value_type1
        >
QUAN_CONSTEXPR
        fraction_of_revolution(
            fraction_of_revolution<
                Extent,
                ReciprocalFraction1,
                Value_type1
            > const & fr
        )
        : m_value{ quan::arithmetic_convert<ValueType>( 
            fr.numeric_value()
            * quan::meta::eval_rational<
                typename quan::meta::binary_op<
                    ReciprocalFraction,
                    quan::meta::divides,
                    ReciprocalFraction1
                >::type
            >()())
           }{}


        template< typename Value_type1>
QUAN_CONSTEXPR
        fraction_of_revolution(
            quan::mathematic_angle<
                Extent,
                Value_type1
            > const & r
        )
        : m_value{ quan::arithmetic_convert<ValueType>(r.numeric_value()
            * quan::meta::eval_rational<
                ReciprocalFraction
            >()()
            / (2 * constant_<typename quan::meta::float_promote<Value_type1>::type>::pi)) }{}

QUAN_CONSTEXPR
        ValueType numeric_value()const{return m_value;}

        template <typename Angle>
        typename quan::where_<
            std::is_same<Angle,fraction_of_revolution>,
            void
        >::type
        set_numeric_value(ValueType const & v)
        {
            m_value = v;
        }

        template <typename Angle>
        typename quan::where_<
            std::is_same<Angle,fraction_of_revolution>,
            ValueType&
        >::type
        reference_numeric_value()
        {
            return this->m_value ;
        }


        template <typename Angle>
QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Angle,fraction_of_revolution>,
            ValueType const&
        >::type
        reference_numeric_value()const
        {
            return this->m_value ;
        }

        template <typename Angle>

QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Angle,fraction_of_revolution>,
            ValueType const&
        >::type
        const_reference_numeric_value()const
        {
            return this->m_value ;
        }

QUAN_CONSTEXPR
        // add rad ops
        fraction_of_revolution operator +()const
        {
            return *this;
        }
QUAN_CONSTEXPR
        fraction_of_revolution operator -()const
        {
            return fraction_of_revolution(-this->numeric_value());
        }

        fraction_of_revolution& operator +=(fraction_of_revolution const & in)
        {
            m_value += in.m_value;
            return *this;
        }

        fraction_of_revolution& operator -=(fraction_of_revolution const & in)
        {
            m_value -= in.m_value;
             return *this;
        }

        template<
            typename ReciprocalFraction1,
            typename Value_type1
        >
        fraction_of_revolution& operator +=(fraction_of_revolution<
            Extent,
            ReciprocalFraction1,
            Value_type1
        > const & in)
        {
            //fraction_of_revolution t(in);
            m_value += fraction_of_revolution(in).m_value;
            return *this;
        }

        template<typename ReciprocalFraction1, typename Value_type1>
        fraction_of_revolution& operator -=(fraction_of_revolution<
            Extent,
            ReciprocalFraction1,
            Value_type1
        > const & in)
        {
            fraction_of_revolution t(in);
            m_value -= t.m_value;
            return *this;
        }

        template<typename Value_type1>
        fraction_of_revolution& operator *=(Value_type1 const & in)
        {
            m_value *= in;
            return *this;
        }

        template<typename Value_type1>
        fraction_of_revolution& operator /=(Value_type1 const & in)
        {
            m_value /= in;
            return *this;
        }
    };

    template<
        int64_t D,
        typename ReciprocalFraction,
        typename ValueType
    >
    class fraction_of_revolution<
        quan::meta::rational<0,D>,
        ReciprocalFraction, ValueType
    >{
    public:
       typedef ValueType type;
    };

}//quan

namespace quan{namespace meta{

      template<
        typename Extent,
        typename ReciprocalFraction,
        typename ValueType
     > struct is_fraction_of_revolution<
        quan::fraction_of_revolution<Extent, ReciprocalFraction,ValueType>
     > : std::true_type{};


    namespace impl {
//binary operations between fraction_of_revolution's (e.g degrees minutes etc)
//frl + frr
       template<
           typename Extent,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionL,
               Value_typeL
           >,
           plus,
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionR,
               Value_typeR
           >
       >{
           typedef typename quan::fraction_of_revolution<
               Extent,
               typename quan::meta::eval_if<
                  quan::meta::gt_<
                    ReciprocalFractionL,
                    ReciprocalFractionR
                  >,
                  ReciprocalFractionL,
                  ReciprocalFractionR
               >::type,
               typename binary_op<
                   Value_typeL,
                   plus,
                   Value_typeR
               >::type
           >::type type;
       };

   // frl - frr
       template<
           typename Extent,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionL,
               Value_typeL
           >,
           minus,
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionR,
               Value_typeR
           >
       >{
           typedef typename quan::fraction_of_revolution<
               Extent,
               typename quan::meta::eval_if<
                  quan::meta::gt_<
                       ReciprocalFractionL,
                       ReciprocalFractionR
                   >,
                   ReciprocalFractionL,
                   ReciprocalFractionR
               >::type,
               typename binary_op<
                   Value_typeL,
                   minus,
                   Value_typeR
               >::type
           >::type type;
       };

   // fr * v
       template<
           typename Extent,
           typename ReciprocalFraction,
           typename ValueType,
           typename Value_type1
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               ValueType
           >,
           times,
           Value_type1,
           typename quan::where_<
               is_angle_value_type<Value_type1>
           >::type
       >{
           typedef typename quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               typename binary_op<
                   ValueType,
                   times,
                   Value_type1
               >::type
           >::type type;
       };

   // v * fr
       template<
           typename Value_type1,
           typename Extent,
           typename ReciprocalFraction,
           typename ValueType
       >
       struct binary_op_impl<
           Value_type1,
           times,
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               ValueType
           >,
           typename quan::where_<
               is_angle_value_type<Value_type1>
           >::type
       >{
           typedef typename quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               typename binary_op<
                   ValueType,
                   times,
                   Value_type1
               >::type
           >::type type;
       };

   // fr / v
       template<
           typename Extent,
           typename ReciprocalFraction,
           typename ValueType,
           typename Value_type1
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               ValueType
           >,
           divides,
           Value_type1,
           typename quan::where_<
               is_angle_value_type<Value_type1>
           >::type
       >{
           typedef typename quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               typename binary_op<
                   ValueType,
                   divides,
                   Value_type1
               >::type
           >::type type;
       };

   // v / fr;
       template<
           typename Extent,
           typename ReciprocalFraction,
           typename ValueType,
           typename Value_type1
       >
       struct binary_op_impl<
           Value_type1,
           divides,
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFraction,
               ValueType
           >,
           typename quan::where_<
                   is_angle_value_type<Value_type1>
           >::type
       >{
           typedef typename quan::fraction_of_revolution<
               typename unary_operation<
                   negate,
                   Extent
               >::type,
               typename unary_operation<
                   reciprocal,
                   ReciprocalFraction
               >::type,
               typename binary_op<
                   ValueType,
                   divides,
                   Value_type1
               >::type
           >::type type;
       };

   // fra / frb
       template <
           typename ExtentL,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename ExtentR,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               ExtentL,
               ReciprocalFractionL,
               Value_typeL
           >,
           divides,
           quan::fraction_of_revolution<
               ExtentR,
               ReciprocalFractionR,
               Value_typeR
           >
       >{
           typedef typename quan::fraction_of_revolution<
              typename binary_op<
                   ExtentL,
                   minus,
                   ExtentR
               >::type,
           // other way up ???
               typename binary_op<
                   ReciprocalFractionL,
                   divides,
                   ReciprocalFractionR
               >::type,
               typename binary_op<
                   Value_typeL,
                   divides,
                   Value_typeR
               >::type
           >::type  type;
       };

   // fra * frb
       template <
           typename ExtentL,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename ExtentR,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               ExtentL,
               ReciprocalFractionL,
               Value_typeL
           >,
           times,
           quan::fraction_of_revolution<
               ExtentR,
               ReciprocalFractionR,
               Value_typeR
           >
       >{
           typedef typename quan::fraction_of_revolution<
              typename binary_op<
                   ExtentL,
                   plus,
                   ExtentR
               >::type,
               typename binary_op<
                   ReciprocalFractionL,
                   times,
                   ReciprocalFractionR
               >::type,
               typename binary_op<
                   Value_typeL,
                   times,
                   Value_typeR
               >::type
           >::type  type;
       };
    } // impl
}}//quan::meta


namespace quan{ //quan


// fr + fr
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op<
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::plus,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator +(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        > const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        > const& rhs)
    {
#if 0
//old style...

        return typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::plus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type (lhs)+= rhs;
#else
//new style...
        typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::plus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type result_type;
       return result_type{result_type{lhs}.numeric_value() + result_type{rhs}.numeric_value()};
#endif
      
    }

// fr - fr
     template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::minus,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator -(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        > const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        > const& rhs)
    {
#if 0
        return typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::minus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type (lhs)-= rhs;
#else
   typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::plus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type result_type;
       return result_type{result_type{lhs}.numeric_value() - result_type{rhs}.numeric_value()};

#endif
    }

// fr * fr
    template <
        typename ExtentL,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ExtentR,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR
//#if 0
   typename quan::where_<
      std::is_same<
			typename quan::meta::binary_op<
					ExtentL,
					quan::meta::plus,
					ExtentR
			  >::type,
			quan::meta::rational<0>
      >,
//#endif
    typename quan::meta::binary_op<
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::times,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
   >::type
    operator*(
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        > const & lhs,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        > const & rhs
    )
    {
#if 0
        typedef typename quan::meta::binary_op<
            ExtentL,
            quan::meta::plus,
            ExtentR
        >::type extent;
        ////////////////////CONCEPT CHECK////////////////////////////////
        // unlike radians for fraction-of-revolution types
        // only multiplication by fraction_of_revolution;s
        // with resulting Extent of 0 is valid
        quan::concept_checking::Assert<
            std::is_same<
                extent,
                quan::meta::rational<0>
            >::value
        >();
#endif
        //////////////////////CONCEPT CHECK/////////////////////////////

        typedef typename quan::meta::binary_op<
            ReciprocalFractionL,
            quan::meta::times,
            ReciprocalFractionR
        >::type eval_type;

        return typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::times,
            quan::fraction_of_revolution<
                ExtentR,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type( lhs.numeric_value() * rhs.numeric_value() /
            quan::meta::eval_rational<
                eval_type
            >()()
        );
    }

    template <
        typename ExtentL,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ExtentR,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR
    typename quan::where_<
		std::is_same<
				typename quan::meta::binary_op<
					ExtentL,
					quan::meta::minus,
					ExtentR
			  >::type,
			  quan::meta::rational<0>
      >,
		typename quan::meta::binary_op<
		  quan::fraction_of_revolution<
				ExtentL,
				ReciprocalFractionL,
				Value_typeL
		  >,
		  quan::meta::divides,
		  quan::fraction_of_revolution<
				ExtentR,
				ReciprocalFractionR,
				Value_typeR
		  >
		>::type
   >::type
    operator/(
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        > const & lhs,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        > const & rhs)
    {
#if 0
        typedef typename quan::meta::binary_op<
            ExtentL,
            quan::meta::minus,
            ExtentR
        >::type extent;
        ////////////////////CONCEPT CHECK////////////////////////////////
        // only division by fraction_of_revolution;s
        // with resulting extent of 0 is valid
        quan::concept_checking::Assert<
            std::is_same<
                extent,
                quan::meta::rational<0>
            >::value
        >();
#endif
        //////////////////////CONCEPT CHECK/////////////////////////////

        typedef typename quan::meta::binary_op<
            ReciprocalFractionR,
            quan::meta::divides,
            ReciprocalFractionL
        >::type eval_type;

        return typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::divides,
            quan::fraction_of_revolution<
                ExtentR,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type(
            lhs.numeric_value() / rhs.numeric_value()
            * quan::meta::eval_rational<
                eval_type
            >()()
        );
    }

// fr * v
    template<
        typename ExtentL,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ValueType
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<ValueType>,
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::times,
        ValueType
    >::type
    operator *(
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        ValueType const& rhs)
    {
      typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::times,
            ValueType
        >::type result_type;
       return result_type{ result_type{lhs}.numeric_value() * rhs};
/*
       return typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::times,
            ValueType
        >::type (lhs) *= rhs;
      */
    }
// v * fr
    template<
        typename ValueType,
        typename ExtentR,
        typename ReciprocalFractionR,
        typename Value_typeR>
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<ValueType>,
        ValueType,
        quan::meta::times,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator *(
        ValueType const&  lhs,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs
    )
    {
        return typename quan::meta::binary_op<
            ValueType,
            quan::meta::times,
            quan::fraction_of_revolution<
                ExtentR,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type ( lhs * rhs.numeric_value());
    }

//fr / v
    template<
        typename ExtentL,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ValueType
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<ValueType>,
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::divides,
        ValueType
    >::type
    operator /(
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        ValueType const& rhs)
    {
        typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::divides,
            ValueType
        >::type result_type;
        return  result_type{result_type{lhs}.numeric_value()/ rhs};
      
    }

// v / fr
    template<
        typename ValueType,
        typename ExtentR,
        typename ReciprocalFractionR,
        typename Value_typeR>
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<ValueType>,
        ValueType,
        quan::meta::divides,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator /(
        ValueType const&  lhs,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs
    )
    {
        return typename quan::meta::binary_op<
            ValueType,
            quan::meta::divides,
            quan::fraction_of_revolution<
                ExtentR,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type ( lhs / rhs.numeric_value());
    }

    // abs
    template<
        typename Extent,
        typename ReciprocalFraction,
        typename ValueType
    >
    inline QUAN_CONSTEXPR
    quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        ValueType
    >
    abs(quan::fraction_of_revolution<Extent,ReciprocalFraction, ValueType>const& in)
    {
      return in.numeric_value() < 0 ? -in : in;
    }

    //comparisons
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR int compare(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs,
        typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::minus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type const & eps =
        typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::minus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type(QUAN_FLOAT_EPSILON)
     )
    {
        typedef typename quan::meta::binary_op<
            Value_typeL,
            quan::meta::minus,
            Value_typeR
        >::type comp_value_type;
        return ((abs(lhs-rhs)).numeric_value() <= abs(eps).numeric_value())
        ? 0
        :(((lhs-rhs).numeric_value() < static_cast<comp_value_type>(0))
            ? -1
            : 1);
    }
// <
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR bool operator<(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs
    )
    {
        return compare(lhs,rhs) < 0;
    }

 // <=
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR bool operator<=(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs)
    {
        return compare(lhs,rhs) <= 0;
    }

 //==
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR bool operator==(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs)
    {
        return compare(lhs,rhs) == 0;
    }
//!=
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR bool operator !=(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs)
    {
        return compare(lhs,rhs) != 0;
    }
// >=
 template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR bool operator>=(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs)
    {
        return compare(lhs,rhs) >= 0;
    }

// >
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline QUAN_CONSTEXPR bool operator >(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        >const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        >const& rhs)
    {
        return compare(lhs,rhs) > 0;
    }

    template<
        typename Extent,
        typename ReciprocalFraction,
        typename ValueType
    >
    inline
	 quan::fraction_of_revolution<
			  Extent,
			  ReciprocalFraction,
			  typename std::common_type<
              ValueType,decltype(quan::meta::eval_rational<ReciprocalFraction>()())
           >::type
    >
    unsigned_modulo( quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        ValueType
    > const & fr)
    {
      constexpr auto one_rev = quan::meta::eval_rational<ReciprocalFraction>()();

      typedef quan::fraction_of_revolution<
           Extent,
           ReciprocalFraction,
           typename std::common_type<
              ValueType,decltype(quan::meta::eval_rational<ReciprocalFraction>()())
           >::type
        > result_type;
      
      if ( fr.numeric_value() >= ValueType{0}){
        return result_type{quan::modulus(fr.numeric_value(),one_rev )};
      }else{
         return result_type{quan::modulus(fr.numeric_value(), one_rev) + one_rev};
      }
    }

    template<
        typename Extent,
        typename ReciprocalFraction,
        typename ValueType
    >
    inline
    quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        typename std::common_type<
           ValueType,decltype(quan::meta::eval_rational<ReciprocalFraction>()())
        >::type
    >
    signed_modulo( quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        ValueType
    > const & fr)
    {
       static_assert(std::is_unsigned<ValueType>::value == false,"not useful for unsigned types");
       constexpr auto one_rev = quan::meta::eval_rational<ReciprocalFraction>()();
       typedef quan::fraction_of_revolution<
          Extent,
          ReciprocalFraction,
          typename std::common_type<
             ValueType,decltype(quan::meta::eval_rational<ReciprocalFraction>()())
          >::type
       > result_type;
       result_type const unsigned_result = unsigned_modulo(fr);
       if (unsigned_result.numeric_value() <= one_rev/2 ){
          return unsigned_result;
       }else{
          return unsigned_result - result_type{one_rev} ;
       }
    }

   template<
      typename Extent,
      typename ReciprocalFraction,
      typename ValueType
   >
   inline
   quan::fraction_of_revolution<
      Extent,
      ReciprocalFraction,
      typename std::common_type<
         ValueType,decltype(quan::meta::eval_rational<ReciprocalFraction>()())
      >::type
   >
   modulo( quan::fraction_of_revolution<
      Extent,
      ReciprocalFraction,
      ValueType
   > const & fr)
   {
      typedef quan::fraction_of_revolution<
         Extent,
         ReciprocalFraction,
         typename std::common_type<
            ValueType,decltype(quan::meta::eval_rational<ReciprocalFraction>()())
         >::type
      > result_type;
      return result_type{
         quan::modulus(fr.numeric_value(),quan::meta::eval_rational<ReciprocalFraction>()())
      };
   }


} //quan

#endif // QUAN_ANGLE_FRACTION_OF_REVOLUTION_HPP_INCLUDED

