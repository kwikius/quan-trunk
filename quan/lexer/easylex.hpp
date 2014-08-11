#ifndef QUAN_LEXER_EASYLEX_HPP_INCLUDED
#define QUAN_LEXER_EASYLEX_HPP_INCLUDED
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

#include <quan/gc.hpp>

#include <iosfwd>
#include <vector>
#include <map>

#include <quan/atomicstring.hpp>
#include <quan/lexer/lex_builder.hpp>
#include <quan/lexer/lexative.hpp>
#include <quan/lexer/lexeme.hpp>

namespace quan{ namespace lexer{

    struct easylex{
      protected:
      virtual ~easylex();
     // src from c string
      easylex(const char* const lexer_src_in, std::string text, std::ostream * out);
      // src from file
      easylex(std::string const & filename,std::ostream * out);
      public:
      // lexer to new data file .. 
      void set_lexer( std::string const & data_filename, std::ostream * out);
      // fill next lexeme
      int yylex();
      quan::atomicstring<char>      get_source_filename()const;
      quan::lexer::source_pos       get_source_pos() const ;

      typedef void (*token_function_ptr_type)( quan::lexer::lexeme const &);
      static void doNull(quan::lexer::lexeme const & lexeme);
      void set_token(const char* name, int id, token_function_ptr_type pf_ = doNull);
      void set_char_tokens(const char* char_tokens, token_function_ptr_type pf_= doNull);
    private:
      quan::lexer::lex_builder* m_builder;
      quan::lexer::lexative* m_lexer ;
      quan::lexer::lexeme m_lexeme;
      typedef std::pair<int,token_function_ptr_type> map_elem;
      std::map<quan::atomicstring<char>, map_elem> m_token_map;

    };

}}//quan::lexer



#endif // QUAN_LEXER_EASYLEX_HPP_INCLUDED
