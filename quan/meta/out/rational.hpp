#ifndef QUAN_META_OUT_RATIONAL1_HPP_INCLUDED
#define QUAN_META_OUT_RATIONAL1_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
/// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/meta/rational.hpp>
#include <iostream>

namespace quan{namespace meta{

        template <QUAN_INT32 N, QUAN_INT32 D>
        std::ostream & operator << (std::ostream& os, quan::meta::rational<N,D>)
        {
            os << "{" << N << '/' << D << '}';
            return os;
        }
}}//quan::meta


#endif
