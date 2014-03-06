#ifndef QUAN_THREE_D_VECT_DEF_HPP_INCLUDED
#define QUAN_THREE_D_VECT_DEF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//

/*
    3d vect definition
*/
#include <quan/config.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/where.hpp>
#include <type_traits>
#include <quan/static_assert.hpp>
#include <stdexcept>

namespace quan{ namespace three_d{
 
   template <typename T>
    struct vect
    {
        typedef T value_type;
        vect() 
        : x( static_cast<T>(0) )
        , y( static_cast<T>(0) )
        , z( static_cast<T>(0) )
        {}
        template <typename Tx, typename Ty, typename Tz>
        vect(Tx const & x_in, Ty const & y_in, Tz const & z_in)
        : x( quan::implicit_cast<T>(x_in) )
        , y( quan::implicit_cast<T>(y_in) )
        , z( quan::implicit_cast<T>(z_in) ){}
        T x,y,z;

        template <typename T1>
        vect( vect<T1> const & in)
        : x(in.x),y(in.y),z(in.z){}
        template <typename T1>
        vect &
        operator = (vect<T1> const & in)
        {
            this->x = in.x;
            this->y = in.y;
            this->z = in.z;
            return * this;
        }
        
        vect operator -()const
        {
            return vect(-x,-y,-z);
        }
        template <typename T1>
        vect &
        operator += (vect<T1> const & in)
        {
            this->x += in.x;
            this->y += in.y;
            this->z += in.z;
            return * this;
        }
        template <typename T1>
        vect &
        operator -= (vect<T1> const & in)
        {
            this->x -= in.x;
            this->y -= in.y;
            this->z -= in.z;
            return * this;
        }

        template <typename T1>
        typename quan::where_<
            std::is_arithmetic<T1>,
            vect &
        >::type
        operator *= (T1 const & in)
        {
            this->x *= in;
            this->y *= in;
            this->z *= in;
            return *this;
        }

        template <typename T1>
        typename quan::where_<
            std::is_arithmetic<T1>,
            vect &
        >::type
        operator /= (T1 const & in)
        {
            this->x /= in;
            this->y /= in;
            this->z /= in;
            return *this;
        }

        T & operator[](int n)
        {
            switch (n){
                case 0:
                    return x;
                case 1:
                    return y; 
                case 2:
                    return z;
                default:
#if defined QUAN_NO_EXCEPTIONS
// crap really maybe some dummy static value?
                 return x;
#else
                 throw std::logic_error(
                     "array subscript out of range in vect"
                 );         
#endif
            }
        }
        T const & operator[](int n)const
        {
            switch (n){
                case 0:
                    return x;
                case 1:
                    return y; 
                case 2:
                    return z;
                default:
#if defined QUAN_NO_EXCEPTIONS
                    return x;
#else
                    throw std::logic_error(
                        "array subscript out of range in vect"
                    );
                    
#endif
            }
        }
        
    };

}}//quan::three_d

#endif

