#ifndef  QUAN_STATIC_HPP_INCLUDED
#define  QUAN_STATIC_HPP_INCLUDED

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

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

#include <quan/fusion/static_value/static_value.hpp>

namespace quan{ 

    template <typename T, int64_t N,int64_t D=1>
    struct static_ :  quan::fusion::static_value<
        T,
        typename quan::meta::rational<N,D>::type 
    >{};
    
    template <typename T>
    struct static_zero : quan::fusion::static_value<
        T,
        quan::meta::rational<0,1> 
    >{};

  
    template <typename T>
    struct static_one : quan::fusion::static_value<
        T,
        quan::meta::rational<1,1> 
    >{};
    
    template <typename T>
    struct static_two : quan::fusion::static_value<
        T,
        quan::meta::rational<2,1>
    >{};
    
    template <typename T>
    struct static_three : quan::fusion::static_value<
        T,
        quan::meta::rational<3,1> 
    >{};

    template <typename T>
    struct static_four : quan::fusion::static_value<
        T,
        quan::meta::rational<4,1> 
    >{};

}//quan

#endif
