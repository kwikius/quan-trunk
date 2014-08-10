#ifndef QUAN_THREE_D_TOUCHES_HPP_INCLUDED
#define QUAN_THREE_D_TOUCHES_HPP_INCLUDED 

// Copyright Andrew Little 2006
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
