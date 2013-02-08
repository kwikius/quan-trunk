#ifndef QUAN_TWO_D_VECT_DEF_HPP_INCLUDED
#define QUAN_TWO_D_VECT_DEF_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andy Little 2005


/*
    2d vect class template definition
*/

#include <quan/implicit_cast.hpp>
#include <quan/where.hpp>
#include <type_traits>

namespace quan{ namespace two_d{

    template <typename T>
    struct vect{
        typedef T value_type;
        vect() : x( static_cast<T>(0) ),  y( static_cast<T>(0) ){}
        template <typename Ta, typename Tb>
        vect(Ta const & x_in, Tb const & y_in)
        : x( quan::implicit_cast<T>(x_in) ),  y( quan::implicit_cast<T>(y_in) ){}
        template <typename T1>
        vect(vect<T1> const & in)
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
    };

}}//quan::two_d
#endif
