#ifndef QUAN_HTML2_BODY_TAG_HPP_INCLUDED
#define QUAN_HTML2_BODY_TAG_HPP_INCLUDED

#include <quan/html2/body_or_frameset.hpp>

#include <list>
#include <iosfwd>
#include <quan/html2/body_content_list.hpp>

namespace quan{ namespace html2{
   
   struct body_tag : body_or_frameset, body_content_list{

	  body_tag(){}

     ~body_tag(){}
      body_content* get_parent() const{ return 0;}

      void set_parent(body_content * p) const
      { assert(p == nullptr);}
      
      document* get_document() const {
        
         return body_or_frameset::get_document();
      }

      std::ostream & output(std::ostream & os)const
      {
         os <<  "<body";
         if (m_tag_identifier){
            m_tag_identifier->output(os);
         }
         os << ">\n";
            for (auto p : m_content) {p->output(os);}
         os << "</body>\n";
         return os;
      }
   };


}}//quan::html

#endif

