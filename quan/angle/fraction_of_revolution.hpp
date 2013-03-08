#ifndef QUAN_ANGLE_FRACTION_OF_REVOLUTION_HPP_INCLUDED
#define QUAN_ANGLE_FRACTION_OF_REVOLUTION_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    fraction of revolution for angles such as degrees etc
*/
#include <quan/config.hpp>
#ifdef __AVR__
#include <math.h>
#else
#include <cmath>
#endif

#include <quan/angle/angle_fwd.hpp>
#include <quan/meta/is_angle.hpp>
#include <type_traits>
#include <quan/concept_checking.hpp>
#include <quan/constants/constant.hpp>
#include <quan/meta/is_angle_value_type.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/meta/rational.hpp>
#include <quan/meta/eval_rational.hpp>
#include <quan/implicit_cast.hpp>
#include <type_traits>
#include <quan/meta/if.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/gt.hpp>
#include <quan/where.hpp>
#include <type_traits>
#include <type_traits>
#include <quan/meta/eq.hpp>
#include <quan/meta/neq.hpp>
#include <quan/arithmetic_convert.hpp>
#include <quan/meta/min_type.hpp>

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
        fraction_of_revolution(): m_value(static_cast<ValueType>(0)){}

QUAN_CONSTEXPR
        explicit fraction_of_revolution(ValueType const& v)
        :m_value(v){}


        template < typename Value_type1>
        explicit 
QUAN_CONSTEXPR
fraction_of_revolution(Value_type1 const & v)
        :m_value(implicit_cast<ValueType>(v)){}

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
        : m_value( fr.numeric_value()
            * quan::meta::eval_rational<
                typename quan::meta::binary_op<
                    ReciprocalFraction,
                    quan::meta::divides,
                    ReciprocalFraction1
                >::type
            >()()){}


        template< typename Value_type1>
QUAN_CONSTEXPR
        fraction_of_revolution(
            quan::mathematic_angle<
                Extent,
                Value_type1
            > const & r
        )
        : m_value( r.numeric_value()
            * quan::meta::eval_rational<
                ReciprocalFraction
            >()()
            / (2 * constant_<typename quan::meta::float_promote<Value_type1>::type>::pi)){}

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
        QUAN_INT32 D,
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

//binary operations between fraction_of_revolution's (e.g degrees minutes etc)
//frl + frr
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    struct binary_op<
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
    struct binary_op<
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
    struct binary_op<
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
    struct binary_op<
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
    struct binary_op<
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
    struct binary_op<
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
    struct binary_op<
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
    struct binary_op<
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
}}//quan::meta

#if !(defined QUAN_SUPPRESS_VC8_ADL_BUG)
namespace quan{ //quan
#endif

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
    typename quan::where_<
		std::is_floating_point<ValueType>,
		 quan::fraction_of_revolution<
			  Extent,
			  ReciprocalFraction,
			  ValueType
		 >
    >::type
    modulo( quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        ValueType
    > const & fr)
    {
        ValueType v = fr.numeric_value()/
            quan::meta::eval_rational<ReciprocalFraction>()();
        ValueType n;
#ifndef __AVR__
       using std::modf;
#else
       using ::modf;
#endif
       // ValueType fract = modf(v,&n);
        return quan::fraction_of_revolution<
            Extent,
            ReciprocalFraction,
            ValueType
        >(
             modf(v,&n) * quan::meta::eval_rational<ReciprocalFraction>()()
        );
    }


 	template<
        typename Extent,
        typename ReciprocalFraction,
        typename ValueType
    >
inline
QUAN_CONSTEXPR
    typename quan::where_<
		quan::meta::and_<
			std::is_integral<ValueType>,
     	   quan::meta::eq_<typename quan::meta::denominator<ReciprocalFraction>::type,quan::meta::int32<1> >
     >,
		 quan::fraction_of_revolution<
			  Extent,
			  ReciprocalFraction,
			  ValueType
		 >
    >::type
    modulo( quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        ValueType
    > const & fr)
    {
       return quan::fraction_of_revolution<
            Extent,
            ReciprocalFraction,
            ValueType
        >(
         fr.numeric_value() % quan::meta::numerator<ReciprocalFraction>::value
       );
    }

#if 0
    template<
        typename Extent,
        typename ReciprocalFraction,
        typename ValueType
    >
    typename quan::where_<
		quan::meta::and_<
			std::is_integral<ValueType>,
     	   quan::meta::neq_<typename quan::meta::denominator<ReciprocalFraction>::type,quan::meta::int32<1> >
     >,
		 quan::fraction_of_revolution<
			  Extent,
			  ReciprocalFraction,
			  ValueType
		 >
    >::type
    modulo( quan::fraction_of_revolution<
        Extent,
        ReciprocalFraction,
        ValueType
    > const & fr)
    {

        QUAN_FLOAT_TYPE v = static_cast<QUAN_FLOAT_TYPE>(fr.numeric_value())/
            quan::meta::eval_rational<ReciprocalFraction>()();
        QUAN_FLOAT_TYPE n;
#ifndef __AVR__
       using std::modf;
#else
      using ::modf;
#endif
       // ValueType fract = modf(v,&n);
        return quan::fraction_of_revolution<
            Extent,
            ReciprocalFraction,
            ValueType
        >(
             quan::arithmetic_convert<ValueType>(modf(v,&n) * quan::meta::eval_rational<ReciprocalFraction>()())
        );

    }

#endif

#if !(defined QUAN_SUPPRESS_VC8_ADL_BUG)
} //quan
#endif

#endif // QUAN_ANGLE_FRACTION_OF_REVOLUTION_HPP_INCLUDED

