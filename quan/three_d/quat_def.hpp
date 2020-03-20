#ifndef QUAN_THREE_D_QUAT_DEF_HPP_INCLUDED
#define QUAN_THREE_D_QUAT_DEF_HPP_INCLUDED
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
// Copyright Janek Kozicki 2006

/*
    quaternion definition
*/
#include <quan/config.hpp>
#include <quan/implicit_cast.hpp>
#if ! defined QUAN_NO_EXCEPTIONS
#include <stdexcept>
#endif

namespace quan{ namespace three_d{
 
   template <typename T>
    struct quat
    {
        typedef T value_type;
        quat() 
        : w( static_cast<T>(0) )
        , x( static_cast<T>(0) )
        , y( static_cast<T>(0) )
        , z( static_cast<T>(0) )
        {}
        template <typename Tw, typename Tx, typename Ty, typename Tz>
        quat(Tw const & w_in, Tx const & x_in, Ty const & y_in, Tz const & z_in)
        : w( quan::implicit_cast<T>(w_in) )
        , x( quan::implicit_cast<T>(x_in) )
        , y( quan::implicit_cast<T>(y_in) )
        , z( quan::implicit_cast<T>(z_in) ){}
        T w,x,y,z;

        template <typename T1>
        quat &
        operator = (quat<T1> const & in)
        {
            this->w = in.w;
            this->x = in.x;
            this->y = in.y;
            this->z = in.z;
            return * this;
        }

        template <typename T1>
        quat &
        operator += (quat<T1> const & in)
        {
            this->w += in.w;
            this->x += in.x;
            this->y += in.y;
            this->z += in.z;
            return * this;
        }
        template <typename T1>
        quat &
        operator -= (quat<T1> const & in)
        {
            this->w -= in.w;
            this->x -= in.x;
            this->y -= in.y;
            this->z -= in.z;
            return * this;
        }

        
        T & operator[](int n)
        {
            static_assert( (sizeof(quat) == 4 * sizeof(T)), "array operator malformed" );
#if  defined QUAN_NO_EXCEPTIONS
            T* p = & x;
            return p[n % 3];
#else
            if( (n < 0) || (n >3)){
             return 
                throw std::length_error("array subscript out of range in quat");
            }
            
            T* p = & x;
            return p[n];
#endif
        }

        T const & operator[](int n)const
        {
            static_assert( (sizeof(quat) == 4 * sizeof(T)) ,"array operator malformed");
#if  defined QUAN_NO_EXCEPTIONS
            T* p = & x;
            return p[n % 3];
#else
            if( (n < 0) || (n >3)){
                throw std::length_error("array subscript out of range in quat");
            }
            
            T const * p = & x;
            return p[n];
#endif
        }
    }; // quat
}}//quan::three_d

#endif

