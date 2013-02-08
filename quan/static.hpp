#ifndef  QUAN_STATIC_HPP_INCLUDED
#define  QUAN_STATIC_HPP_INCLUDED

#if (defined _MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif

// Copyright Andrew Little 2005
//
 

 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/fusion/static_value/out/static_value.hpp>

namespace quan{ 

    template <typename T, QUAN_INT32 N,QUAN_INT32 D=1>
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
