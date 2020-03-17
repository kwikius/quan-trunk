#ifndef QUAN_THREE_D_BEZIER4A_HPP_INCLUDED
#define QUAN_THREE_D_BEZIER4A_HPP_INCLUDED
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
    4 point bezier . 
    A True bezier should allow arbitrary number of points in.
    Use bezier4.at(Float const & p) to get the point at p (where  0 <= p <= 1).

*/

#include <quan/config.hpp>
#include <quan/where.hpp>
#include <quan/meta/binary_op.hpp>
#include <type_traits>
#include <stdexcept>

namespace quan{namespace three_d{

    template <
        typename PointType
    >
    struct bezier4a{
        typedef PointType point_type;
        point_type a,b,c,d;
      
        bezier4a(
            point_type const & a_in,
            point_type const & b_in,
            point_type const & c_in,
            point_type const & d_in
        )
        : a(a_in),b(b_in),c(c_in),d(d_in)
        {
        } 
       
        // t must be between between 0 and 1
        // if t==0 output == point a
        // if t == 1 output == point d
        // other values lie between.
        // throws out_of_range
        template<typename T>
        typename quan::where_<
           std::is_floating_point<T>,
           point_type
        >::type
        at( const T & t)const
        {
            typedef typename quan::meta::binary_op<
               typename point_type::value_type,quan::meta::divides,typename point_type::value_type
            >::type float_type1;

            typedef typename quan::meta::binary_op<
               float_type1,quan::meta::times,T
            >::type float_type;
           
            if ( (t < 0) || ( t > 1)){
                throw std::out_of_range("bezier at argument out of range");
            }
            float_type const one_m_t = 1 - t;
            float_type const one_m_t2 = one_m_t * one_m_t;
            float_type const one_m_t3 = one_m_t2 * one_m_t;
            float_type const t2 = t * t;
            float_type const t3 = t2 * t;
  
            point_type result 
                = one_m_t3 * a 
                + 3 * t * one_m_t2 * b
                + 3 * t2 * one_m_t * c
                + t3 * d;
            return result;
        }  
    };

}}//quan::three_d

#endif

