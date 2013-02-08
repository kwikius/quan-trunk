#ifndef QUAN_LEXER_LOOKAHEAD_HPP_INCLUDED
#define QUAN_LEXER_LOOKAHEAD_HPP_INCLUDED

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
