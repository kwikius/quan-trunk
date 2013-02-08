#ifndef QUAN_HTML2_CSS_LINK_HPP_INCLUDED
#define QUAN_HTML2_CSS_LINK_HPP_INCLUDED

#include <quan/html2/url.hpp>
#include <quan/html2/head_content.hpp>
#include <cassert>

namespace quan{namespace html2{

   struct css_link : head_content{
      css_link(url* url_in): m_url(url_in)
      { assert(m_url != nullptr);};

      ~css_link(){delete m_url;}
      void set_document( document * doc) {
        m_url->set_document(doc);
        head_content::set_document(doc);
      }
      std::ostream & output(std::ostream & os)const
      {
         os <<  "<link\n";
         os << "rel=\'stylesheet\'\n";
         os << "href="; m_url->output(os); os << '\n'; 
         os << "type=\'text/css\'\n";
         os  << ">\n";
         return os;
      }
      url* m_url;
   };
   
}}//quan::html

#endif

