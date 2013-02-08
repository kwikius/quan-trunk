#ifndef QUAN_HTML2_P_TAG_HPP_INCLUDED
#define QUAN_HTML2_P_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{namespace html2{

   struct p_tag : tag_body_content_list{
      p_tag() : tag_body_content_list{"p",true}{}
   };

}}//quan::html2
#endif

