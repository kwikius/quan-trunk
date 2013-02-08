#ifndef QUAN_HTML2_HDR_URL_HPP_INCLUDED
#define QUAN_HTML2_HDR_URL_HPP_INCLUDED

#include <quan/html2/rel_url.hpp>


namespace quan{namespace html2{

   struct hdr_url : rel_url{
      hdr_url(std::string * in): rel_url(in){}
   };

}}//quan::html

#endif

