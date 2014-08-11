#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_TWO_D_IN_VECT_HPP_INCLUDED
#define  QUAN_TWO_D_IN_VECT_HPP_INCLUDED
 
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


