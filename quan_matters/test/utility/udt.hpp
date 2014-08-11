#ifndef PQS_TEST_MY_UDT_HPP_INCLUDED
#define PQS_TEST_MY_UDT_HPP_INCLUDED

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

/*  
    dummy udt representing a value_type
    for test purposes.
    However the to_arithmetic struct at the end of the header
    is a useful example of how other UDT's must be treated
*/


#include <quan/meta/binary_op.hpp>
#include <quan/meta/rational.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/meta/if.hpp>
#include <quan/meta/and.hpp>
#include <type_traits>
#include <quan/meta/bool/true.hpp>
#include <iostream>
#include <quan/meta/is_arithmetic.hpp>

namespace my{
    template <typename T>
    struct udt;
}

namespace quan{namespace meta{

    template <typename T1, typename Op, typename T2>
    struct binary_op<
        my::udt<T1>, Op, my::udt<T2> 
    >{
        typedef my::udt<
            typename binary_op<T1,Op,T2>::type
        > type;
    };

    template <typename T1, typename T2>
    struct binary_op<
        my::udt<T1>, times, T2 ,
        typename quan::where_<
            quan::meta::and_<
                std::is_convertible<T2,T1>,
                std::is_convertible<T1,T2>
            >
        >::type
    >{
        typedef my::udt<
            typename binary_op<T1,times,T2>::type
        > type;
    };

    template <typename T1, typename T2>
    struct binary_op<
        T1, times, my::udt<T2> ,
        typename quan::where_<
            quan::meta::and_<
                std::is_convertible<T2,T1>,
                std::is_convertible<T1,T2>
            >
        >::type
    >{
        typedef my::udt<
            typename binary_op<T1,times,T2>::type
        > type;
    };

    template <typename T1, typename T2>
    struct binary_op<
        my::udt<T1>, divides, T2 ,
        typename quan::where_<
            quan::meta::and_<
                std::is_convertible<T2,T1>,
                std::is_convertible<T1,T2>
            >
        >::type
    >{
        typedef my::udt<
            typename binary_op<T1,divides,T2>::type
        > type;
    };

    template <typename T1, typename T2>
    struct binary_op<
        T1, divides, my::udt<T2> ,
        typename quan::where_<
            quan::meta::and_<
                std::is_convertible<T2,T1>,
                std::is_convertible<T1,T2>
            >
        >::type
    >{
        typedef my::udt<
            typename binary_op<T1,divides,T2>::type
        > type;
    };

    template <typename T1, typename Exp>
    struct binary_op<
       my::udt<T1>, pow, Exp
    >{
        typedef my::udt<
            typename binary_op<T1,times,T1>::type
        > type;
    };
    

}}//quan::meta

namespace my{

    template <typename T>
    struct udt{
        typedef T value_type;
    private:
        T m_value;
    public:
        T get_value()const{ return m_value;}

        udt():m_value(0){} // no division by zero wanted
        udt(T const & in) : m_value(in){}

        /*template <typename T1>
        udt ( T1 const & in, typename quan::where_<
                    std::is_convertible<T1,T>, int*
                >::type =0
        ): m_value(in){}*/

        template <typename T1>
        udt(udt<T1>  const &in ,
            typename quan::where_<
                    std::is_convertible<T1,T>, int*
            >::type =0): m_value(in.get_value()){}


        template <typename T1>
        udt& operator +=( udt<T1> const & rhs)
        {
            this->m_value += rhs.m_value;
            return *this;
        }

        template <typename T1>
        udt<
            typename quan::meta::binary_op<
                T, quan::meta::plus,T1
            >::type
        >
        operator +(  udt<T1> const & in)const
        {
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::plus,T1
                >::type
            > result(m_value + in.get_value());
            return result;
        }

        template <typename T1>
        udt& operator -=( udt<T1> const & rhs)
        {
            this->m_value -= rhs.m_value;
            return *this;
        }

        template <typename T1>
        udt<
            typename quan::meta::binary_op<
                T, quan::meta::minus,T1
            >::type
        >
        operator -(  udt<T1> const & in)const
        {
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::minus,T1
                >::type
            > result(m_value - in.get_value());
            return result;
        }

        template <typename T1>
        udt& operator *=( udt<T1> const & rhs)
        {
            this->m_value *= rhs.m_value;
            return *this;
        }

        template <typename T1>
        udt<
            typename quan::meta::binary_op<
                T, quan::meta::times,T1
            >::type
        >
        operator *(  udt<T1> const & in)const
        {
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::times,T1
                >::type
            > result(m_value * in.get_value());
            return result;
        }

        template <typename T1>
        typename quan::where_<
            std::is_convertible<T1,T>,
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::times,T1
                >::type
            >
        >::type
        operator *(  T1 const & in)const
        {
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::times,T1
                >::type
            > result(m_value * in);
            return result;
        }

        template <typename T1>
        udt& operator /=( udt<T1> const & rhs)
        {
            this->m_value /= rhs.m_value;
            return *this;
        }

        template <typename T1>
        typename quan::where_<
            std::is_convertible<T1,T>,
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::divides,T1
                >::type
            >
        >::type
        operator /(  udt<T1> const & in)const
        {
            udt<
                typename quan::meta::binary_op<
                    T, quan::meta::divides,T1
                >::type
            > result(m_value / in.get_value());
            return result;
        }        
    }; 

    /*template <typename TL, typename Tr>
    udt<quan::meta::binary_op<TL,quan::meta::divides,TR>
    operator / (TL const & lhs, udt<TR> const & rhs)
    {
        typedef udt<
            quan::meta::binary_op<
            TL,quan::meta::divides,TR
        > result_type;
        result_type result(lhs * rhs.get_value());
    }*/
// some distinguishing output 
    template <typename CharType,typename T>
    std::basic_ostream<CharType>& 
    operator <<(std::basic_ostream<CharType>& os, udt<T> const & u)
    {
        os << "{" << u.get_value() << "}";
        return os;
    }

    template <typename ValueType>
    bool operator < (udt<ValueType> const & a,udt<ValueType> const & b)
    {
        return a.get_value() < b.get_value();
    }
    template <typename ValueType>
    bool operator == (udt<ValueType> const & a,udt<ValueType> const & b)
    {
        return a.get_value() == b.get_value();
    }
}
namespace quan{

    template <
        int64_t N,
        int64_t D,
        typename T
    >
    inline
    typename quan::meta::binary_op<
        my::udt<T>,
        quan::meta::pow,
        quan::meta::rational<N,D>
    >::type
    pow (my::udt<T> const & v)
    {
        typedef typename quan::meta::binary_op<
            my::udt<T>,
            quan::meta::pow,
            quan::meta::rational<N,D>
        >::type result_type;
        using std::pow;
        result_type result(
            pow(v.get_value(),static_cast<T>( N ) / static_cast<T>(D))
        );  
        return result;   
    }
}
namespace quan{namespace meta{

    template <typename T>
    struct is_numeric<
        my::udt<T>
    > : quan::meta::true_{};

}}//quan::meta

#endif
