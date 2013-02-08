#ifndef QUAN_ANGLE_MATHEMATICAL_ANGLE_HPP_INCLUDED
#define QUAN_ANGLE_MATHEMATICAL_ANGLE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

/// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    mathematic_angle implementation(radians, steradians)
    mathematic_angle can be seen as a numeric type with extra attributes
    therefore it can be 'decayed' to its numeric value_type.
    The Extent parameter is a rational number e.g radians  has an extent of 1
    , while steradians has an extent of two.
    Therefore radians * radians --> steradians
    etc

    Also see <quan/angles/fraction_of-revolution.hpp> for
    e.g degrees,minutes, seconds
*/
#include <quan/config.hpp>
#ifdef __AVR__
#include "math.h"
//#include "float.h"
#if defined abs
#undef abs
#endif

#else
#include <cmath>
#endif
#include <quan/meta/is_angle.hpp>
#include <quan/angle/meta_math_angle.hpp>
#include <quan/meta/binary_op_if.hpp>
#include <quan/meta/is_numeric.hpp>
#include <quan/meta/is_angle_value_type.hpp>
#include <quan/implicit_cast.hpp>
#include <type_traits>
#include <type_traits>
#include <quan/constants/constant.hpp>
#include <quan/meta/if.hpp>

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

     QUAN_CONSTEXPR   mathematic_angle(): m_value{static_cast<Value_type>(0)}{}

      //  mathematic_angle(Value_type const & v): m_value(v){}

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
        :m_value{implicit_cast<Value_type>(r.m_value)}{}

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
        > const & epsilon
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

namespace quan {

    template<typename Value_type>
    inline
    Value_type cos(
        quan::mathematic_angle<
            quan::meta::rational<1>,
            Value_type
        >const& r)
    {
#ifndef __AVR__
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
#ifndef __AVR__
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
#ifndef __AVR__
        using std::tan;
#else
       using ::tan;
#endif
        return tan(r.numeric_value());
    }

    template <
        QUAN_INT32 N,
        QUAN_INT32 D,
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
        QUAN_INT32 N,
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
    quan::mathematic_angle<Extent, Value_type>
    modulo( quan::mathematic_angle<Extent,Value_type> const & fr)
    {
        // check extent == 1
        Value_type v = fr.numeric_value() / (2 * quan::constant_<Value_type>::pi);
        Value_type n;

#ifndef __AVR__
        using std::modf;
#else 
        using ::modf;
#endif
     //   Value_type fract = modf(v,&n);
        return quan::mathematic_angle<
            Extent,
            Value_type
        > (modf(v,&n) * 2 * quan::constant_<Value_type>::pi);
       
    }
}

#endif
