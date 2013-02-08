#ifndef QUAN_HTML2_TABLE_TAG_HPP_INCLUDED
#define QUAN_HTML2_TABLE_TAG_HPP_INCLUDED

#include <quan/html2/tag_body_content_list.hpp>

namespace quan{ namespace html2{

   struct table_tag : tag_body_content_list{
      table_tag():tag_body_content_list{"table",true}{}
   };

}}//quan::html2


#endif

