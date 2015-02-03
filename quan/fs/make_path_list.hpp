#ifndef QUAN_FS_MAKE_PATH_LIST_HPP_INCLUDED
#define QUAN_FS_MAKE_PATH_LIST_HPP_INCLUDED
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
