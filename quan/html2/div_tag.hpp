#ifndef QUAN_HTML2_DIV_TAG_HPP_INCLUDED
#define QUAN_HTML2_DIV_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{
 
   struct div_tag : tag_body_content_list{
      div_tag() : tag_body_content_list{"div"}{}
   };

}}//quan::html2

#endif

