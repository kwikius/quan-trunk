#ifndef QUAN_HTML2_PRE_TAG_HPP_INCLUDED
#define QUAN_HTML2_PRE_TAG_HPP_INCLUDED
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
#include <quan/html2/tag_identifier.hpp>

namespace quan{ namespace html2{
 
   struct pre_tag : body_content_list{

      pre_tag(){}
      std::ostream & output(std::ostream & os)const
      {
         size_t n_tabs = tabs.clear();
         os << "<pre";
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << ">";
         for (auto p : m_content) { p->output(os);}
         os << "</pre>";
         tabs.set(n_tabs);
         return os;
      }
   };

}}//quan::html2

#endif

