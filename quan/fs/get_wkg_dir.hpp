#ifndef QUAN_FS_GET_WKG_DIR_HPP_INCLUDED
#define QUAN_FS_GET_WKG_DIR_HPP_INCLUDED

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
