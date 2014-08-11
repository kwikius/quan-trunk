#ifndef QUAN_LEXER_LEXATIVE_INCLUDED
#define QUAN_LEXER_LEXATIVE_INCLUDED
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
#include <iostream>

#include <quan/gc.hpp>

namespace quan_lexer{

  struct scope;

}

namespace quan { namespace lexer{

  struct lexative;

  struct lex_builder{
     // build from string representing filename
     lex_builder(std::string const & filename, std::ostream * out);
     // build from readymade istream.. filename is name for it
     lex_builder(std::istream * istream,std::string const & filename, std::ostream * out);
     int get_num_errors() const;
     // return null pointer if have errors
     lexative* get_lexative(std::string const & filename, std::ostream * out );
 
   private:
     void construct(
        std::istream & in, std::string const & filename,std::ostream * out
     );
     int m_num_errors;
     quan_lexer::scope* m_scope;
  };

}}

#endif // QUAN_LEXER_REFLEX_INCLUDED
