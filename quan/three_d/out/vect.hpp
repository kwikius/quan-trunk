

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif
#ifndef  QUAN_THREE_D_VECT_OUT_HPP_INCLUDED1
#define  QUAN_THREE_D_VECT_OUT_HPP_INCLUDED1
 
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


