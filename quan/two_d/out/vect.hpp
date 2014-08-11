#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_TWO_D_OUT_VECT_HPP_INCLUDED
#define  QUAN_TWO_D_OUT_VECT_HPP_INCLUDED
 
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


