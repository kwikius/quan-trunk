#ifndef QUAN_HTML2_OL_TAG_HPP_INCLUDED
#define QUAN_HTML2_OL_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{

   struct ol_tag : tag_body_content_list{
     ol_tag() : tag_body_content_list{"ol",true}{}
   };

}}//quan::html

#endif

