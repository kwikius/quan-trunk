#ifndef QUAN_ANGLE_FRACTION_OF_REVOLUTION_OUT_HPP_INCLUDED
#define QUAN_ANGLE_FRACTION_OF_REVOLUTION_OUT_HPP_INCLUDED
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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    stream output for fraction_of_revolution
    degrees, minutes, seconds, 
    and reciprocals of those
*/

#include <quan/angle/fraction_of_revolution.hpp>
#include <string>
#include <ostream>

namespace quan{

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<360>,
            Value_type
        > const& )
    {
        return "deg";
    }

     template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<36000>,
            Value_type
        > const& )
    {
        return "cdeg";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<-1>,
            quan::meta::rational<1,360>,
            Value_type
        > const& ang)
    {
        return "deg-1";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<360 * 60>,
            Value_type
        > const& ang)
    {
        return "min";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<-1>,
            quan::meta::rational<1,360 * 60>,
            Value_type
        > const& ang)
    {
        return "min-1";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<360 * 60 *60>,
            Value_type
        > const& ang)
    {
        return "sec";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<-1>,
            quan::meta::rational<1,360 * 60 *60>,
            Value_type
        > const& ang)
    {
        return "sec-1";
    }

       template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<1>,
            Value_type
        > const& )
    {
        return "rev";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<-1>,
            quan::meta::rational<1>,
            Value_type
        > const& ang)
    {
        return "rev-1";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<256>,
            Value_type
        > const& ang)
    {
        return "brad8";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<3600000000>,
            Value_type
        > const& ang)
    {
        return "<deg/10^7>";
    }

    template<typename Value_type>
    inline
    std::string 
    units_str(fraction_of_revolution<
            quan::meta::rational<1>,
            quan::meta::rational<65536>,
            Value_type
        > const& ang)
    {
        return "brad16";
    }



    template<
        typename CharType,
        typename Extent,
        typename ReciprocalFraction,
        typename Value_type>
    inline
    std::basic_ostream<CharType> & 
    operator << (
        std::basic_ostream<CharType>& os,
        fraction_of_revolution<
            Extent,
            ReciprocalFraction,
            Value_type
        > const& ang)
    {
         typedef std::ctype<CharType> ct;
         auto & facet = std::use_facet<ct>(std::locale());
         std::string str = units_str(ang);
         std::basic_string<CharType> str1;
         for ( std::size_t i = 0; i < str.length();++i){
          str1 += facet.widen(str[i]);
         }
         os << ang.numeric_value() << facet.widen(' ') << str1;
         return os;
    }

}//quan


namespace quan{namespace meta{

   namespace impl{
       template < 
           typename Extent,
           typename ReciprocalFraction,
           typename Value_type
       >
       struct binary_op_impl< 
           std::ostream,
           shift_left, 
           quan::fraction_of_revolution<
               Extent, 
               ReciprocalFraction,
               Value_type
           >
       >{
           typedef std::ostream& result_type;
       };
   }

}}//quan::meta

#endif
