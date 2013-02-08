#ifndef QUAN_LEXER_FILE_POS_HPP_INCLUDED
#define QUAN_LEXER_FILE_POS_HPP_INCLUDED

#include <quan/lexer/sourcepos.hpp>
#include <quan/atomicstring.hpp>

namespace quan{ namespace lexer{

    struct filepos {
      filepos(){}
      filepos(quan::atomicstring<char> name, quan::lexer::source_pos const & pos)
      : filename{name},position{pos}{}

       quan::atomicstring<char> filename;
       quan::lexer::source_pos  position;

       std::string to_string() const
       {
           return  std::string{"\""} + filename.to_c_str() + std::string{"\" : " }+ position.to_string();
       }
    };
}}

#endif
