#ifndef QUAN_TWO_D_BOX_HPP_INCLUDED
#define QUAN_TWO_D_BOX_HPP_INCLUDED
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


#include <quan/two_d/vect.hpp>
#include <quan/implicit_cast.hpp>
#include <quan/min.hpp>
#include <quan/max.hpp>

/*
n.b there is a confusion here about top and bottom depending on text or graphics mode
 in text mode the bottom will have a bigger value than the top, and vice versa for graphics.
This box assumes graphics mode. For text mode the bottom is at actual top on display
 and vice versa. Unresolved! 
 A solution is probably a new box not using "top, bottom left right etc"
 box{
      vect min; // the smallest vales of x any y
      vect max; // the largest values of x and y
      assert ((max.x >= min.x) && ( max.y >= min.y));
 }
 This 
*/

namespace quan{namespace two_d{

    template <typename T>
    struct box{
        T left; // x_min
        T top; //  y_max,
        T right; // x_max
        T bottom; // y_min
        template <typename T1, typename T2, typename T3, typename T4>
        box(T1 const & left_, T2 const & top_, T3 const & right_, T4 const & bottom_)
        : left(quan::implicit_cast<T>(left_)),top(quan::implicit_cast<T>(top_)),
            right(quan::implicit_cast<T>(right_)), bottom(quan::implicit_cast<T>(bottom_)){}
        
        box() : left(T(0)),top(T(0)),right(T(0)),bottom(T(0)){}
        template <typename T1, typename T2>
        box (vect<T1> const & left_top, vect<T2> const & right_bot)
        : left(quan::implicit_cast<T>(left_top.x)),
            top(quan::implicit_cast<T>(left_top.y)),
            right(quan::implicit_cast<T>(right_bot.x)),
            bottom(quan::implicit_cast<T>(right_bot.y)){}

        template <typename T1>
        box& operator +=( vect<T1> const & in)
        {
            this->left += in.x;
            this->right += in.x;
            this->top += in.y;
            this->bottom += in.y; 
            return *this;
        }
        
        template <typename T1>
        box& operator -=( vect<T1> const & in)
        {
            this->left -= in.x;
            this->right -= in.x;
            this->top -= in.y;
            this->bottom -= in.y; 
            return *this;
        }
    };

    // probably could do a vector_view ala Fusion here
    template <typename T>
    inline
    vect<T> top_left(box<T> const & b)
    {
        return vect<T>(b.left,b.top);
    }

    template <typename T>
    inline
    vect<T> top_right(box<T> const & b)
    {
        return vect<T>(b.right,b.top);
    }

    template <typename T>
    inline
    vect<T> bottom_right(box<T> const & b)
    {
        return vect<T>(b.right,b.bottom);
    }

    template <typename T>
    inline
    vect<T> bottom_left(box<T> const & b)
    {
        return vect<T>(b.left,b.bottom);
    }

    template < typename T1, typename T2>
    inline
    box< typename quan::meta::binary_op<T1, quan::meta::plus, T2>::type >
    operator + ( box<T1> const & b, vect<T2> const & v)
    {
        box< 
            typename quan::meta::binary_op<T1, quan::meta::plus, T2>::type 
        > result = b;
        result += v;
        return result;
    }
    
    template < typename T1, typename T2>
    inline
    box< typename quan::meta::binary_op<T1, quan::meta::plus, T2>::type >
    operator - ( box<T1> const & b, vect<T2> const & v)
    {
        box< 
            typename quan::meta::binary_op<T1, quan::meta::plus, T2>::type 
        > result = b;
        result -= v;
        return result;
    }

    template < typename T1, typename T2>
    inline
    box< typename quan::meta::binary_op<T1, quan::meta::plus, T2>::type >
    max_box ( box<T1> const & lhs, box<T2> const & rhs)
    {
      typedef typename quan::meta::binary_op<T1, quan::meta::plus, T2>::type vtype;
      
      return  box<vtype> (
         quan::min( lhs.left,rhs.left),
         quan::max( lhs.top,rhs.top),
         quan::max( lhs.right,rhs.right),
         quan::min( lhs.bottom,rhs.bottom)
      );
    }

   template <typename T1, typename T2>
   inline
   bool point_in_box( vect<T1> const & pt,  box<T2> const & b)
   {
     return ( pt.x >= b.left ) 
         && ( pt.x <= b.right ) 
         && ( pt.y >= b.bottom ) 
         && ( pt.y <= b.top );
   }

   

}} //quan::two_d

#endif
