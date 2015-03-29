#ifndef QUAN_FS_GET_ABS_FILE_PATH_HPP_INCLUDED
#define QUAN_FS_GET_ABS_FILE_PATH_HPP_INCLUDED
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
     if( ::realpath(str.c_str(),buf) !=0){
       std::string ret = buf;
       delete [] buf;
       return ret;
     }
     else{
      delete [] buf;
      //return "";
      throw std::runtime_error(std::strerror(errno));
     }
#else
 #error "need to define get_abs_file_path for this platform"
#endif
  }
}} 

#endif // QUAN_FS_GET_ABS_FILE_PATH_HPP_INCLUDED
