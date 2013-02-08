#ifndef QUAN_HTML2_TD_TAG_HPP_INCLUDED
#define QUAN_HTML2_TD_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{
 
   struct td_tag : tag_body_content_list{
      td_tag():tag_body_content_list{"td"}{}
   };

}}//quan::html

#endif

