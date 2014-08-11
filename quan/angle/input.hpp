#ifndef QUAN_ANGLE_INTPUT_HPP_INCLUDED2911030401
#define QUAN_ANGLE_INTPUT_HPP_INCLUDED2911030401
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

/*
    Simple input routine for ct-quantity.
    sets badbit on invalid input

   After C++ 3rd ed p 621. Input of a fixed_quantity
   basically compares the format of the units in operator <<

   modified to use angle model conce
*/

#include <sstream>
#include <locale>
#include <quan/out/angle.hpp>
#include <quan/where.hpp>
#include <quan/std/string/convert.hpp>

 namespace quan{

      template <typename CharType,typename Angle>
      typename quan::where_<
        quan::meta::is_angle<Angle>,
        std::basic_istream<CharType>&
       >::type
       operator >> (
        std::basic_istream<CharType>& is,
        Angle& angle
    )
    {
        typename Angle::value_type numeric_value;
        is >> numeric_value;
        
//        typedef std::ctype<CharType> ct;
//        auto & facet = std::use_facet<ct>(std::locale());
//        std::string units_str_c = units_str(angle);
//        std::basic_string<CharType> units_str_w;
//        for ( auto i = 0U ; i < units_str_c.length();++i){
//          units_str_w += facet.widen(units_str_c[i]);
//        }
        std::basic_string<CharType> units_str_cmp 
           = quan::convert<CharType>(units_str(angle));
        std::basic_string<CharType> units_str_in;
        is >> units_str_in;
        if (units_str_in != units_str_cmp){
            is.clear(std::ios_base::badbit);
            return is;
        }
        if (is){
            angle = Angle{numeric_value};
        }
        return is;
        
    }

}//quan
#endif
