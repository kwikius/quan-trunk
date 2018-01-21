
#ifndef QUAN_ANGLE_ANGLE_HPP_INCLUDED
#define QUAN_ANGLE_ANGLE_HPP_INCLUDED
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
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    interface betweeen mathematic_angle and fraction_of_revolution
    together with angle container giving convenient typedefs for
    angles
*/
#include <quan/config.hpp>
#include <quan/angle/mathematic_angle.hpp>
#include <quan/angle/fraction_of_revolution.hpp>
#include <quan/angle/literal.hpp>
#include <quan/concept_checking.hpp>

namespace quan{

// ctor for rad from fraction-of-rev
    template<
        typename Extent,
        typename Value_type
    >
    template<
        typename ReciprocalFraction,
        typename Value_type1
    >
    inline QUAN_CONSTEXPR

    mathematic_angle<
        Extent,
        Value_type
    > ::mathematic_angle(
        fraction_of_revolution<
            Extent,
            ReciprocalFraction,
            Value_type1
        > const & fr)
    : m_value ((Extent::numerator == 1)
        ?(fr.numeric_value()
            * 2 * quan::constant_<Value_type>::pi)
                / quan::meta::eval_rational< ReciprocalFraction>()()
        :fr.numeric_value()
            /( 2 * quan::constant_<Value_type>::pi
                * quan::meta::eval_rational< ReciprocalFraction>()())
     ){
    ///////////////////////////Concept Check//////////////////////////////////////
    // limit conversion to mathematic_angle and mathematic_angle ^-1
#if 0
        quan::concept_checking::Assert<
             (((Extent::numerator == 1) && (Extent::denominator == 1))
            ||  ((Extent::numerator == -1) && (Extent::denominator == 1))) >();
#endif
    //////////////////////Concept Check //////////////////////////////////////////
    }
}//quan

namespace quan{namespace meta{

    namespace impl {

   // rad * fr
       template<
           typename ExtentL,
           typename Value_typeL,
           typename ExtentR,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::mathematic_angle<
               ExtentL,Value_typeL
           >,
           times,
           quan::fraction_of_revolution<
               ExtentR,
               ReciprocalFractionR,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               typename binary_op<
                   ExtentL,
                   plus,
                   ExtentR
               >::type,
               typename binary_op<
                   Value_typeL,
                   times,
                   Value_typeR
               >::type
           >::type type;
       };
   // rad / fr
       template<
           typename ExtentL,
           typename Value_typeL,
           typename ExtentR,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::mathematic_angle<
               ExtentL,
               Value_typeL
           >,
           divides,
           quan::fraction_of_revolution<
               ExtentR,
               ReciprocalFractionR,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               typename binary_op<
                   ExtentL,
                   minus,
                   ExtentR
               >::type,
               typename binary_op<
                   Value_typeL,
                   divides,
                   Value_typeR
               >::type
           >::type type;
       };

   //fr * rad
       template<
           typename ExtentL,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename ExtentR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               ExtentL,
               ReciprocalFractionL,
               Value_typeL
           >,
           times,
           quan::mathematic_angle<
               ExtentR,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               typename binary_op<
                   ExtentL,
                   plus,
                   ExtentR
               >::type,
               typename binary_op<
                   Value_typeL,
                   times,
                   Value_typeR
               >::type
           >::type type;
       };
   // fr / rad
       template<
           typename ExtentL,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename ExtentR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               ExtentL,
               ReciprocalFractionL,
               Value_typeL
           >,
           divides,
           quan::mathematic_angle<
               ExtentR,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               typename binary_op<
                   ExtentL,
                   minus,
                   ExtentR
               >::type,
               typename binary_op<
                   Value_typeL,
                   divides,
                   Value_typeR
               >::type
           >::type type;
       };
   // fr + rad
       template<
           typename Extent,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionL,
               Value_typeL
           >,
           plus,
           quan::mathematic_angle<
               Extent,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               Extent,
               typename binary_op<
                   Value_typeL,
                   plus,
                   Value_typeR
               >::type
           >::type type;
       };

   // rad + fr
       template<
           typename Extent,
           typename Value_typeL,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::mathematic_angle<
               Extent,
               Value_typeL
           >,
           plus,
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionR,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               Extent,
               typename binary_op<
                   Value_typeL,
                   plus,
                   Value_typeR
               >::type
           >::type type;
       };

   //rad-fr
       template<
           typename Extent,
           typename Value_typeL,
           typename ReciprocalFractionR,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::mathematic_angle<
               Extent,
               Value_typeL
           >,
           minus,
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionR,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               Extent,
               typename binary_op<
                   Value_typeL,
                   minus,
                   Value_typeR
               >::type
           >::type type;
       };

   // fr - rad
       template<
           typename Extent,
           typename ReciprocalFractionL,
           typename Value_typeL,
           typename Value_typeR
       >
       struct binary_op_impl<
           quan::fraction_of_revolution<
               Extent,
               ReciprocalFractionL,
               Value_typeL
           >,
           minus,
           quan::mathematic_angle<
               Extent,
               Value_typeR
           >
       >
       {
           typedef typename quan::mathematic_angle<
               Extent,
               typename binary_op<
                   Value_typeL,
                   minus,
                   Value_typeR
               >::type
           >::type type;
       };
   }// impl

}}//quan::meta

#if !(defined _MSC_VER && _MSC_VER ==1400 && defined QUAN_SUPPRESS_VC8_ADL_BUG)
namespace quan {
#endif
//namespace quan{

// fr + rad
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
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
        quan::mathematic_angle<
            Extent,
            Value_typeR
        >
    >::type
    operator +(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        > const&  lhs,
        quan::mathematic_angle<
            Extent,
            Value_typeR
        > const& rhs
    )
    {
#if 0
        typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::plus,
            quan::mathematic_angle<
                Extent,
                Value_typeR
            >
        >::type t(lhs);
        t += rhs;
        return t;
#else
	typedef typename quan::meta::binary_op<
		quan::fraction_of_revolution<
			 Extent,
			 ReciprocalFractionL,
			 Value_typeL
		>,
		quan::meta::plus,
		quan::mathematic_angle<
			 Extent,
			 Value_typeR
		>
		>::type result_type;
      return result_type{result_type{lhs}.numeric_value() + result_type{rhs}.numeric_value()};
#endif
    }

// rad + fr
    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
        quan::mathematic_angle<
            Extent,
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
        quan::mathematic_angle<
            Extent,
            Value_typeL
        > const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        > const& rhs
    )
    {
#if 0
        typedef typename quan::meta::binary_op<
            quan::mathematic_angle<
                Extent,
                Value_typeL
            >,
            quan::meta::plus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type rad;
        rad t(lhs);
        t += rad(rhs);
        return t;
#else
      typedef typename quan::meta::binary_op<
            quan::mathematic_angle<
                Extent,
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

// rad - fr
    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
        quan::mathematic_angle<
            Extent,
            Value_typeL
        >,
        quan::meta::minus,
        quan::fraction_of_revolution<
            Extent,ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator -(
        quan::mathematic_angle<
            Extent,
            Value_typeL
        > const& lhs,
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionR,
            Value_typeR
        > const& rhs)
    {
#if 0
        typedef typename quan::meta::binary_op<
            quan::mathematic_angle<
                Extent,
                Value_typeL
            >,
            quan::meta::minus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type rad;
        rad t(lhs);
        t -= rad(rhs);
        return t;
#else
      typedef typename quan::meta::binary_op<
            quan::mathematic_angle<
                Extent,
                Value_typeL
            >,
            quan::meta::minus,
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type result_type;
         return result_type{result_type{lhs}.numeric_value() - result_type{rhs}.numeric_value()};
#endif
    }

// fr - rad
    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
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
        quan::mathematic_angle<
            Extent,
            Value_typeR
        >
    >::type
    operator -(
        quan::fraction_of_revolution<
            Extent,
            ReciprocalFractionL,
            Value_typeL
        > const&  lhs,
        quan::mathematic_angle<
            Extent,
            Value_typeR
        > const& rhs
    )
    {
#if 0
        typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::minus,
            quan::mathematic_angle<
                Extent,
                Value_typeR
            >
        >::type t(lhs);
        t -= rhs;
        return t;
#else
      typedef     typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                Extent,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::minus,
            quan::mathematic_angle<
                Extent,
                Value_typeR
            >
        >::type result_type;
       return result_type{result_type{lhs}.numeric_value() - result_type{rhs}.numeric_value()};
#endif
    }

// rad * fr
    template<
        typename ExtentL,
        typename Value_typeL,
        typename ExtentR,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
        quan::mathematic_angle<
            ExtentL,
            Value_typeL
        >,
        quan::meta::times,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator * (
        quan::mathematic_angle<
            ExtentL,
            Value_typeL
        > const & lhs,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        > const & rhs
    )
    {
        typedef typename quan::meta::binary_op<
            ExtentL,
            quan::meta::plus,
            ExtentR
        >::type extent_type;
        ////////////////////CONCEPT CHECK////////////////////////////////
        // only multiplication  by angles
        // with resulting Extent of 0 is valid currently
        quan::concept_checking::Assert<
            std::is_same<
                extent_type,
                quan::meta::rational<0>
            >::value
        >();
        //////////////////////CONCEPT CHECK/////////////////////////////
/*
        typedef typename quan::meta::binary_op<
            quan::mathematic_angle<
                ExtentL,
                Value_typeL
            >,
            quan::meta::times,
            quan::fraction_of_revolution<
                ExtentR,
                ReciprocalFractionR,
                Value_typeR
            >
        >::type type;
*/
        typedef typename quan::meta::binary_op<
            Value_typeL,
            quan::meta::times,
            Value_typeR
        >::type result_value_type;
        quan::mathematic_angle<
            ExtentR,
            result_value_type
        > t(rhs);
        return (lhs.numeric_value() * t.numeric_value() );
    }
// fr * rad
    template<
        typename ExtentL,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ExtentR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
         quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::times,
        quan::mathematic_angle<
            ExtentR,
            Value_typeR
        >
    >::type
    operator * (
        quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        > const  & lhs,
        quan::mathematic_angle<
            ExtentR,
            Value_typeR
        > const& rhs
    )
    {
         ////////////////////CONCEPT CHECK////////////////////////////////
        // only multiplication  by non rad angles
        // with resulting Extent of 0 is valid currently
        typedef typename quan::meta::binary_op<
            ExtentL,
            quan::meta::plus,
            ExtentR
        >::type extent_type;
        quan::concept_checking::Assert<
            std::is_same<
                extent_type,
                quan::meta::rational<0>
            >::value
        >();
        //////////////////////CONCEPT CHECK/////////////////////////////
/*
        typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::times,
            quan::mathematic_angle<ExtentR,Value_typeR>
        >::type type;
*/
        typedef typename quan::meta::binary_op<
            Value_typeL,
            quan::meta::times,
            Value_typeR
        >::type result_value_type;
        quan::mathematic_angle<ExtentL,result_value_type> t(lhs);
        return (t.numeric_value() * rhs.numeric_value()  );
    }
// rad / fr
    template<
        typename ExtentL,
        typename Value_typeL,
        typename ExtentR,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
        quan::mathematic_angle<ExtentL,Value_typeL>,
        quan::meta::divides,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >
    >::type
    operator / (quan::mathematic_angle<ExtentL,Value_typeL> const & lhs,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        > const & rhs)
    {
        typedef typename quan::meta::binary_op<
            typename ExtentL::type,
            quan::meta::minus,
            typename ExtentR::type
        >::type extent_type;
        ////////////////////CONCEPT CHECK////////////////////////////////
        // only multiplication  by different angles
        // with resulting Extent of 0 is valid currently
        quan::concept_checking::Assert<
            std::is_same<
                extent_type,
                quan::meta::rational<0>
            >::value
        >();
        //////////////////////CONCEPT CHECK/////////////////////////////
/*
        typedef typename quan::meta::binary_op<
        quan::mathematic_angle<ExtentL,Value_typeL>,
        quan::meta::divides,
        quan::fraction_of_revolution<
            ExtentR,
            ReciprocalFractionR,
            Value_typeR
        >
        >::type type;
*/
        typedef typename quan::meta::binary_op<
            Value_typeL,
            quan::meta::divides,
            Value_typeR
        >::type result_value_type;
        quan::mathematic_angle<ExtentR,result_value_type> t(rhs);
        return (lhs.numeric_value() / t.numeric_value() );
    }
// fr / rad
    template<
        typename ExtentL,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename ExtentR,
        typename Value_typeR
    >
    inline
    typename quan::meta::binary_op<
         quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        >,
        quan::meta::divides,
        quan::mathematic_angle<ExtentR,Value_typeR>
    >::type
    operator / ( quan::fraction_of_revolution<
            ExtentL,
            ReciprocalFractionL,
            Value_typeL
        > const  & lhs,
        quan::mathematic_angle<ExtentR,Value_typeR> const& rhs)
    {
         typedef typename quan::meta::binary_op<
            ExtentL,
            quan::meta::minus,
            ExtentR
         >::type extent_type;
        ////////////////////CONCEPT CHECK////////////////////////////////
        // only multiplication  by non rad angles
        // with resulting Extent of 0 is valid currently
          quan::concept_checking::Assert<
            std::is_same<
                extent_type,
                quan::meta::rational<0>
            >::value
        >();
        //////////////////////CONCEPT CHECK/////////////////////////////
/*
        typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<
                ExtentL,
                ReciprocalFractionL,
                Value_typeL
            >,
            quan::meta::divides,
            quan::mathematic_angle<ExtentR,Value_typeR>
        >::type type;
*/
        typedef typename quan::meta::binary_op<
            Value_typeL,
            quan::meta::divides,
            Value_typeR
        >::type result_value_type;
        quan::mathematic_angle<ExtentL,result_value_type> t(lhs);
        return result_value_type(t.numeric_value() / rhs.numeric_value()  );
    }

    template<typename ReciprocalFraction,typename Value_type>
    inline
    Value_type cos(
        quan::fraction_of_revolution<quan::meta::rational<1>,ReciprocalFraction,Value_type>const& r)
    {
        quan::mathematic_angle<quan::meta::rational<1>,Value_type> t(r);
        return cos(t);
    }
    template<typename ReciprocalFraction,typename Value_type>
    inline
    Value_type sin(quan::fraction_of_revolution<quan::meta::rational<1>,ReciprocalFraction,Value_type>const& r)
    {
        quan::mathematic_angle<quan::meta::rational<1>,Value_type> t(r);
        return sin(t);
    }
    template<typename ReciprocalFraction,typename Value_type>
    inline
    Value_type
    tan(
        quan::fraction_of_revolution<
            quan::meta::rational<1>,
            ReciprocalFraction,
            Value_type
        >const& r
    )
    {
        quan::mathematic_angle<quan::meta::rational<1>,Value_type> t(r);
        return tan(t);
    }


//comparisons

    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline int compare(
        quan::mathematic_angle<Extent,Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR,Value_typeR>const& rhs,
        typename quan::meta::binary_op<
            quan::mathematic_angle<Extent, Value_typeL>,
            quan::meta::minus,
            quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>
        >::type const & eps
        =typename quan::meta::binary_op<
            quan::mathematic_angle<Extent, Value_typeL>,
            quan::meta::minus,
            quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>
        >::type(QUAN_FLOAT_EPSILON)
    )
    {
        typedef typename quan::meta::binary_op<
            quan::mathematic_angle<Extent, Value_typeL>,
            quan::meta::minus,
            quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>
        >::type comp_type;
        comp_type rhs1(rhs);
        typedef typename comp_type::value_type comp_value_type;
        return ((abs(lhs-rhs1)).numeric_value() <= abs(eps).numeric_value())
        ? 0
        :(((lhs-rhs1).numeric_value() < static_cast<comp_value_type>(0))
            ? -1
            : 1);
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline int compare(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs,
        typename quan::meta::binary_op<
            quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>,
            quan::meta::minus,
            quan::mathematic_angle<Extent, Value_typeR>
        >::type const & eps
        = typename quan::meta::binary_op<
            quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>,
            quan::meta::minus,
            quan::mathematic_angle<Extent, Value_typeR>
        >::type(QUAN_FLOAT_EPSILON)
    )
    {
        typedef typename quan::meta::binary_op<
            quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>,
            quan::meta::minus,
            quan::mathematic_angle<Extent, Value_typeR>
        >::type comp_type;
        typedef typename comp_type::value_type comp_value_type;
        comp_type lhs1(lhs);
        return ((abs(lhs1-rhs)).numeric_value() <= eps.numeric_value() )
        ? 0
        :(((lhs1-rhs).numeric_value() < static_cast<comp_value_type>(0))
            ? -1
            : 1);
    }
// <
  template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline bool operator <(
        quan::mathematic_angle<Extent, Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) < 0;
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline bool operator <(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) < 0;
    }

// <=

    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline bool operator <=(
        quan::mathematic_angle<Extent, Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) <= 0;
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline bool operator <=(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) <= 0;
    }

    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline bool operator ==(
        quan::mathematic_angle<Extent, Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) == 0;
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline bool operator ==(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) == 0;
    }

//!=
    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline bool operator !=(
        quan::mathematic_angle<Extent, Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR,Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) != 0;
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline bool operator !=(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL,Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) != 0;
    }

//>=
    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline bool operator >=(
        quan::mathematic_angle<Extent, Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) >= 0;
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline bool operator >=(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) >= 0;
    }

// >
    template<
        typename Extent,
        typename Value_typeL,
        typename ReciprocalFractionR,
        typename Value_typeR
    >
    inline bool operator >(
        quan::mathematic_angle<Extent, Value_typeL>const& lhs,
        quan::fraction_of_revolution<Extent,ReciprocalFractionR, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) > 0;
    }

    template<
        typename Extent,
        typename ReciprocalFractionL,
        typename Value_typeL,
        typename Value_typeR
    >
    inline bool operator >(
        quan::fraction_of_revolution<Extent,ReciprocalFractionL, Value_typeL>const& lhs,
        quan::mathematic_angle<Extent, Value_typeR>const& rhs)
    {
        return compare(lhs,rhs) > 0;
    }

#if (defined _MSC_VER && _MSC_VER ==1400 && defined QUAN_SUPPRESS_VC8_ADL_BUG)
namespace quan { //quan
#endif
 // useful container for angles

    template<typename Value_type>
    struct angle_{

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<360>,
            Value_type
        > deg;

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<36000>,
            Value_type
        > cdeg; // 1/100ths of a degree

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<360000000>,
            Value_type
        > deg10e6;

         typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<3600000000>,
            Value_type
        > deg10e7;
    
        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<400>,
            Value_type
        > grad;

         typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<256>,
            Value_type
        > brad8;  // binary radian degree

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<65536>,
            Value_type
        > brad16; // 16 bit brad

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<16777216>,
            Value_type
        > brad24; //24 bit brad

          typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<1073741824>,
            Value_type
        > brad30; //30 bit brad

         typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<21600>,
            Value_type
        > min;

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<1296000>,
            Value_type
        > s;

        typedef fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<1>,
            Value_type
        > rev;
        typedef mathematic_angle<
            quan::meta::rational<1>,
            Value_type
        > rad;
        typedef mathematic_angle<
            quan::meta::rational<2>,
            Value_type
        > sr;
        
      //  static const rad   one;
        static constexpr rad   pi  = rad{3.141592653589793238462643383279502884197};
        static constexpr rad   two_pi = rad{2 * 3.141592653589793238462643383279502884197};
    };


#ifdef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
    template<typename Value_type>
    typename angle_<Value_type>::rad constexpr
    angle_<Value_type>::pi;

    template<typename Value_type>
    typename angle_<Value_type>::rad constexpr
    angle_<Value_type>::two_pi;

#endif

 struct angle : angle_<quan::quantity_traits::default_value_type>{};

}//quan

#endif
