#ifndef QUAN_HTML2_BODY_CONTENT_HPP_INCLUDED
#define QUAN_HTML2_BODY_CONTENT_HPP_INCLUDED
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

#include <quan/html2/tabber.hpp>
#include <quan/html2/tag_identifier.hpp>
#include <iosfwd>
#include <cassert>

namespace quan{ namespace html2{

   struct document;

   struct body_content :  tabber{

      virtual ~body_content(){delete m_tag_identifier;}
      virtual std::ostream & output(std::ostream & os)const =0;
      void set_tag_id(tag_identifier * tg){ m_tag_identifier = tg;}

      // only overridden by body_tag
	   virtual document *
      get_document() const {
         assert(get_parent());
         return get_parent()->get_document();
      }

      virtual body_content* get_parent() const{return m_parent;}
      virtual void set_parent( body_content*  p) { m_parent = p; }

     private: // not used by bc_ref...
        body_content* m_parent;
    
      protected:
      body_content(): m_parent(nullptr),m_tag_identifier(nullptr){}
      tag_identifier* m_tag_identifier;
   
   };

}}//quan::html

#endif

