#ifndef QUAN_HTML2_CSS_LINK_HPP_INCLUDED
#define QUAN_HTML2_CSS_LINK_HPP_INCLUDED
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
#include <quan/html2/head_content.hpp>
#include <cassert>

namespace quan{namespace html2{

   struct css_link : head_content{
      css_link(url* url_in): m_url(url_in)
      { assert(m_url != nullptr);};

      ~css_link(){delete m_url;}
//      void set_document( document * doc) {
//       // m_url->set_document(doc);
//       // head_content::set_document(doc);
//      }
      std::ostream & output(std::ostream & os)const
      {
         os <<  "<link\n";
         os << "rel=\'stylesheet\'\n";
         os << "href="; m_url->output(os); os << '\n'; 
         os << "type=\'text/css\'\n";
         os  << ">\n";
         return os;
      }
      url* m_url;
   };
   
}}//quan::html

#endif

