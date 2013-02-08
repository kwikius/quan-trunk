#ifndef QUAN_HTML2_TITLE_TAG_HPP_INCLUDED
#define QUAN_HTML2_TITLE_TAG_HPP_INCLUDED

#include <quan/html2/head_content.hpp>
#include <string>

namespace quan{namespace html2{

   struct title_tag : head_content{

      title_tag(std::string const & name) : m_name(name){};
      std::ostream & output(std::ostream & os)const
      {
         os << "<title>\n";
 
         os << tabs << m_name << '\n';

         os <<  "</title>\n";
         return os;
      }
      std::string m_name;
   };

}}//quan::html2

#endif

