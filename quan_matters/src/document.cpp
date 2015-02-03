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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#include <quan/html2/document.hpp>
#include <quan/html2/head_tag.hpp>
#include <quan/html2/body_or_frameset.hpp>
#include <cassert>

void quan::html2::document::set_head(head_tag* head)
{
  m_head = head;
  m_head->set_document(this);
}
void quan::html2::document::set_body (
  body_or_frameset * body
) 
{ 
 m_body = body;
  m_body->set_document(this);
}

quan::html2::document::document(std::string * title_in, int version_number_in)
:m_head{nullptr}, m_body(nullptr), m_root{nullptr}, m_offset{nullptr}, 
   m_title{title_in}, m_version_number{version_number_in}
{ }

quan::html2::document::~document()
{
   delete m_head;
   delete m_body;
   delete m_root;
   delete m_offset;
   delete m_title;
}

std::ostream & quan::html2::document::output(std::ostream & os)
{
   os << "<html>\n";

      os << "<!-- root   = " << *this->get_root() << " -->\n";
      os << "<!-- offset = " << *this->get_offset() << " -->\n";
      os << "<title>\n";
      os << *m_title << '\n';
      os << "</title>\n";
     
      assert(m_head != nullptr);
      m_head->output(os);
      assert(m_body != nullptr);
      m_body->output(os);

   os << "</html>\n";
   return os;
}

