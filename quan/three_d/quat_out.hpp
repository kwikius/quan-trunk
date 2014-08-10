#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_THREE_D_QUAT_OUT_HPP_INCLUDED
#define  QUAN_THREE_D_QUAT_OUT_HPP_INCLUDED
 
// Copyright Andy Little 2005
// Copyright Janek Kozicki 2006
//
 
 
 

/*
    quaternion output
*/

#include "quan/three_d/quat.hpp"
#include <iostream>

namespace quan{namespace three_d{

    template <typename Q1,  typename Char_type>
    inline
    std::basic_ostream<Char_type>& 
    operator << ( std::basic_ostream<Char_type>& os_inout, quat<Q1> const& v_in)
    {
        os_inout << "[" << v_in.w << ", " << v_in.x << ", " << v_in.y << ", " << v_in.z <<"]";
        return os_inout;
    }

}}//quan::three_d


#endif


