#ifndef QUAN_STD_STRING_UNQUOTE_HPP_INCLUDED
#define QUAN_STD_STRING_UNQUOTE_HPP_INCLUDED

#include <string>

namespace quan{

   inline
   std::string 
   unquote( std::string const & str, char quote_char = '"')
   {
      if ((str.size() >=  2) && (str.front() == quote_char) && (str.back() == quote_char)){
         return str.substr(1,str.length()-1);
      }else{
         return str;
      }
   }

} //quan

#endif // QUAN_STD_STRING_UNQUOTE_HPP_INCLUDED
