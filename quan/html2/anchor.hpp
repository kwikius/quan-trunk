#ifndef QUAN_HTML2_ANCHOR_HPP_INCLUDED
#define QUAN_HTML2_ANCHOR_HPP_INCLUDED
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

#include <quan/html2/body_content_list.hpp>

#include <string>

namespace quan{ namespace html2{
   
   struct anchor : body_content_list{

      anchor(std::string * in):m_pstr(in){}
      ~anchor(){delete m_pstr;}
      std::ostream & output(std::ostream & os)const
      {
         os <<  "<a name = \"" <<  *m_pstr << '"';
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << ">";
         for  (auto elem : m_content) {elem->output(os);}

         os << "</a>\n";
         return os;
      }
      bool is_inline_element()const {return false;}
      
   private:
      std::string * m_pstr;
   };


}}//quan::html2


#endif

