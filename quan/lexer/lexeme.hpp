#ifndef QUAN_LEXER_LEXEME_HPP_INCLUDED
#define QUAN_LEXER_LEXEME_HPP_INCLUDED

#include <string>
#include <quan/atomicstring.hpp>
#include <quan/lexer/source_pos.hpp>

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
