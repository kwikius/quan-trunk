#ifndef QUAN_UTILITY_INTPUT_HPP_INCLUDED2911030401
#define QUAN_UTILITY_INTPUT_HPP_INCLUDED2911030401
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
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

/*
    Simple input routine for ct-quantity.
    sets badbit on invalid input

   After C++ 3rd ed p 621. Input of a fixed_quantity
   basically compares the format of the units in operator <<
*/

#include <sstream>
#include <locale>
#include <quan/fixed_quantity/io/output.hpp>

 namespace quan{

    template<
        typename StaticUnit,
        typename Value_type,
        typename CharType
    >
    inline std::basic_istream<CharType>& 
    operator >> (
        std::basic_istream<CharType>& is,
        fixed_quantity<StaticUnit,Value_type>& pq 
    )
    {
        // use default numeric input format
        if (is.bad())return is;
        Value_type v;
        is >> v;

        if (!is || is.fail() || is.bad() ){
            return is;
        // add check on stream state here?
        }
        
        // remove spaces, must be at least 1
        // multiple space should be unnecessary
        // check no_skipwhitespace?
        // IOW should always be 1
        int space_count = 0;
        CharType ch=0;
        while (is.get(ch)){
            if (ch  == is.widen(' ')){
                space_count++;
                continue;
            }
            else {
                is.putback(ch);
                break;
            }
        }
        if (!space_count){
            is.clear(std::ios_base::badbit);
            return is;
        }

        // use output string for the type to compare units
        std::basic_ostringstream<CharType> ost;
        ost << units(fixed_quantity<StaticUnit,Value_type>());
        std::basic_string<CharType> str = ost.str();

        // read in characters of unit to same number
        // and comparing with those in unit we already have
        typename std::basic_string<CharType>::const_iterator iter = str.begin();
        while (iter != str.end()){
            is.get(ch);
            if (ch != *iter){
                is.clear(std::ios_base::badbit);
                break;
            }
            ++iter;
        }
        if (is){
            pq 
            = fixed_quantity<
                StaticUnit,
                Value_type
            >(v);
        }
        return is; 
    } 
}//quan
#endif
