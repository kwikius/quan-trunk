#ifndef QUAN_HTML2_LI_TAG_HPP_INCLUDED
#define QUAN_HTML2_LI_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{

   struct li_tag : tag_body_content_list{
     li_tag() : tag_body_content_list{"li",true}{}
   };

}}//quan::html

#endif

