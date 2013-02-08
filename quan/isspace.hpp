#ifndef QUAN_ISSPACE_HPP_INCLUDED
#define QUAN_ISSPACE_HPP_INCLUDED

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
