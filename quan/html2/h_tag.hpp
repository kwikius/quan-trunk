#ifndef QUAN_HTML2_H_TAG_HPP_INCLUDED
#define QUAN_HTML2_H_TAG_HPP_INCLUDED

#include <quan/html2/body_content_list.hpp>
#include <quan/html2/tag_identifier.hpp>

namespace quan{ namespace html2{
   
   template <int N>
   struct h_tag : body_content_list{
   
      h_tag(){}
   
       std::ostream & output(std::ostream & os)const
       {
         os << "<h" << N;
         if ( m_tag_identifier){
            m_tag_identifier->output(os);
         }
         os << ">";
         for (auto p : m_content) { p->output(os);}
         os << "</h" << N << ">\n";
         return os;
       } 
   };

}}//quan::html

#endif

