#ifndef QUAN_HTML2_COMMENT_BODY_ELEMENT_HPP_INCLUDED
#define QUAN_HTML2_COMMENT_BODY_ELEMENT_HPP_INCLUDED

#include <quan/html2/body_content.hpp>

namespace quan { namespace html2{

   struct comment_element : body_content {
   
      comment_element(std::string * text_in) : m_pstr(text_in){}
      ~comment_element(){delete m_pstr;}
      std::ostream & output(std::ostream & os)const
      {
         os << "<!--";
         os << *m_pstr;
         os << "-->\n";
         return os;
      }
      std::string* m_pstr;
   };
}}


#endif // QUAN_HTML2_COMMENT_BODY_ELEMENT_HPP_INCLUDED
