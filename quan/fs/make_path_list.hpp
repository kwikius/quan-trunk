#ifndef QUAN_FS_MAKE_PATH_LIST_HPP_INCLUDED
#define QUAN_FS_MAKE_PATH_LIST_HPP_INCLUDED

#include <list>
#include <string>
#include <sstream>

//string is a filepath

namespace quan{ namespace fs{

   template <typename CharType>
   inline
   std::list<std::basic_string<CharType> >
   make_path_list( std::basic_string<CharType> const & path, CharType sep = '/')
   {
      std::basic_stringstream<CharType> s; 
      s << path; 

      std::list<std::basic_string<CharType> > tokens; 
      while (! s.eof() ){ 
         std::basic_string<CharType> str; 
         std::getline(s,str,sep); 
         tokens.push_back(str); 
      } 
      return tokens;
   }

}}//quan::fs

#endif
