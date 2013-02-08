#ifndef QUAN_HTML2_REL_URL_HPP_INCLUDED
#define QUAN_HTML2_REL_URL_HPP_INCLUDED

#include <quan/html2/url.hpp>
#include <quan/fs/get_rel_file_path.hpp>
#include <quan/html2/document.hpp>
#include <string>
#include <cassert>
#include <iosfwd>

namespace quan{namespace html2{

   struct rel_url : url{
      rel_url(std::string * in): url(in){}

      std::string get_string() const
      {
        auto doc = get_document();
        assert (doc);
        auto offset = doc->get_offset();
        assert (offset);
        return quan::fs::get_rel_file_path(*offset,url::get_string());
      }
      std::ostream & output(std::ostream & os)const
      {
        auto doc = get_document();
        assert (doc);
        auto offset = doc->get_offset();
        assert (offset);
        return os << '\''<< get_string() << '\'';
      }

   };

}}//quan::html

#endif

