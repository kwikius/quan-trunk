#ifndef QUAN_LEXER_SOURCE_POS_HPP_INCLUDED1
#define QUAN_LEXER_SOURCE_POS_HPP_INCLUDED1
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

#include <iostream>
#include <sstream>

namespace quan{ namespace lexer{

   struct source_pos{
      typedef std::streamoff off_type;
      source_pos():row(-1),column(-1){}
      source_pos(off_type row_in,off_type col_in)
      :row(row_in),column(col_in){}
      off_type row;
      off_type column;

      std::string to_string() const
      {
         std::ostringstream ost;
         ost << "Ln " << row << ", Col " << column;
         return ost.str();
      }
   };

   inline std::ostream & 
   operator << (std::ostream & os,source_pos const & pos)
   {
      return os << "Ln " << pos.row 
      << ", Col " << pos.column;
   }

   

}}//quan::lexer

#endif

