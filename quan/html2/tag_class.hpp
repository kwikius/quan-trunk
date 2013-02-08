#ifndef QUAN_HTML2_TAG_CLASS_HPP_INCLUDED
#define QUAN_HTML2_TAG_CLASS_HPP_INCLUDED

#include <quan/html2/tag_identifier.hpp>
#include <cassert>
#include <string>

namespace quan{ namespace html2{
 
   struct tag_class : tag_identifier{

      tag_class( std::string * in)
      : m_class(in){}
      ~tag_class(){delete m_class;};
      std::ostream & output(std::ostream & os)const
      {
         assert (m_class);
         return os << " class=\"" << *m_class << "\"";
      }
      private:
      std::string * m_class;
   };


}}//quan::html

#endif

