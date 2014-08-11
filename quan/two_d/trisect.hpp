
#ifndef QUAN_TWO_D_TRISECT_HPP_INCLUDED
#define QUAN_TWO_D_TRISECT_HPP_INCLUDED

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
    clipping utility.
    trisect returns a line representing wheteher an actual lines
    start and end points are inside or outside the clipping box.
    1 means the element is above or to the right
    -1 means the element is below or to the left
    0 means between the two relevant the clipping box extents
*/

#include <quan/two_d/vect.hpp>
#include <quan/two_d/box.hpp>
#include <quan/two_d/line.hpp>

namespace quan{namespace two_d{

    template <typename T>
    struct trisect{
        private:
        box<T> clip_box;
        public:
        trisect( box<T> const& clip_box_in)
        : clip_box(clip_box_in){}
        void set_clip_box( box<T> const& clip_box_in)
        {
            clip_box = clip_box_in;
        }
        line<vect<int> > 
        operator()( line<vect<T> >const & line_in)const
        {
            line<vect<int> > result;
        // vect<int> result;

            if (line_in.from.x < clip_box.left){
                result.from.x = -1;
            } else if (line_in.from.x > clip_box.right){
                result.from.x = 1;
            } else {
                result.from.x=0;
            }

            if (line_in.to.x < clip_box.left){
                result.to.x = -1;
            } else if (line_in.to.x > clip_box.right){
                result.to.x = 1;
            } else {
                result.to.x=0;
            }

            if (line_in.from.y < clip_box.bottom) {
                result.from.y = -1;
            } else if (line_in.from.y > clip_box.top){
                result.from.y = 1;
            } else {
                result.from.y=0;
            }

            if (line_in.to.y < clip_box.bottom) {
                result.to.y = -1;
            } else if (line_in.to.y > clip_box.top){
                result.to.y = 1;
            } else {
                result.to.y=0;
            }
            return result;
        }
       // vect<int> operator()(vect<T> const & in) const;
       
    };
}}// quan::two_d

#endif
