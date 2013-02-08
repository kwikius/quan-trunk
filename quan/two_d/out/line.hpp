#ifndef QUAN_TWO_D_OUT_LINE_HPP_INCLUDED
#define QUAN_TWO_D_OUT_LINE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andy Little 2005
//
 
 
 

#include <quan/two_d/line.hpp>
#include <iostream>
namespace quan{ namespace two_d{

    template <typename T>
    std::ostream& operator <<( std::ostream& os, line<T> const & t)
    {
        os << t.from << "->" << t.to ;
        return os;
    }   
}}


#endif
