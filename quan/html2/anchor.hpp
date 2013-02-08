#ifndef QUAN_HTML2_ANCHOR_HPP_INCLUDED
#define QUAN_HTML2_ANCHOR_HPP_INCLUDED

#include <quan/html2/body_content_list.hpp>

#include <string>

namespace quan{ namespace html2{
   
   struct anchor : body_content_list{

      anchor(std::string * in):m_pstr(in){}
      ~anchor(){delete m_pstr;}
      std::ostream & output(std::ostream & os)const
      {
         os <<  "<a name = \"" <<  *m_pstr << '"';
         if ( m_tag_identifier){
            this->m_tag_identifier->output(os);
         }
         os << ">";
         for  (auto elem : m_content) {elem->output(os);}

         os << "</a>\n";
         return os;
      }
      bool is_inline_element()const {return false;}
      
   private:
      std::string * m_pstr;
   };


}}//quan::html2


#endif

