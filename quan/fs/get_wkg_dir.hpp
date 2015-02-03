#ifndef QUAN_FS_GET_WKG_DIR_HPP_INCLUDED
#define QUAN_FS_GET_WKG_DIR_HPP_INCLUDED
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
#include <cstring>
#include <errno.h>

#if defined (linux) || defined (__linux)
#include <unistd.h>
#else
#error "need to implement get_wkg_dir on this platform"
#endif
namespace quan{ namespace fs{
  
  inline
  std::string get_wkg_dir()
  {
#if defined (linux) || defined (__linux)
      // keep making bigger buf till it fits
      std::size_t size = 256;
      for (;;){
         char* buf = new char[size ]; 
         errno =0;
         if (getcwd(buf,size)){
            std::string str = buf;
            delete [] buf;
            return str;
         }else {
            delete [] buf;
            if (errno == ERANGE){
               size += 64;
               continue;
            }else{
              throw std::runtime_error(std::strerror(errno));
            }
         }
      }
#endif
  }
   
}} //quan::fs

#endif // QUAN_FS_GET_WKG_DIR_HPP_INCLUDED
