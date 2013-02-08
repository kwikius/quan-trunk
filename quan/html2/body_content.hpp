#ifndef QUAN_HTML2_BODY_CONTENT_HPP_INCLUDED
#define QUAN_HTML2_BODY_CONTENT_HPP_INCLUDED

#include <quan/html2/tabber.hpp>
#include <quan/html2/tag_identifier.hpp>
#include <iosfwd>
#include <cassert>

namespace quan{ namespace html2{

   struct document;

   struct body_content :  tabber{

      virtual ~body_content(){delete m_tag_identifier;}
      virtual std::ostream & output(std::ostream & os)const =0;
      void set_tag_id(tag_identifier * tg){ m_tag_identifier = tg;}

      // only overridden by body_tag
	   virtual document *
      get_document() const {
         assert(get_parent());
         return get_parent()->get_document();
      }

      virtual body_content* get_parent() const{return m_parent;}
      virtual void set_parent( body_content*  p) { m_parent = p; }

     private: // not used by bc_ref...
        body_content* m_parent;
    
      protected:
      body_content(): m_parent(nullptr),m_tag_identifier(nullptr){}
      tag_identifier* m_tag_identifier;
   
   };

}}//quan::html

#endif

