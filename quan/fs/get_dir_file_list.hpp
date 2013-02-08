#ifndef QUAN_FS_GET_DIR_FILE_LIST_HPP_INCLUDED
#define QUAN_FS_GET_DIR_FILE_LIST_HPP_INCLUDED

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

