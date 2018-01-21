#ifndef QUAN_ANGLE_MATHEMATICAL_ANGLE_OUT_HPP_INCLUDED
#define QUAN_ANGLE_MATHEMATICAL_ANGLE_OUT_HPP_INCLUDED
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
    stream output for mathematic_angles (radians and steradians etc)
*/

#include <quan/angle/mathematic_angle.hpp>
#include <string>
#include <iostream>

namespace quan{

    template<typename Value_type>
    inline std::string  
    units_str(mathematic_angle<quan::meta::rational<1>,Value_type> const & )
    {
        return "rad";
    }

    template<typename Value_type>
    inline std::string  
    units_str(mathematic_angle<quan::meta::rational<-1>,Value_type> const & )
    {
        return "rad-1";
    }

    template<typename Value_type>
    inline std::string  
    units_str(mathematic_angle<quan::meta::rational<2>,Value_type> const & )
    {
        return "sr";
    }

    template<typename Value_type>
    inline std::string  
    units_str(mathematic_angle<quan::meta::rational<-2>,Value_type> const & )
    {
        return "sr-1";
    }

    template<
        typename CharType,
        typename Extent,
        typename Value_type
    >
    inline
    std::basic_ostream<CharType>& 
    operator <<  (std::basic_ostream<CharType>& os,
                    mathematic_angle<Extent,Value_type> const & r)
    {
         typedef std::ctype<CharType> ct;
         auto & facet = std::use_facet<ct>(std::locale());
         std::string str = units_str(r);
         std::basic_string<CharType> str1;
         for ( std::size_t i = 0; i < str.length();++i){
          str1 += facet.widen(str[i]);
         }
         os << r.numeric_value() << facet.widen(' ') << str1;
        return os;
     }
         
}//quan

namespace quan{namespace meta{

    namespace impl{
       template < 
           typename CharType,
           typename Extent,
           typename Value_type
       >
       struct binary_op_impl< 
           std::basic_ostream<CharType>,
           shift_left, 
           quan::mathematic_angle<Extent,Value_type>
       >{
           typedef std::basic_ostream<CharType>& result_type;
       };
    }

}}//quan::meta

#endif
