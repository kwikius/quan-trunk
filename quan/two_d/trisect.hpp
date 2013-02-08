
#ifndef QUAN_TWO_D_TRISECT_HPP_INCLUDED
#define QUAN_TWO_D_TRISECT_HPP_INCLUDED

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
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
