#ifndef QUAN_FS_GET_BASENAME_HPP_INCLUDED
#define QUAN_FS_GET_BASENAME_HPP_INCLUDED

#if defined (linux) || defined (__linux)
#include <libgen.h>
#else
#error "need to define get_basename for this platform"
#endif
#include <string>
#include <cstring>

namespace quan{ namespace fs{

   inline std::string get_basename(std::string const & path_in)
   {
      assert ( (path_in != "") && __LINE__);
      char* path = strdup(path_in.c_str());
      assert(path && __LINE__);
#if defined (linux) || defined (__linux)
      char* basename = ::basename(path);
#else
#error "need to define get_basename for this platform"
#endif
      std::string result = basename;
      free(path);
      return result;
   }
}}

#endif // QUAN_FS_GET_BASENAME_HPP_INCLUDED
