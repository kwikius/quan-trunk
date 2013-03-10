#ifndef QUAN_DETAIL_PUT_RATIONAL_HPP_INCLUDED
#define QUAN_DETAIL_PUT_RATIONAL_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    output a rational in eg 1/2 style
    explicit + for powers
*/
#ifndef __AVR__
#include <iosfwd>
#else
#include <quan/avr/iostream_dummy.hpp>
#endif

namespace quan{namespace detail{

    template<typename CharType>
    inline 
    std::basic_ostream<CharType>& 
    put_rational_impl(std::basic_ostream<CharType>& os,
        int64_t n, 
        int64_t d)
    {
        if (!n) return os;
        if (d==1){
            if( n != 1){
                if (n > 1)
                    os << '+';
                os << n;
            }
            return os;
        }
        else {
            if (n > 0) os << '+';
            os << n << '/' << d;
        }
        return os;           
    }

    template<typename T,typename CharType>
    inline 
    std::basic_ostream<CharType>&  
    put_rational(std::basic_ostream<CharType>& os)
    {
        return put_rational_impl(
            os,
            T::numerator,
            T::denominator
        );
    }
    
}}//quan::detail

#endif
