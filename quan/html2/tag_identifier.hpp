#ifndef QUAN_HTML2_TAG_IDENTIFIER_HPP_INCLUDED
#define QUAN_HTML2_TAG_IDENTIFIER_HPP_INCLUDED

#include <quan/html2/tabber.hpp>

namespace quan{ namespace html2{
   
   struct tag_identifier{
      virtual ~tag_identifier(){}
      virtual std::ostream & output(std::ostream & os)const=0;
   };

}}

#endif

