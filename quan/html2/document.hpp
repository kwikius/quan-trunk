#ifndef QUAN_HTML2_DOCUMENT_HPP_INCLUDED
#define QUAN_HTML2_DOCUMENT_HPP_INCLUDED
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
#include <string>
#include <map>
#include <list>
#include <typeinfo>

namespace quan{ namespace html2{

   struct head_tag;
   struct body_or_frameset;

   struct document : tabber {

      document(std::string * title_in, int version_number_in);
      
      ~document();
      std::ostream & output(std::ostream & os);

      void set_root(std::string * in){m_root= in;}
      void set_offset(std::string * in){m_offset = in;}
      void set_head(head_tag* head);// { m_head = head;}
      void set_body (body_or_frameset * body);// {m_body = body;}
      std::string* get_root() const {return m_root;}
      std::string* get_offset() const {return m_offset;}
      std::string* get_title() const {return m_title;}
      body_or_frameset* get_body()const { return m_body;}
      head_tag * get_head() const {return m_head;}
      int get_version_number()const{return m_version_number;}
     
   private:
      head_tag*                           m_head;
      body_or_frameset*                   m_body;
      std::string*                        m_root;
      std::string*                        m_offset;

      std::string*                        m_title;
      std::map<std::string,std::string>   m_resources;
      int                                 m_version_number;
   };

   struct opt_root_element{
      virtual ~opt_root_element(){}
   };

   struct repo_header : opt_root_element{
      std::string * name;
      std::string* repo_url;
   };

   struct root_elements {
      std::string * root;
      std::string * offset;
      std::list<opt_root_element*> * m_opt_root_elements;
   };



}}//quan::html


#endif

