#ifndef QUAN_STRING_CONVERT_HPP
#define  QUAN_STRING_CONVERT_HPP
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

#include <string>
#include <iostream>
#include <type_traits>
#include <locale>
#include <quan/where.hpp>
#include <quan/meta/bool.hpp>

namespace quan{

     template <typename CharTo, typename CharFrom>
     inline
     typename quan::where_<
        quan::meta::bool_< (sizeof(CharTo) > sizeof(CharFrom))>,
        std::basic_string<CharTo>
     >::type
      convert(std::basic_string<CharFrom> const & in)
     {
        typedef std::ctype<CharTo> ct;
        auto & facet = std::use_facet<ct>(std::locale());
        std::basic_string<CharTo> result;
        for ( auto i = 0U ; i < in.length();++i){
          result += facet.widen(in[i]);
        }
        return result;
     }

     template <typename CharTo, typename CharFrom>
     inline
     typename quan::where_<
         quan::meta::bool_< (sizeof(CharTo) == sizeof(CharFrom))>,
         std::basic_string<CharFrom> const &
     >::type
      convert(std::basic_string<CharFrom> const & in)
     {
        return in;
     }

     template <typename CharTo, typename CharFrom>
     inline
     typename quan::where_<
         quan::meta::bool_< (sizeof(CharTo) < sizeof(CharFrom))>,
         std::basic_string<CharTo>
     >::type
      convert(std::basic_string<CharFrom> const & in)
     {
        typedef std::ctype<CharFrom> ct;
        auto & facet = std::use_facet<ct>(std::locale());
        std::basic_string<CharTo> result;
        for ( auto i = 0U ; i < in.length();++i){
          result += facet.narrow(in[i],'#');
        }
        return result;
     }


}

#endif
