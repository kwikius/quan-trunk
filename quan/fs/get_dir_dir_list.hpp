#ifndef QUAN_FS_GET_DIR_DIR_LIST_HPP_INCLUDED
#define QUAN_FS_GET_DIR_DIR_LIST_HPP_INCLUDED

#include <quan/fs/detail/get_dir_list.hpp>

namespace quan { namespace fs{

   inline
   void get_dir_dir_list( std::vector<std::string> & v,std::string const & dir)
   {
      return detail::get_dir_list(v,dir,""," /b /a:d");
   }

}}//quan::fs

#endif

