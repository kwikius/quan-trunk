#ifndef QUAN_LEXER_LOOKAHEAD_HPP_INCLUDED
#define QUAN_LEXER_LOOKAHEAD_HPP_INCLUDED
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
#include <list>

namespace quan{namespace lexer{

   template <typename Lex>
   struct lookahead{
      typedef typename Lex::token_type token_type;
      typedef typename std::list<token_type*> list_type;
      typedef lookahead type;
   private:
      Lex* m_lexer;
      list_type m_list;
      void append_token();
      token_type * m_curr_tok;
   public:
      lookahead(Lex* lex_in);
      ~lookahead();
      quan::lexer::source_pos get_position()const;
      int get();
      int peek(int n);
      std::ostream& out(){ return m_lexer->out();}
      token_type * get_curr_tok();
      token_type * clone_curr_tok();
      token_type * peek_tok(int n);
      Lex* get_lexer() const;

   };

}}

#endif
