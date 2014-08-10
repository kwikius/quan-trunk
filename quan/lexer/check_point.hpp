#ifndef QUAN_LEXER_CHECK_POINT_HPP_INCLUDED
#define QUAN_LEXER_CHECK_POINT_HPP_INCLUDED


#include <string>
#include <quan/lexer/source_pos.hpp>

namespace quan{ namespace lexer{

   struct check_point{
      std::string info;
      source_pos pos;
      std::string id;

      check_point(
         std::string const & info_in,
         source_pos const & pos_in,
         std::string const & id_in) // file id e.g name
      : info(info_in),pos(pos_in),id(id_in){}
   };

}}

#endif
