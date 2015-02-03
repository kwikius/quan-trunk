#ifndef QUAN_HTML2_BODY_CONTENT_LIST_HPP_INCLUDED
#define QUAN_HTML2_BODY_CONTENT_LIST_HPP_INCLUDED
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

#include <quan/html2/body_content.hpp>
#include <list>
#include <cassert>

namespace quan{ namespace html2{

   struct body_content_list : body_content{

      body_content_list(){}
      body_content_list& push_back( body_content * d_in)
      {
         assert(d_in != nullptr);
         d_in->set_parent(this);
         m_content.push_back(d_in);
         return *this;
      }

      std::list<body_content*> & get_list() {return m_content;}

//      virtual std::ostream & output(std::ostream & os)const
//      {
//         for  (auto elem : m_content) {elem->output(os);}
//         return os;
//      }

      ~body_content_list(){ for( auto p : m_content){delete p;} }
    protected:
      std::list<body_content*> m_content;
      
   };

}}//quan::html

#endif

