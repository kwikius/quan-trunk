#ifndef QUAN_LEXER_FLEXER_HPP_INCLUDED
#define QUAN_LEXER_FLEXER_HPP_INCLUDED

#include <quan/gc.hpp>

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
