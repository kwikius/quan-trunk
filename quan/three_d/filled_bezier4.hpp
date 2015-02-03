#ifndef QUAN_GEOMETRY_THREE_D_BEZIER_HPP_INCLUDED
#define QUAN_GEOMETRY_THREE_D_BEZIER_HPP_INCLUDED
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
    4 point bezier . with fill
    True bezier should allow arbitrary number of points in.
    Use bezier4.at(Float const & p) to get the point at p (where  0 <= p <= 1).
    Note: the member points vect and fillup functions should probably be removed.
    at function can be used by client directly

*/

#include <quan/three_d/line.hpp>
#include <vector>

namespace quan{ namespace three_d{

template <typename PointType>
    struct filled_bezier4{
        typedef typename PointType::value_type value_type;
        typedef typename PointType point_type;
        point_type a,b,c,d;
        typedef std::vector<PointType> points_vect;
        points_vect points;
        value_type const inc;
        filled_bezier4() {}
        filled_bezier4& operator =( filled_bezier4 const & in)
        {
            a = in.a; b=in.b; c = in.c;d = in.d;
            this->points.clear();
            for (typename points_vect::iterator i = points.begin(); i != points.end(); ++i){
                this->points.push_back(*i);
            }
            return *this;
            return *this;
        }
        filled_bezier4(
            point_type const & a_in,
            point_type const & b_in,
            point_type const & c_in,
            point_type const & d_in,
            value_type inc_in = value_type(1)
        )
        : a(a_in),b(b_in),c(c_in),d(d_in), inc(inc_in)
        {
        } 
        filled_bezier4(
            line<point_type> const & a_in,
            line<point_type> const & b_in,
             value_type inc_in = value_type(1)
        ): a (a_in.from),b(a_in.to),c(b_in.from),d(b_in.to), inc(inc_in)
        {
        }
        // t must be between between 0 and 1
        // may add range exception
        point_type at( const double & t)const
        {
            double one_m_t = 1 - t;
            double one_m_t2 = one_m_t * one_m_t;
            double one_m_t3 = one_m_t2 * one_m_t;
            double t2 = t * t;
            double t3 = t2 * t;
            point_type aa(a.x,a.y,a.z);
            point_type bb(b.x,b.y,b.z);
            point_type cc(c.x,c.y,c.z);
            point_type dd(d.x,d.y,d.z);
            point_type temp 
                    = one_m_t3 * aa 
                    + 3 * t * one_m_t2 * bb
                    + 3 * t2 * one_m_t * cc
                    + t3 * dd;
            point_type result(temp.x,temp.y,temp.z);
            return result;
        }
        /*
            fill with n points
        */
        void fillup( int numpoints)
        {
            value_type  t = 1. / numpoints;
            point_type cur = this->at(t);
            value_type tt = value_type(0);
            while ( tt <= 1 )
            {
                cur = this->at(tt);
                points.push_back(cur);
                tt += t;  
            }
        }
    };


}}//quan::three_d

#endif

