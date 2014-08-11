#ifndef QUAN_THREE_D_TOUCHES_HPP_INCLUDED
#define QUAN_THREE_D_TOUCHES_HPP_INCLUDED 

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

namespace quan{namespace three_d{

template <typename T> 
struct touches{
    vect<T> tolerance;
    touches() : tolerance(T(0),T(0),T(0)){}
    template <typename T1>
    touches(vect<T1> const & in)
    : tolerance(in){}
    template< typename T1, typename T2>
        bool operator()(
        vect<T1> const & a,
        vect<T2> const & b 
    ) 
    { 
        for (int i = 0; i < 3; ++i){ 
            using std::abs; 
            if ( abs( a[i] - b[i]) > abs(tolerance[i]) ){ 
                    return false; 
            } 
        } 
        return true; 
    }
};

}}//quan::three_d

#endif
