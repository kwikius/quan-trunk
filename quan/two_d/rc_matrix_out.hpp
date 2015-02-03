#ifndef QUAN_TWO_D_TRANSFORM_MATRIX_OUT_HPP_INCLUDED
#define QUAN_TWO_D_TRANSFORM_MATRIX_OUT_HPP_INCLUDED
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
