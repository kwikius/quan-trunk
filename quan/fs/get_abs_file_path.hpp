#ifndef QUAN_FS_GET_ABS_FILE_PATH_HPP_INCLUDED
#define QUAN_FS_GET_ABS_FILE_PATH_HPP_INCLUDED

#include <stdexcept>

#include <limits.h>
#include <errno.h>
#if defined (linux) || defined (__linux)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#else
/*
 try fullpath on windows?
*/
  #error "need to define get_abs_file_path for this platform"
#endif

namespace quan{ namespace fs{

  inline std::string get_abs_file_path(std::string const & str)
  {
#if defined (linux) || defined (__linux)
     char* buf = new char[PATH_MAX];
     errno = 0;
     if( realpath(str.c_str(),buf) !=0){
       std::string ret = buf;
       delete [] buf;
       return ret;
     }
     else{
       throw std::runtime_error(std::strerror(errno));
     }
#else
 #error "need to define get_abs_file_path for this platform"
#endif
  }
}} 

#endif // QUAN_FS_GET_ABS_FILE_PATH_HPP_INCLUDED
