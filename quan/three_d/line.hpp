#ifndef QUAN_THREE_D_LINE_HPP_INCLUDED
#define QUAN_THREE_D_LINE_HPP_INCLUDED
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
    simple 3d line
*/

namespace quan{ namespace three_d{

    template <typename PointType>
    struct line{
        typedef PointType point_type;
        line(point_type const & p1_in ,point_type const & p2_in)
        : from(p1_in),to(p2_in){}
        template<typename T1>
        line(line<T1> const & in)
        : p1(in.p1),p2(in.p2){}
        point_type from, to;
    };

}}//quan::three_d




#endif
