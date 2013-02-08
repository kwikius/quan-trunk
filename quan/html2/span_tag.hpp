#ifndef QUAN_HTML2_SPAN_TAG_HPP_INCLUDED
#define QUAN_HTML2_SPAN_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{
 
   struct span_tag : tag_body_content_list{
      span_tag():tag_body_content_list{"span"}{}
   };

}}//quan::html2

#endif

