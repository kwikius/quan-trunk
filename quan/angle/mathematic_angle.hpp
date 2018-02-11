#ifndef QUAN_ANGLE_MATHEMATICAL_ANGLE_HPP_INCLUDED
#define QUAN_ANGLE_MATHEMATICAL_ANGLE_HPP_INCLUDED
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
    mathematic_angle implementation(radians, steradians)
    mathematic_angle is really just a numeric type with extra attributes
    therefore it can be 'decayed' to its numeric value_type.
    The Extent parameter is a rational number e.g radians  has an extent of 1
    , while steradians has an extent of two.
    Therefore radians * radians --> steradians
    etc

    Also see <quan/angles/fraction_of-revolution.hpp> for
    fraction of revolution angles e.g degrees,minutes, seconds, grad
*/
#include <quan/config.hpp>
#ifdef QUAN_AVR_NO_CPP_STDLIB
#include "math.h"
#include <quan/std/tr1/is_same.hpp>
#include <quan/std/tr1/integral_constant.hpp>
#if defined abs
#undef abs
#endif
//#include "float.h"
#else
#include <type_traits>
#include <cmath>
#endif

#include <quan/meta/if.hpp>
#include <quan/meta/is_angle.hpp>
#include <quan/angle/meta_math_angle.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/is_angle_value_type.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/constants/constant.hpp>
#include <quan/arithmetic_convert.hpp>
#include <quan/modulus.hpp>

namespace quan{

    template <
        typename Extent, //Is a quan::meta::rational
        typename Value_type
    >
    class mathematic_angle{
        Value_type m_value;
    public:
        typedef Value_type value_type;
        typedef Extent extent;
        typedef typename quan::meta::if_<
            quan::meta::eq_<
                Extent,
                quan::meta::rational<0>
            >,
            value_type,
            mathematic_angle
        >::type type;

      QUAN_CONSTEXPR mathematic_angle(): m_value{static_cast<Value_type>(0)}{}

      template<typename Value_type1>
      QUAN_CONSTEXPR
      mathematic_angle(
            Value_type1 const & v,
            typename quan::where_<
                quan::meta::is_angle_value_type<Value_type1>,
                void*
            >::type = 0 )
        : m_value{implicit_cast<Value_type>(v)}{}

      QUAN_CONSTEXPR  mathematic_angle(const mathematic_angle& in)
        :m_value{in.m_value}{}

        template<
            typename Value_type1
        >
        QUAN_CONSTEXPR
        mathematic_angle(
            mathematic_angle<Extent,Value_type1> const & r
        )
        :m_value{implicit_cast<Value_type>(r.numeric_value())}{}

        template<
            typename ReciprocalFraction,
            typename Value_type1
        >
        
        inline QUAN_CONSTEXPR mathematic_angle(
            fraction_of_revolution<
                Extent,
                ReciprocalFraction,
                Value_type1
            > const & fr
        );

        QUAN_CONSTEXPR Value_type numeric_value()const {return m_value;}

        template <typename Angle>
        typename quan::where_<
            std::is_same<Angle,mathematic_angle>,
            void
        >::type
        set_numeric_value(Value_type const & v)
        {
            m_value = v;
        }

        template <typename Angle>
        QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Angle,mathematic_angle>,
            Value_type&
        >::type
        reference_numeric_value()
        {
            return this->m_value ;
        }

        template <typename Angle>
        QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Angle,mathematic_angle>,
            Value_type const&
        >::type
        reference_numeric_value()const
        {
            return this->m_value ;
        }

        template <typename Angle>
        QUAN_CONSTEXPR
        typename quan::where_<
            std::is_same<Angle,mathematic_angle>,
            Value_type const&
        >::type
        const_reference_numeric_value()const
        {
            return this->m_value ;
        }

#ifndef QUAN_NO_MATH_ANGLE_NUMERIC_CONVERSION
        QUAN_CONSTEXPR operator Value_type()const {return m_value;}
#endif

        QUAN_CONSTEXPR mathematic_angle operator -()const
        {
            return mathematic_angle{-this->m_value};
        }

        QUAN_CONSTEXPR mathematic_angle operator +()const
        {
            return mathematic_angle{ this->m_value};
        }

        //add fraction_of_rev ops
        template<
            typename Value_type1
        >
        mathematic_angle &
        operator +=(
            mathematic_angle<Extent,Value_type1> const & in)
        {
            this->m_value += in.numeric_value();
            return *this;
        }

        template<
            typename ReciprocalFraction,
            typename Value_type1
        >
        mathematic_angle & operator +=(

            fraction_of_revolution<
                Extent,
                ReciprocalFraction,
                Value_type1
            > const & fr
        ){
            this->m_value += mathematic_angle{fr}.m_value;
            return *this;
        }

        template<
            typename ReciprocalFraction,
            typename Value_type1
        >
        mathematic_angle & operator -=(

            fraction_of_revolution<
                Extent,
                ReciprocalFraction,
                Value_type1
            > const & fr
        ){
            this->m_value -= mathematic_angle{fr}.m_value;
            return *this;
        }

        template<
            typename Value_type1
        >
        mathematic_angle &
        operator -=(mathematic_angle<Extent,Value_type1> const & in)
        {
            this->m_value -= in.numeric_value();
            return *this;
        }

        template<typename Value_type1>
        typename quan::where_<
            quan::meta::is_angle_value_type<Value_type1>,
            mathematic_angle &
        >::type  operator *=(Value_type1 const & in)
        {
            this->m_value *= in;
            return *this;
        }
        template<typename Value_type1>
        typename quan::where_<
            quan::meta::is_angle_value_type<Value_type1>,
            mathematic_angle &
        >::type operator /=(Value_type1 const & in)
        {
            this->m_value /= in;
            return *this;
        }

    };//mathematic_angle

    namespace meta{

        template <typename Extent, typename ValueType>
        struct is_numeric<
            quan::mathematic_angle<Extent,ValueType>
        > : std::true_type{};

        template <typename Extent, typename ValueType>
        struct is_mathematic_angle<
            quan::mathematic_angle<Extent,ValueType>
        > : std::true_type{};

    }//meta
}//quan

#if !(defined _MSC_VER && _MSC_VER ==1400 && defined QUAN_SUPPRESS_VC8_ADL_BUG)
namespace quan { //quan
#endif

    template<
        typename Extent,
        typename Value_typeA,
        typename Value_typeB
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op<
        quan::mathematic_angle<Extent,Value_typeA>,
        quan::meta::plus,
        quan::mathematic_angle<Extent,Value_typeB>
    >::type
    operator + (
        quan::mathematic_angle<Extent,Value_typeA> const & ra,
        quan::mathematic_angle<Extent,Value_typeB> const & rb
    )
    {
       typedef typename quan::meta::binary_op<
            quan::mathematic_angle<Extent,Value_typeA>,
            quan::meta::plus,
            quan::mathematic_angle<Extent,Value_typeB>
        >::type  result_type;
       return result_type{result_type{ra}.numeric_value() + result_type{rb}.numeric_value()} ; 
    }

   template<
        typename Extent,
        typename Value_typeA,
        typename Value_typeB
    >
   inline QUAN_CONSTEXPR
   typename quan::where_<
      quan::meta::is_angle_value_type<Value_typeB>,
      typename quan::meta::binary_op<
         quan::mathematic_angle<Extent,Value_typeA>,
         quan::meta::plus,
         Value_typeB
      >::type
    >::type
    operator + (
        quan::mathematic_angle<Extent,Value_typeA> const & ra,
        Value_typeB const & rb
    )
    {
        return typename quan::meta::binary_op<
            quan::mathematic_angle<Extent,Value_typeA>,
            quan::meta::plus,
            Value_typeB
        >::type{ ra.numeric_value() + rb };
    }

   template<
        typename Extent,
        typename Value_typeA,
        typename Value_typeB
    >
   inline QUAN_CONSTEXPR
   typename quan::where_<
      quan::meta::is_angle_value_type<Value_typeA>,
      typename quan::meta::binary_op<
         Value_typeA,
         quan::meta::plus,
         quan::mathematic_angle<Extent,Value_typeB>
      >::type
    >::type
    operator + (
        Value_typeA const & ra,
        quan::mathematic_angle<Extent,Value_typeB> const & rb
    )
    {
        return typename quan::meta::binary_op<
            Value_typeA,
            quan::meta::plus,
            quan::mathematic_angle<Extent,Value_typeB>
        >::type{ ra + rb.numeric_value() };
    }

    template<
        typename Extent,
        typename Value_typeA,
        typename Value_typeB
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op<
        quan::mathematic_angle<Extent,Value_typeA>,
        quan::meta::minus,
        quan::mathematic_angle<Extent,Value_typeB>
    >::type
    operator - (
        quan::mathematic_angle<Extent,Value_typeA> const & ra,
        quan::mathematic_angle<Extent,Value_typeB> const & rb
    )
    {
        return typename quan::meta::binary_op<
            quan::mathematic_angle<Extent,Value_typeA>,
            quan::meta::minus,
            quan::mathematic_angle<Extent,Value_typeB>
        >::type{ra.numeric_value() - rb.numeric_value()};
    }


   template<
        typename Extent,
        typename Value_typeA,
        typename Value_typeB
    >
   inline QUAN_CONSTEXPR
   typename quan::where_<
      quan::meta::is_angle_value_type<Value_typeB>,
      typename quan::meta::binary_op<
         quan::mathematic_angle<Extent,Value_typeA>,
         quan::meta::minus,
         Value_typeB
      >::type
    >::type
    operator - (
        quan::mathematic_angle<Extent,Value_typeA> const & ra,
        Value_typeB const & rb
    )
    {
        return typename quan::meta::binary_op<
            quan::mathematic_angle<Extent,Value_typeA>,
            quan::meta::minus,
            Value_typeB
        >::type{ra.numeric_value() - rb};
    }

   template<
        typename Extent,
        typename Value_typeA,
        typename Value_typeB
    >
   inline QUAN_CONSTEXPR
   typename quan::where_<
      quan::meta::is_angle_value_type<Value_typeA>,
      typename quan::meta::binary_op<
         Value_typeA,
         quan::meta::minus,
         quan::mathematic_angle<Extent,Value_typeB>
      >::type
    >::type
    operator - (
        Value_typeA const & ra,
        quan::mathematic_angle<Extent,Value_typeB> const & rb
    )
    {
        return typename quan::meta::binary_op<
            Value_typeA,
            quan::meta::minus,
            quan::mathematic_angle<Extent,Value_typeB>
        >::type{ra - rb.numeric_value()};
    }

    template<
        typename ExtentA,
        typename Value_typeA,
        typename ExtentB,
        typename Value_typeB
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op<
        quan::mathematic_angle<ExtentA,Value_typeA>,
        quan::meta::times,
        quan::mathematic_angle<ExtentB,Value_typeB>
    >::type
    operator * (
        quan::mathematic_angle<ExtentA,Value_typeA> const & ra,
        quan::mathematic_angle<ExtentB,Value_typeB> const & rb
    )
    {
        return typename quan::meta::binary_op<
            quan::mathematic_angle<ExtentA,Value_typeA>,
            quan::meta::times,
            quan::mathematic_angle<ExtentB,Value_typeB>
        >::type{ra.numeric_value() * rb.numeric_value()};
    }

    template<
        typename Extent,
        typename Value_type,
        typename Value_type1
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<Value_type1>,
        quan::mathematic_angle<Extent,Value_type>,
        quan::meta::times,
        Value_type1
    >::type
    operator * (
        quan::mathematic_angle<Extent,Value_type> const & ra,
        Value_type1 const & b)
    {
        return typename quan::meta::binary_op<
            quan::mathematic_angle<Extent,Value_type>,
            quan::meta::times,
            Value_type1
        >::type{ra.numeric_value() * b};
       
    }

    template<
        typename Value_type1,
        typename Extent,
        typename Value_type
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<Value_type1>,
        Value_type1,
        quan::meta::times,
        quan::mathematic_angle<Extent,Value_type>
    >::type
    operator * (
        Value_type1 const & b,
        quan::mathematic_angle<Extent,Value_type> const & ra
    )
    {
        return typename quan::meta::binary_op<
            Value_type1,
            quan::meta::times,
            quan::mathematic_angle<Extent,Value_type>
        >::type{b * ra.numeric_value()};
    }

    template<
        typename ExtentA,
        typename Value_typeA,
        typename ExtentB,
        typename Value_typeB
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op<
        quan::mathematic_angle<ExtentA,Value_typeA>,
        quan::meta::divides,
        quan::mathematic_angle<ExtentB,Value_typeB>
    >::type
    operator /(
        quan::mathematic_angle<ExtentA,Value_typeA> const & ra,
        quan::mathematic_angle<ExtentB,Value_typeB> const & rb
    )
    {
       return  typename quan::meta::binary_op<
            quan::mathematic_angle<ExtentA,Value_typeA>,
            quan::meta::divides,
            quan::mathematic_angle<ExtentB,Value_typeB>
        >::type{ra.numeric_value() / rb.numeric_value()};
    }

    template<
        typename Extent,
        typename Value_type,
        typename Value_type1
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<Value_type1>,
        quan::mathematic_angle<Extent,Value_type>,
        quan::meta::divides,
        Value_type1
    >::type
    operator / (
        quan::mathematic_angle<Extent,Value_type> const & ra,
        Value_type1 const & b
    )
    {
       return typename quan::meta::binary_op<
            quan::mathematic_angle<Extent,Value_type>,
            quan::meta::divides,
            Value_type1
        >::type{ra.numeric_value() / b};
    }

    template<
        typename Value_type1,
        typename Extent,
        typename Value_type
    >
    inline QUAN_CONSTEXPR
    typename quan::meta::binary_op_if<
        quan::meta::is_angle_value_type<Value_type1>,
        Value_type1,
        quan::meta::divides,
        quan::mathematic_angle<Extent,Value_type>
    >::type
    operator / (
        Value_type1 const & b,
        quan::mathematic_angle<Extent,Value_type> const & ra)
    {
       return typename quan::meta::binary_op<
            Value_type1,
            quan::meta::divides,
            quan::mathematic_angle<Extent,Value_type>
        >::type{b / ra.numeric_value()};
    }

    template<
        typename Extent,
        typename Value_typeL,
        typename Value_typeR
    >
    inline
    int QUAN_CONSTEXPR
    compare(quan::mathematic_angle<Extent,Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR> const& rhs ,
        quan::mathematic_angle<
            Extent,
            typename quan::meta::binary_op<
                Value_typeL,
                quan::meta::minus,
                Value_typeR
            >::type
        > const & epsilon = quan::mathematic_angle<
            Extent,
            typename quan::meta::binary_op<
                Value_typeL,
                quan::meta::minus,
                Value_typeR
            >::type
        >{0}
    )
    {
        typedef typename quan::meta::binary_op<
            quan::mathematic_angle<Extent, Value_typeL>,
            quan::meta::minus,
            quan::mathematic_angle<Extent, Value_typeR>
        >::type comp_type;
        return ((abs(lhs-rhs)).numeric_value() <= abs(epsilon).numeric_value())
        ? 0
        :(((lhs-rhs).numeric_value() < comp_type(0).numeric_value())
            ? -1
            : 1);
    }

    template<typename Extent, typename Value_typeL,typename Value_typeR>
    inline QUAN_CONSTEXPR
    bool operator <(
        quan::mathematic_angle<Extent, Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR>const& rhs
    )
    {
        return compare(lhs,rhs) < 0;
    }

    template<typename Extent, typename Value_typeL,typename Value_typeR>
    inline QUAN_CONSTEXPR
    bool operator <=(
        quan::mathematic_angle<Extent,Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR>const& rhs
    )
    {
        return compare(lhs,rhs) <= 0;
    }

    template<typename Extent, typename Value_typeL,typename Value_typeR>
    inline QUAN_CONSTEXPR
    bool operator ==(
        quan::mathematic_angle<Extent, Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR>const& rhs
    )
    {
        return compare(lhs,rhs) == 0;
    }

    template<typename Extent, typename Value_typeL,typename Value_typeR>
    inline QUAN_CONSTEXPR
    bool operator !=(
        quan::mathematic_angle<Extent, Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR>const& rhs
    )
    {
        return compare(lhs,rhs) != 0;
    }

    template<typename Extent, typename Value_typeL,typename Value_typeR>
    inline QUAN_CONSTEXPR
    bool operator >=(
        quan::mathematic_angle<Extent, Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR>const& rhs
    )
    {
        return compare(lhs,rhs) >= 0;
    }

    template<typename Extent, typename Value_typeL,typename Value_typeR>
    inline QUAN_CONSTEXPR
    bool operator >(
        quan::mathematic_angle<Extent, Value_typeL>const & lhs,
        quan::mathematic_angle<Extent,Value_typeR>const& rhs
    )
    {
        return compare(lhs,rhs) > 0;
    }

#if !(defined _MSC_VER && _MSC_VER ==1400 && defined QUAN_SUPPRESS_VC8_ADL_BUG)
} //quan
#endif

namespace quan{ namespace impl_detail{

}}

namespace quan {

    

    template<typename Value_type>
    inline
    Value_type cos(
        quan::mathematic_angle<
            quan::meta::rational<1>,
            Value_type
        >const& r)
    {
#ifndef QUAN_AVR_NO_CPP_STDLIB
        using std::cos;
#else
       using ::cos;
#endif
        return cos(r.numeric_value());
    }

    template<typename Value_type>
    inline
    Value_type sin(quan::mathematic_angle<quan::meta::rational<1>,Value_type>const& r)
    {
#ifndef QUAN_AVR_NO_CPP_STDLIB
        using std::sin;
#else
       using ::sin;
#endif
        return sin(r.numeric_value());

    }

    template<typename Value_type>
    inline
    Value_type tan(quan::mathematic_angle<quan::meta::rational<1>,Value_type>const& r)
    {
#ifndef QUAN_AVR_NO_CPP_STDLIB
        using std::tan;
#else
       using ::tan;
#endif
        return tan(r.numeric_value());
    }

    template <
        int64_t N,
        int64_t D,
        typename Extent,
        typename Value_type
    >
    inline
    typename quan::meta::binary_op<
        typename quan::mathematic_angle<Extent,Value_type>::type,
        quan::meta::pow,
        typename quan::meta::rational<N,D>::type
    >::type

    pow(quan::mathematic_angle<Extent,Value_type> const& r)
    {
        typedef  typename quan::meta::binary_op<
            typename quan::mathematic_angle<Extent,Value_type>::type,
            quan::meta::pow,
            typename quan::meta::rational<N,D>::type
        >::type result_type;
        return result_type(quan::pow<N,D>(r.numeric_value()));

    }

    template <
        int64_t N,
        typename Extent,
        typename Value_type
    >
    inline
    typename quan::meta::binary_op<
        typename quan::mathematic_angle<Extent,Value_type>::type,
        quan::meta::pow,
        typename quan::meta::rational<N,1>::type
    >::type

    pow(quan::mathematic_angle<Extent,Value_type> const& r)
    {
        typedef  typename quan::meta::binary_op<
            typename quan::mathematic_angle<Extent,Value_type>::type,
            quan::meta::pow,
            typename quan::meta::rational<N,1>::type
        >::type result_type;
        return result_type(quan::pow<N,1>(r.numeric_value()));

    }
    template< typename Extent, typename Value_type>
    inline QUAN_CONSTEXPR
    quan::mathematic_angle<Extent,Value_type>
    abs(quan::mathematic_angle<Extent,Value_type> const& r)
    {
       return 
        ( r.numeric_value() < static_cast<Value_type>(0))
        ? -r : r;
     
    }

   template<
      typename Extent,
      typename Value_type
   >
   inline 
   quan::mathematic_angle<
      Extent, 
      typename std::common_type<
         Value_type,QUAN_FLOAT_TYPE
      >::type
   >
   modulo( quan::mathematic_angle<Extent,Value_type> const & fr)
   {
      typedef quan::mathematic_angle<
         Extent, 
         typename std::common_type<
            Value_type,QUAN_FLOAT_TYPE
         >::type
      > result_type;
      return result_type{quan::modulus(fr.numeric_value(),2 * quan::constant_<QUAN_FLOAT_TYPE>::pi) };
   }

   template<
      typename Extent,
      typename Value_type
   >
   inline 
   quan::mathematic_angle<
      Extent, 
      typename std::common_type<
         Value_type,QUAN_FLOAT_TYPE
      >::type
   >
   unsigned_modulo( quan::mathematic_angle<Extent,Value_type> const & fr)
   {
      typedef quan::mathematic_angle<
         Extent, 
         typename std::common_type<
            Value_type,QUAN_FLOAT_TYPE
         >::type
      > result_type;
      constexpr auto one_rev = 2 * quan::constant_<QUAN_FLOAT_TYPE>::pi;
      if ( fr.numeric_value() >= Value_type{0}){
        return result_type(
           quan::modulus(fr.numeric_value(),one_rev )
        );
      }else{
         return result_type(
            quan::modulus(fr.numeric_value(), one_rev) + one_rev
         );
      }
   }

   template<
      typename Extent,
      typename Value_type
   >
   inline 
   quan::mathematic_angle<
      Extent, 
      typename std::common_type<
         Value_type,QUAN_FLOAT_TYPE
      >::type
   >
   signed_modulo( quan::mathematic_angle<Extent,Value_type> const & fr)
   {
      static_assert(std::is_unsigned<Value_type>::value == false,"not useful for unsigned types");
      typedef quan::mathematic_angle<
         Extent, 
         typename std::common_type<
            Value_type,QUAN_FLOAT_TYPE
         >::type
      > result_type;
      result_type const unsigned_result = unsigned_modulo(fr);
      constexpr auto one_rev = 2 * quan::constant_<QUAN_FLOAT_TYPE>::pi;
      if (unsigned_result.numeric_value() <= one_rev/2 ){
          return unsigned_result;
      }else{
          return unsigned_result - result_type{one_rev} ;
      }
   }

}


#endif
