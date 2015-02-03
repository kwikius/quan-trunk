#ifndef QUAN_HTML2_H_TAG_HPP_INCLUDED
#define QUAN_HTML2_H_TAG_HPP_INCLUDED
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
   
   template <int N>
   struct h_tag : body_content_list{
   
      h_tag(){}
   
       std::ostream & output(std::ostream & os)const
       {
         os << "<h" << N;
         if ( m_tag_identifier){
            m_tag_identifier->output(os);
         }
         os << ">";
         for (auto p : m_content) { p->output(os);}
         os << "</h" << N << ">\n";
         return os;
       } 
   };

}}//quan::html

#endif

