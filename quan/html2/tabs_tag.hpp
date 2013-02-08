#ifndef QUAN_HTML2_TABS_TAG_HPP_INCLUDED
#define QUAN_HTML2_TABS_TAG_HPP_INCLUDED

#include <quan/html2/body_content.hpp>

namespace quan{ namespace html2{
   
   struct tabs_tag : body_content{

      tabs_tag(){}
       virtual std::ostream & output(std::ostream & os)const
       {
         return os << tabs;
       }  
       bool is_inline_element()const {return true;}  
   };

  

}}//quan::html

#endif

