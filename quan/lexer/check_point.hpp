#ifndef QUAN_LEXER_CHECK_POINT_HPP_INCLUDED
#define QUAN_LEXER_CHECK_POINT_HPP_INCLUDED
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
