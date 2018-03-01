#ifndef QUAN_HTML2_IMG_TAG_HPP_INCLUDED
#define QUAN_HTML2_IMG_TAG_HPP_INCLUDED
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
#include <quan/html2/tag_identifier.hpp>
#include <quan/html2/url.hpp>
#include <string>
/*
  img {src{"quan_matters/dummy/entities/img1.jpg"}}
*/
namespace quan{ namespace html2{

   struct img_attributes{
      img_attributes(): m_url{nullptr},m_alt{""},m_width{-1},m_height{-1}{}
      url* m_url;
      std::string m_alt;
      int m_width;
      int m_height;
      ~img_attributes(){ if (m_url != nullptr) delete m_url;}
   };

   struct img_tag : body_content{
     
      img_tag( )
      : m_url(nullptr),m_width(-1),m_height(-1){}

      ~img_tag(){ if (m_url != nullptr) delete m_url;}

      std::ostream & output(std::ostream & os)const
      {
//         auto doc = this->get_document();
//         assert(doc);
//        // m_url->set_document(doc);
         os << "<img" ;
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << " src = ";
         if ( m_url != nullptr){
            m_url->output(os) ;
         }
         if ( m_width !=-1){
            os << " width =" << m_width ;
         }
         if ( m_height !=-1){
            os << " height = " << m_height ;
         }
         if (m_alt != ""){
            os << " alt = '" << m_alt << "'";
         }
         os << ">\n";
         return os;
      }
      bool is_inline_element()const {return true;}
      
    //  private:
      url * m_url;
      std::string m_alt;
      int m_width;
      int m_height;
     

   };

}}//quan::html

#endif

