#ifndef QUAN_HTML2_RET_TAG_HPP_INCLUDED
#define QUAN_HTML2_RET_TAG_HPP_INCLUDED

#include <quan/html2/body_content.hpp>

namespace quan{ namespace html2{
   
   struct ret_tag : body_content{

    ret_tag() {}
     
       virtual std::ostream & output(std::ostream & os)const
       {
         return os << "\n" ;
       }  
       bool is_inline_element()const {return false;}  
   };

}}//quan::html

#endif

