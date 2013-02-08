#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_TWO_D_OUT_VECT_HPP_INCLUDED
#define  QUAN_TWO_D_OUT_VECT_HPP_INCLUDED
 
// Copyright Andy Little 2005

/*
    vect output
*/

#include <quan/two_d/vect.hpp>
#include <iostream>

namespace quan{namespace two_d{

    template <typename Q1,  typename CharType>
    inline
    std::basic_ostream<CharType>& 
    operator << ( std::basic_ostream<CharType>& os_inout, vect<Q1> const& v_in)
    {
        os_inout << "[" << v_in.x << ", " << v_in.y << "]";
        return os_inout;
    }

}}//quan::two_d


#endif


