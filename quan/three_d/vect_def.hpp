#ifndef QUAN_THREE_D_VECT_DEF_HPP_INCLUDED
#define QUAN_THREE_D_VECT_DEF_HPP_INCLUDED
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

/*
    3d vect definition
*/
#include <quan/config.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/where.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <type_traits>
#else
#include <quan/std/tr1/is_arithmetic.hpp>
#endif
#include <quan/static_assert.hpp>
#if !defined QUAN_NO_EXCEPTIONS
#include <stdexcept>
#endif

namespace quan{ namespace three_d{
 
   template <typename T>
    struct vect
    {
        typedef T value_type;
        constexpr vect() 
        : x( static_cast<T>(0) )
        , y( static_cast<T>(0) )
        , z( static_cast<T>(0) )
        {}

        template <typename Tx, typename Ty, typename Tz>
        constexpr 
        vect(Tx const & x_in, Ty const & y_in, Tz const & z_in)
        : x( quan::implicit_cast<T>(x_in) )
        , y( quan::implicit_cast<T>(y_in) )
        , z( quan::implicit_cast<T>(z_in) ){}
        T x,y,z;

        template <typename T1>
        constexpr
        vect( vect<T1> const & in)
        : x(in.x),y(in.y),z(in.z){}

        template <typename T1>
        vect &
        operator = (vect<T1> const & in)
        {
            return * this = vect{in} ;
        }
        
        constexpr vect operator -()const
        {
            return vect(-x,-y,-z);
        }
        
        template <typename T1>
        vect &
        operator += (vect<T1> const & in)
        {
           return *this = vect{this->x + in.x,this->y + in.y, this->z + in.z};
        }

        template <typename T1>
        vect &
        operator -= (vect<T1> const & in)
        {
           return *this = vect{this->x - in.x,this->y - in.y, this->z - in.z};
        }

        template <typename T1>
        typename quan::where_<
            std::is_arithmetic<T1>,
            vect &
        >::type
        operator *= (T1 const & in)
        {
            return *this = vect{this->x * in,this->y * in, this->z * in};
        }

        template <typename T1>
        typename quan::where_<
            std::is_arithmetic<T1>,
            vect &
        >::type
        operator /= (T1 const & in)
        {
            return *this = vect{this->x / in,this->y / in, this->z / in};
        }

        T & operator[](int n)
        {
           static_assert( (sizeof(vect) == 3 * sizeof(T)), "array operator malformed" );
#if !defined QUAN_NO_EXCEPTIONS
           if( (n < 0) || (n >2)){
                throw std::length_error("array subscript out of range in quat");
           }
#endif
           return (&x)[n];
        }

        T const & operator[](int n)const
        {
           static_assert( (sizeof(vect) == 3 * sizeof(T)), "array operator malformed" );
#if !defined QUAN_NO_EXCEPTIONS
           if( (n < 0) || (n >2)){
                throw std::length_error("array subscript out of range in quat");
           }
#endif
           return (&x)[n];
        }
        
    };

}}//quan::three_d

#endif

