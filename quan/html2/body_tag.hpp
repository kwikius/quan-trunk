#ifndef QUAN_HTML2_BODY_TAG_HPP_INCLUDED
#define QUAN_HTML2_BODY_TAG_HPP_INCLUDED
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

#include <quan/html2/body_or_frameset.hpp>

#include <list>
#include <iosfwd>
#include <quan/html2/body_content_list.hpp>

namespace quan{ namespace html2{
   
   struct body_tag : body_or_frameset, body_content_list{

	  body_tag(){}

     ~body_tag(){}
      body_content* get_parent() const{ return 0;}

      void set_parent(body_content * p) const
      { assert(p == nullptr);}
      
      document* get_document() const {
        
         return body_or_frameset::get_document();
      }

      std::ostream & output(std::ostream & os)const
      {
         os <<  "<body";
         if (m_tag_identifier){
            m_tag_identifier->output(os);
         }
         os << ">\n";
            for (auto p : m_content) {p->output(os);}
         os << "</body>\n";
         return os;
      }
   };


}}//quan::html

#endif

