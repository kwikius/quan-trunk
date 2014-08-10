

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_THREE_D_VECT_OUT_HPP_INCLUDED1
#define  QUAN_THREE_D_VECT_OUT_HPP_INCLUDED1
 
// Copyright Andy Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    vect output
*/

#include <quan/three_d/vect.hpp>
//#include <quan/out/minmaxpair.hpp>
#include <iostream>

namespace quan{namespace three_d{

    template <typename Q1,  typename Char_type>
    inline
    std::basic_ostream<Char_type>& 
    operator << ( std::basic_ostream<Char_type>& os_inout, vect<Q1> const& v_in)
    {
        os_inout << "[" << v_in.x << ", " << v_in.y << ", " << v_in.z <<"]";
        return os_inout;
    }

}}//quan::three_d


#endif


