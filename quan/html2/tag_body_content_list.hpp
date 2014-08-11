#ifndef QUAN_HTML2_TAG_BODY_CONTENT_LIST_HPP_INCLUDED
#define QUAN_HTML2_TAG_BODY_CONTENT_LIST_HPP_INCLUDED
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

namespace quan { namespace html2{

   struct tag_body_content_list : body_content_list{

     tag_body_content_list (std::string tag, bool want_ret = false) : m_tag_name{tag},m_want_ret{want_ret}{}
   
      std::ostream & output(std::ostream & os)const
      {
         os << "<" << m_tag_name;
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << ">";
         for (auto p : m_content) { p->output(os);}
         os <<  "</" << m_tag_name << ">";
         if (m_want_ret){
           os <<'\n';
         }
         return os;
      }
    private:
     std::string const m_tag_name;
     bool const m_want_ret;
     
   };
  
}}

#endif // QUAN_HTML2_TAG_BODY_CONTENT_LIST_HPP_INCLUDED
