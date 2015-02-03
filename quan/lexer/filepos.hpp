#ifndef QUAN_LEXER_FILE_POS_HPP_INCLUDED
#define QUAN_LEXER_FILE_POS_HPP_INCLUDED
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

#include <quan/lexer/sourcepos.hpp>
#include <quan/atomicstring.hpp>

namespace quan{ namespace lexer{

    struct filepos {
      filepos(){}
      filepos(quan::atomicstring<char> name, quan::lexer::source_pos const & pos)
      : filename{name},position{pos}{}

       quan::atomicstring<char> filename;
       quan::lexer::source_pos  position;

       std::string to_string() const
       {
           return  std::string{"\""} + filename.to_c_str() + std::string{"\" : " }+ position.to_string();
       }
    };
}}

#endif
