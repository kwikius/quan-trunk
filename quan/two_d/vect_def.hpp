#ifndef QUAN_TWO_D_VECT_DEF_HPP_INCLUDED
#define QUAN_TWO_D_VECT_DEF_HPP_INCLUDED
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


/*
    2d vect class template definition
*/

#include <quan/implicit_cast.hpp>
#include <quan/where.hpp>
#include <type_traits>

#if ! defined QUAN_NO_EXCEPTIONS
#include <stdexcept>
#endif

namespace quan{ namespace two_d{

    template <typename T>
    struct vect{
        typedef T value_type;
        constexpr vect() : x( static_cast<T>(0) ),  y( static_cast<T>(0) ){}

        template <typename Ta, typename Tb>
        constexpr vect(Ta const & x_in, Tb const & y_in)
        : x( quan::implicit_cast<T>(x_in) ),  y( quan::implicit_cast<T>(y_in) ){}

        template <typename T1>
        constexpr vect(vect<T1> const & in)
        : x( quan::implicit_cast<T>(in.x) ),  y( quan::implicit_cast<T>(in.y) ){}
        T x,y;

        template <typename T1>
        vect& operator =( vect<T1> const & in)
        {
            this->x = in.x;
            this->y = in.y;
            return *this;
        }

        template <typename T1>
        vect& operator +=( vect<T1> const & in)
        {
            this->x += in.x;
            this->y += in.y;
            return *this;
        }
        template <typename T1>
        vect& operator -=( vect<T1> const & in)
        {
            this->x -= in.x;
            this->y -= in.y;
            return *this;
        }
        vect operator -()const
        {
            vect result = vect(-x,-y);
            return result;
        }

        template <typename Arithmetic>
        typename quan::where_<
            std::is_arithmetic<Arithmetic>,
            vect<T> &
        >::type
        operator *=(Arithmetic const & in)
        {
            this->x *=in;
            this->y *=in;
            return *this;
        }
        template <typename Arithmetic>
        typename quan::where_<
            std::is_arithmetic<Arithmetic>,
            vect &
        >::type
        operator /=(Arithmetic const & in)
        {
            this->x /=in;
            this->y /=in;
            return *this;
        }

        T & operator[](int n)
        {
           static_assert( (sizeof(vect) == 2 * sizeof(T)), "array operator malformed" );
#if !defined QUAN_NO_EXCEPTIONS
           if( (n < 0) || (n >1)){
                throw std::length_error("array subscript out of range in quat");
           }
#endif
           return (&x)[n];
        }

        T const & operator[](int n)const
        {
           static_assert( (sizeof(vect) == 2 * sizeof(T)), "array operator malformed" );
#if !defined QUAN_NO_EXCEPTIONS
           if( (n < 0) || (n >1)){
                throw std::length_error("array subscript out of range in quat");
           }
#endif
           return (&x)[n];
        }
    };

}}//quan::two_d
#endif
