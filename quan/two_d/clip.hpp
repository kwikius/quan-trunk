#ifndef QUAN_TWO_D_CLIP_HPP_INCLUDED
#define QUAN_TWO_D_CLIP_HPP_INCLUDED
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
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    clip a line to a box.
    The trisect part could definitely be optimised
*/
#include <quan/two_d/box.hpp>
#include <quan/two_d/line.hpp>
#include <quan/two_d/trisect.hpp>
#include <quan/fixed_quantity/operations/compare.hpp>
//#include <cassert>

namespace quan{namespace two_d{

// add checks that left < right and top > bottom etc
    template <typename T>
    struct clip{
        typedef typename quan::meta::binary_op<
            T, quan::meta::divides,T
        >::type slope_type;
    private:
        box<T> m_box;
        trisect<T> m_trisect;
        T  m_epsilon;
    public:
        clip (box<T> const & box_in, T const & epsilon_in = T(0))
        :m_box(box_in),m_trisect(box_in), m_epsilon(epsilon_in){}
        clip(): m_trisect(box<T>(0,0,0,0)){}
        void set_epsilon( T const & eps)
        {
            m_epsilon = eps;
        }
        void set_clipbox( box<T> const & in)
        {
            m_box = in;
            m_trisect.set_clip_box(in);
        }
        // true if draw false if all outside
        typedef std::pair<bool,line<vect<T> > > result_type;
        result_type operator()(line<vect<T> > const & in)const
        {
            // assume all the line is inside the box by default
            result_type result(true,in);
            line<vect<int> > tris = m_trisect(in);
            if(all_inside(tris)){
                return result;
            }
            if (simple_outside(tris)){
                result.first = false;
              //  assert( false && __LINE__);
                return result;
            }
            // check horizontal case
            if ( quan::compare(in.from.y,in.to.y, m_epsilon) == 0){
                if( tris.from.x == -1){
                    result.second.from.x = m_box.left;
                }else if( tris.from.x == 1){
                    result.second.from.x = m_box.right;
                }
                if( tris.to.x == -1){
                    result.second.to.x = m_box.left;
                }else if( tris.to.x == 1){
                    result.second.to.x = m_box.right;
                }
                return result;  
            } else
            //check vertical case
            if (  quan::compare(in.from.x,in.to.x,m_epsilon) == 0){
                if( tris.from.y == -1){
                    result.second.from.y = m_box.bottom;
                }else if( tris.from.y == 1){
                    result.second.from.y = m_box.top;
                }
                if( tris.to.y == -1){
                    result.second.to.y = m_box.bottom;
                }else if( tris.to.y == 1){
                    result.second.to.y = m_box.top;
                }
                return result;
            }
           
            if( tris.from.y != 0){
                T yy = (tris.from.y ==1) ? m_box.top : m_box.bottom;
                result.second.from.x 
                += (result.second.to.x - result.second.from.x) 
                * (yy - result.second.from.y)
                /(result.second.to.y - result.second.from.y);
                result.second.from.y = yy; 
                tris = m_trisect(result.second);  
            }
            if(tris.from.x != 0){
                T xx = (tris.from.x == -1) ? m_box.left : m_box.right;
                result.second.from.y 
                += (result.second.to.y - result.second.from.y)
                * (xx - result.second.from.x)
                /(result.second.to.x - result.second.from.x);
                result.second.from.x = xx;
            }
            if(tris.to.y != 0){
                T yy = (tris.to.y ==1) ? m_box.top : m_box.bottom;
                result.second.to.x 
                = result.second.from.x + (result.second.to.x -result.second.from.x)
                * (yy - result.second.from.y)
                / (result.second.to.y - result.second.from.y);
                result.second.to.y = yy;
                tris = m_trisect(result.second);
            }
            if( tris.to.x !=0){
                T xx = (tris.to.x == -1) ? m_box.left : m_box.right;
                result.second.to.y 
                = result.second.from.y + (result.second.to.y - result.second.from.y)
                *(xx - result.second.from.x)
                /(result.second.to.x - result.second.from.x);
                result.second.to.x=xx;
             }
             tris = m_trisect(result.second);
            if (simple_outside(tris)){
               //  assert( false && __LINE__);
                result.first = false;
                
            }
            if ( (compare(result.second.from.x, result.second.to.x,m_epsilon)==0)
                 && (compare(result.second.from.y, result.second.to.y,m_epsilon)==0)){
                result.first = false;
              
            }
            return result;
        }


        bool simple_outside(line<vect<int> > const & in)const
        {
            bool result 
            = ((in.from.x * in.to.x) == 1) || ((in.from.y * in.to.y) == 1);
            return result;
        }

        bool all_inside(line<vect<int> > const & in)const
        {
            bool result 
            = (in.from.x ==0) && (in.to.x == 0)
            && (in.from.y == 0) && (in.to.y == 0);
            return result;
        }
    };

}}//quan::two_d

#endif
