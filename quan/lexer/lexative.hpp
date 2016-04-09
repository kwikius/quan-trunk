#ifndef QUAN_LEXER_FLEXER_HPP_INCLUDED
#define QUAN_LEXER_FLEXER_HPP_INCLUDED
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

//#include <quan/gc.hpp>

#include <iostream>
#include <string>
#include <stack>

#include <quan/lexer/lexeme.hpp>

namespace quan_lexer{
   struct scope;
}
namespace quan { namespace lexer{

   /*
     need to add capability to change input file
     optionally do includes etc
     also sort buffer which is set to 100 chars currently
     add start scope for reset
   */

   struct lexative{

      lexative (std::string const & src_filename,
                std::ostream * out,
                quan_lexer::scope* scope_in);
      // return 1 on success, 0 on fail, -1 on end of file
      int yylex( quan::lexer::lexeme& tok);

      std::string            m_filename;
      std::istream *         m_istream;
      std::ostream *         m_ostream;
      std::stack<quan_lexer::scope*>     m_function_stack;
      std::size_t            m_buf_length;
      source_pos             m_source_pos;
      std::stack<source_pos> m_source_pos_stack;
   };

}}
#endif // QUAN_LEXER_FLEXER_HPP_INCLUDED
