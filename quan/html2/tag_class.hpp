#ifndef QUAN_HTML2_TAG_CLASS_HPP_INCLUDED
#define QUAN_HTML2_TAG_CLASS_HPP_INCLUDED
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

#include <quan/html2/tag_identifier.hpp>
#include <cassert>
#include <string>

namespace quan{ namespace html2{
 
   struct tag_class : tag_identifier{

      tag_class( std::string * in)
      : m_class(in){}
      ~tag_class(){delete m_class;};
      std::ostream & output(std::ostream & os)const
      {
         assert (m_class);
         return os << " class=\"" << *m_class << "\"";
      }
      private:
      std::string * m_class;
   };


}}//quan::html

#endif

