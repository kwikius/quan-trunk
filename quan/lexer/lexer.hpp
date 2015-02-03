#ifndef QLANG_LEXER_HPP_INCLUDED
#define QLANG_LEXER_HPP_INCLUDED
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
