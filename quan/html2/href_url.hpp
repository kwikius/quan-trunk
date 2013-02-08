#ifndef QUAN_HTML2_HREF_URL_HPP_INCLUDED
#define QUAN_HTML2_HREF_URL_HPP_INCLUDED

#include <quan/html2/url.hpp>
#include <string>
#include <cassert>
#include <iosfwd>

namespace quan{namespace html2{

   struct href_url : url{
      href_url(std::string * in): url(in){}
      std::ostream & output(std::ostream & os)const
      {
        return os << '\''<< this->get_string() << '\'';
      }
   };

}}//quan::html

#endif

