#ifndef QUAN_FS_GET_BASENAME_HPP_INCLUDED
#define QUAN_FS_GET_BASENAME_HPP_INCLUDED

#include <quan/config.hpp>

#if ((defined QUAN_OS_LINUX)  || (defined(__MINGW32__)))
#include <libgen.h>
#include <malloc.h>
#else
// hint for windows use splitpath?
#error "need to define get_basename for this platform"
#endif

#include <string>
#include <cstring>

namespace quan{ namespace fs{

   inline std::string get_basename(std::string const & path_in)
   {
#if (defined(QUAN_OS_LINUX)  || defined(__MINGW32__))
     // assert ( (path_in != "") && __LINE__);
     if (path_in == ""){
            return "";
     }
     char * path = (char*) ::malloc(path_in.length()+1);
     if (path == nullptr){
         return "";
     }else{
         strcpy(path,path_in.c_str());
     }

     // assert(path && __LINE__);

      char* basename = ::basename(path);

      std::string result = basename;
      free(path);
      return result;

#else
#error "need to define get_basename for this platform"
#endif
       } //fun

}}  // quan::fs

#endif // QUAN_FS_GET_BASENAME_HPP_INCLUDED
