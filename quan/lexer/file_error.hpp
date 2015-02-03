#ifndef QUAN_LEXER_FILE_ERROR_HPP_INCLUDED
#define QUAN_LEXER_FILE_ERROR_HPP_INCLUDED
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

#include <stdexcept>
//#include <quan/lexer/istream.hpp>
#include <string>

namespace quan{ namespace lexer{

  template<typename CharType> struct istream;

// will need to sort wide stream
   template <typename CharType>
   struct file_error : std::runtime_error{
       typedef quan::lexer::istream<CharType> istream_type;
      file_error(
         istream_type const & fin,
         std::string const & text_in
      )
      :  std::runtime_error(text_in),
         pos(fin.get_source_pos()),
         file_name(fin.get_stream_id()),
         last_check_point(fin.get_check_point())
      {}
      ~file_error() throw() {}
      quan::lexer::source_pos pos;
      std::string file_name;
      quan::lexer::check_point last_check_point;

   };

}}

#endif

