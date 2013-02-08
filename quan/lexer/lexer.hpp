#ifndef QLANG_LEXER_HPP_INCLUDED
#define QLANG_LEXER_HPP_INCLUDED

#ifndef __FLEX_LEXER_H
#include <FlexLexer.h>
#endif

#include <quan/lexer/token.hpp>
#include <quan/lexer/filepos.hpp>

namespace quan{ namespace lexer{

  
   struct lex : yyFlexLexer{

      typedef quan::lexer::token token_type;
      typedef quan::lexer::filepos filepos_type;
   
      lex( quan::atomicstring<char> filename ,std::istream* arg_yyin, std::ostream* arg_yyout )
      : yyFlexLexer(arg_yyin,arg_yyout),filepos{filename,quan::lexer::source_pos{1,1}}
      {}
      
      filepos_type filepos;

   };
}}

#endif
