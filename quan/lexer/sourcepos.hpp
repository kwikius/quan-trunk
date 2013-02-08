#ifndef QUAN_LEXER_SOURCE_POS_HPP_INCLUDED1
#define QUAN_LEXER_SOURCE_POS_HPP_INCLUDED1

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

