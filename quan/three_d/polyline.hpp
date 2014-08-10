#ifndef QUAN_THREE_D_POLYLINE_HPP_INCLUDED
#define QUAN_THREE_D_POLYLINE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 

/*
    Dubious polyline. derivation from std::vector ok?   
    Currently Not same paradigm as e.g line where 
    PointType is param rather than value_type
    to do
*/

#include <vector>
#include <quan/three_d/vect.hpp>

namespace quan{namespace three_d{

    template <typename T>
    struct polyline : std::vector<vect<T> >{

     polyline(): std::vector<vect<T> >(){}
     };

}}}///quan::three_d


#endif
