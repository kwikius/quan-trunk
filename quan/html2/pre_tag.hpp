#ifndef QUAN_HTML2_PRE_TAG_HPP_INCLUDED
#define QUAN_HTML2_PRE_TAG_HPP_INCLUDED

#include <quan/html2/body_content_list.hpp>
#include <quan/html2/tag_identifier.hpp>

namespace quan{ namespace html2{
 
   struct pre_tag : body_content_list{

      pre_tag(){}
      std::ostream & output(std::ostream & os)const
      {
         size_t n_tabs = tabs.clear();
         os << "<pre";
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << ">";
         for (auto p : m_content) { p->output(os);}
         os << "</pre>";
         tabs.set(n_tabs);
         return os;
      }
   };

}}//quan::html2

#endif

