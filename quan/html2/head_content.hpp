#ifndef QUAN_HTML2_HEAD_CONTENT_HPP_INCLUDED
#define QUAN_HTML2_HEAD_CONTENT_HPP_INCLUDED

#include <quan/html2/tabber.hpp>

#include <iosfwd>

namespace quan{ namespace html2{

   struct document ;
   struct head_content : tabber{

      head_content() : m_document{nullptr}{}
      virtual ~head_content(){}
      virtual std::ostream & output(std::ostream & os)const =0;
      virtual  void set_document( document * doc) { m_document = doc;}
      document* get_document() const { return m_document;}
      private:
      document * m_document;
   };

}}//quan::html

#endif

