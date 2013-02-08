#ifndef QUAN_THREE_D_QUAT_DEF_HPP_INCLUDED
#define QUAN_THREE_D_QUAT_DEF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
// Copyright Janek Kozicki 2006

/*
    quaternion definition
*/

#include <quan/implicit_cast.hpp>

#include <stdexcept>

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
            if( (n < 0) || (n >3)){
                throw std::length_error("array subscript out of range in quat");
            }
            
            T* p = & x;
            return p[n];
        }
        T const & operator[](int n)const
        {
            static_assert( (sizeof(quat) == 4 * sizeof(T)) ,"array operator malformed");
            if( (n < 0) || (n >3)){
                throw std::length_error("array subscript out of range in quat");
            }
            
            T const * p = & x;
            return p[n];
        }
        
    };

}}//quan::three_d

#endif

