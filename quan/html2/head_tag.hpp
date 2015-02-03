#ifndef QUAN_HTML2_HEAD_TAG_HPP_INCLUDED
#define QUAN_HTML2_HEAD_TAG_HPP_INCLUDED
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

#include <quan/html2/head_content.hpp>
#include <list>

namespace quan{ namespace html2{

   struct document;

   struct head_tag : tabber {

      std::list<head_content*> m_content;

      std::ostream & output(std::ostream & os)const{

         os << "<head>\n";
         for (auto p : m_content){
            p->output(os);
         }
         os <<  "</head>\n";
         return os;
      }
      head_tag & push_back( head_content * d_in)
      {
         m_content.push_back(d_in);
         return *this;
      }

      head_tag(): m_document{nullptr}{}
    

      document * get_document() const { return m_document;}

       ~head_tag()
      {
          for (auto p : m_content){
            delete p;
         }
       }
    private :
       document * m_document;
      friend class document;
      void set_document(document * doc) 
      {
         m_document = doc;
         for (auto p : m_content){
           p->set_document(doc);
         }
      }
   };

}}//quan::html

#endif

