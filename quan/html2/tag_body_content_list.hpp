#ifndef QUAN_HTML2_TAG_BODY_CONTENT_LIST_HPP_INCLUDED
#define QUAN_HTML2_TAG_BODY_CONTENT_LIST_HPP_INCLUDED

#include <quan/html2/body_content_list.hpp>

namespace quan { namespace html2{

   struct tag_body_content_list : body_content_list{

     tag_body_content_list (std::string tag, bool want_ret = false) : m_tag_name{tag},m_want_ret{want_ret}{}
   
      std::ostream & output(std::ostream & os)const
      {
         os << "<" << m_tag_name;
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << ">";
         for (auto p : m_content) { p->output(os);}
         os <<  "</" << m_tag_name << ">";
         if (m_want_ret){
           os <<'\n';
         }
         return os;
      }
    private:
     std::string const m_tag_name;
     bool const m_want_ret;
     
   };
  
}}

#endif // QUAN_HTML2_TAG_BODY_CONTENT_LIST_HPP_INCLUDED
