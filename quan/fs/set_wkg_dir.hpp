#ifndef QUAN_FS_SET_WKG_DIR_HPP_INCLUDED
#define QUAN_FS_SET_WKG_DIR_HPP_INCLUDED

//#include <cstdio>
#include <stdexcept>
#if defined (linux) || defined (__linux)
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
#include <unistd.h>
#else
/*
 try fullpath on windows?
*/
  #error "need to define set_wkg_dir for this platform"
#endif

namespace quan{ namespace fs{
   inline void set_wkg_dir(std::string const & dir)
   {
#if defined (linux) || defined (__linux)
     if( chdir(dir.c_str()) !=0){
       throw std::runtime_error(std::strerror(errno));
     }
#else
     #error "need to implement set_wkg_dir on this platform"
#endif
    }
}} //quan::fs


#endif // QUAN_FS_SET_WKG_DIR_HPP_INCLUDED
