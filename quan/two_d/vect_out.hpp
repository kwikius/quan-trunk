#ifndef QUAN_TWO_D_VECT_OUT_HPP_INCLUDED
#define QUAN_TWO_D_VECT_OUT_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
 
// Copyright Andy Little 2005
//
 
 
 

/*
    point output
*/

#include <quan/two_d/vect.hpp>
#include <iostream>

namespace quan{namespace two_d{

    template <typename Q1,  typename Char_type>
    inline
    std::basic_ostream<Char_type>& 
    operator << ( std::basic_ostream<Char_type>& os_inout, vect<Q1> const& v_in)
    {
        os_inout << '[' << v_in.x << ',' << v_in.y << ']';
        return os_inout;
    }

}}//quan::two_d


#endif


