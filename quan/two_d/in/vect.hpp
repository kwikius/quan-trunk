#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_TWO_D_IN_VECT_HPP_INCLUDED
#define  QUAN_TWO_D_IN_VECT_HPP_INCLUDED
 
// Copyright Andy Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.
/*
    vect output
*/

#include <quan/two_d/vect.hpp>
#include <iostream>


namespace quan{namespace two_d{

    template <typename CharType,typename T>
    inline
    std::basic_istream<CharType> &
    operator >> ( std::basic_istream<CharType>& is, vect<T> & v_out)
    {
        std::ios_base::fmtflags flags = is.flags();
        CharType lb=0,comma=0,rb =0;
        vect<T> tv;
        is 
         >> std::skipws >> lb 
         >> std::skipws >> tv.x 
         >> std::skipws >> comma
         >> std::skipws >> tv.y
         >> std::skipws >> rb;
        is.flags(flags);
        if ( (lb != '[') || (comma != ',' ) || (rb != ']')){
          is.clear(std::ios_base::badbit);
        }
        if (is.bad()){
         return is;
        }
        v_out = tv;
        return is;
    }

}}//quan::two_d


#endif


