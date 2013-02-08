#ifndef QUAN_TWO_D_CIRCLE_HPP_INCLUDED
#define QUAN_TWO_D_CIRCLE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 

/*
    circle by center-position and radius
*/

#include <quan/two_d/vect.hpp>
namespace quan{namespace two_d{

    template<typename Value_type>
    struct circle{
        circle(
            vect<Value_type>const & position_in, 
            Value_type const & radius_in
        )
        : position(position_in),radius(radius_in){}
        vect<Value_type> position;
        Value_type radius;
    };

}}//quan::two_d


#endif
