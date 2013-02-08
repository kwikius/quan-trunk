#ifndef QUAN_HTML2_TAG_ID_HPP_INCLUDED
#define QUAN_HTML2_TAG_ID_HPP_INCLUDED

#include <quan/html2/tag_identifier.hpp>
#include <cassert>
#include <string>

namespace quan{ namespace html2{

   struct tag_id : tag_identifier{

      tag_id( std::string * in) : m_id(in){}
      ~tag_id(){delete m_id;}
      std::ostream & output(std::ostream & os)const
      {
         assert (m_id);
         return os << " id=\"" << *m_id << "\"";
      }
      private:
      std::string * m_id;
   };
   
}}//quan::html

#endif
 
