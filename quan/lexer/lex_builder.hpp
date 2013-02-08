#ifndef QUAN_LEXER_LEXATIVE_INCLUDED
#define QUAN_LEXER_LEXATIVE_INCLUDED

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
