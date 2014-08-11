#ifndef QUAN_ISSPACE_HPP_INCLUDED
#define QUAN_ISSPACE_HPP_INCLUDED
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

#include <ctype.h>
#include <type_traits>
#include <quan/where.hpp>

/*
   isspace.. functions template char type must be specified
*/

namespace quan{

  template< typename Char>
  inline
  typename quan::where_< std::is_same<Char,char>, bool>::type
  isspace( typename std::char_traits<Char>::int_type ch)
  {
    return std::isspace(ch) !=0;
  }
  
  template< typename Char>
  inline
  typename quan::where_< std::is_same<Char,wchar_t>, bool>::type
  isspace(wchar_t ch)
  {
    return std::iswspace(ch) !=0;
  }
}



#endif // QUAN_ISSPACE_HPP_INCLUDED
