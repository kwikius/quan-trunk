#ifndef QUAN_THREE_D_LINE_HPP_INCLUDED
#define QUAN_THREE_D_LINE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
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
