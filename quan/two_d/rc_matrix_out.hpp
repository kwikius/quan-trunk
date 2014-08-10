#ifndef QUAN_TWO_D_TRANSFORM_MATRIX_OUT_HPP_INCLUDED
#define QUAN_TWO_D_TRANSFORM_MATRIX_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 

/*
    homogeneous transform matrix out
*/

#include <quan/two_d/rc_matrix.hpp>

namespace quan{namespace two_d{

    template<typename Q>
    std::ostream& operator << (std::ostream& os, rc_matrix<Q> const & m)
    {
        os << "|" << m.at<0,0>() << ", " << m.at<0,1>() << ", " << m.at<0,2>() << "|\n|";
        os << m.at<1,0>() << ", " << m.at<1,1>() << ", " << m.at<1,2>() << "|\n|"; 
        os << m.at<2,0>() << ", " << m.at<2,1>() << ", " << m.at<2,2>() << "|";
        return os;
    }

}}//quan::two_d

#endif
