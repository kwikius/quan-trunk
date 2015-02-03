#ifndef QUAN_WORDPROC_TABS_HPP_INCLUDED
#define QUAN_WORDPROC_TABS_HPP_INCLUDED
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
