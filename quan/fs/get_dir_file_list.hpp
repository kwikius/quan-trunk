#ifndef QUAN_FS_GET_DIR_FILE_LIST_HPP_INCLUDED
#define QUAN_FS_GET_DIR_FILE_LIST_HPP_INCLUDED
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

#include <quan/fs/detail/get_dir_list.hpp>

namespace quan { namespace fs{
// win32
//files not dirs
// "dir /b a:/-d"
//dirs not files
//dir /b a:d"
// get list of files in dir with ext

   inline
   void get_dir_file_list( std::vector<std::string> & v,std::string const & dir, std::string const & ext)
   {
      return detail::get_dir_list(v,dir,ext," /b /a:-d");
   }

}}//quan::fs

#endif

