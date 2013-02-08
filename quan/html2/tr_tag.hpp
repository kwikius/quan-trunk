#ifndef QUAN_HTML2_TR_TAG_HPP_INCLUDED
#define QUAN_HTML2_TR_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{
 
   struct tr_tag : tag_body_content_list{
      tr_tag(): tag_body_content_list{"tr",true}{}
   };

}}//quan::html

#endif

