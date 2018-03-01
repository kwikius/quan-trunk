#ifndef QUAN_HTML2_A_TAG_HPP_INCLUDED
#define QUAN_HTML2_A_TAG_HPP_INCLUDED
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

#include <quan/html2/url.hpp>
#include <quan/html2/body_content_list.hpp>
#include <quan/html2/simple_text.hpp>
#include <quan/html2/tag_identifier.hpp>
#include <string>

namespace quan{ namespace html2{
   
   struct a_tag : body_content_list{

      a_tag(url * url_in )
      :m_url(url_in) {}
 
      std::ostream & output(std::ostream & os)const
      {
         os << "<a";
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << " href = " ;
        // auto doc = this->get_document();
        // assert(doc);
        // m_url->set_document(doc);
         m_url->output(os);
         os  << ">";
          if ( m_content.size()==0){
            auto pstr = new std::string(m_url->get_string());
            quan::html2::simple_text text(pstr)  ;
            text.output(os);
          }else{
            for ( auto p : m_content) {p->output(os);}
          }
         os << "</a>";
         return os;
      } 
      bool is_inline_element()const {return true;}
      private:
      url* m_url;

      
   };

}}//quan::html2

#endif

