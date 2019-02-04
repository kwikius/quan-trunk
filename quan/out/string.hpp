#ifndef QUAN_OUT_STRING_HPP_INCLUDED
#define QUAN_OUT_STRING_HPP_INCLUDED

#include <iostream>
#include <quan/string.hpp>

namespace quan{

   inline std::ostream & operator << ( std::ostream & out, quan::string const & str)
   {
      return out << str.get();
   }

}//quan

#endif // QUAN_OUT_STRING_HPP_INCLUDED
