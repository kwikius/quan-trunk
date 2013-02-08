#ifndef QUAN_WORDPROC_TABS_HPP_INCLUDED
#define QUAN_WORDPROC_TABS_HPP_INCLUDED

#include <iostream>

namespace quan{ namespace wordproc{
    
    template <int N>
    struct tab_object{

        size_t n_tabs;
        tab_object(std::size_t n =0): n_tabs(n){}
        tab_object& operator ++()
        {
            if (n_tabs < 30){
                ++n_tabs;
            }
            return *this;
        }
        
        tab_object& operator --()
        {
            if ( n_tabs > 0){
                --n_tabs;
            }
            return *this;
        }
        size_t clear()
        {
            size_t temp = n_tabs;
            n_tabs= 0;
            return temp;
        }
        void set( size_t n)
        {
            n_tabs = n;
        }
        
    };
    template <int N>
    inline
    std::ostream & 
    operator << (
        std::ostream& os, 
        tab_object<N> const & t
    )
    {
        
        for (size_t i = 0 ; i < t.n_tabs * N ;++i){
            os << ' ';
        }
        return os;
    }

}}//quan::wordproc

#endif
