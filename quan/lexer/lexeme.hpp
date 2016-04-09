#ifndef QUAN_LEXER_LEXEME_HPP_INCLUDED
#define QUAN_LEXER_LEXEME_HPP_INCLUDED
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
#include <quan/atomicstring.hpp>
#include <quan/lexer/sourcepos.hpp>

namespace quan {namespace lexer{

 // the returned lexeme
  struct lexeme{
      lexeme(): m_source_pos(0,0){}
      quan::atomicstring<char>       m_token_name; 
      std::string                    m_lexeme; // the source data
      quan::atomicstring<char>       m_filename;
      quan::lexer::source_pos        m_source_pos;

  };

}}

#endif // QUAN_LEXER_LEXEME_HPP_INCLUDED
