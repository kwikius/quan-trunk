#ifndef QUAN_HTML2_UL_TAG_HPP_INCLUDED
#define QUAN_HTML2_UL_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{

   struct ul_tag : tag_body_content_list{
     ul_tag() : tag_body_content_list{"ul",true}{}
   };

}}//quan::html

#endif

