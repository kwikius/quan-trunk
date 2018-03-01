#ifndef QUAN_HTML2_REL_URL_HPP_INCLUDED
#define QUAN_HTML2_REL_URL_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

#include <quan/html2/url.hpp>
#include <quan/fs/get_rel_file_path.hpp>
#include <quan/html2/document.hpp>
#include <string>
#include <cassert>
#include <iosfwd>

namespace quan{namespace html2{

   std::string global_get_offset();

   struct rel_url : url{
      rel_url(std::string * in): url(in){}

      std::string get_string() const
      {
        std::string offset = global_get_offset();
        assert (offset != "");
        return quan::fs::get_rel_file_path(offset,url::get_string());
      }
      std::ostream & output(std::ostream & os)const
      {
        return os << '\''<< get_string() << '\'';
      }

   };

}}//quan::html

#endif

