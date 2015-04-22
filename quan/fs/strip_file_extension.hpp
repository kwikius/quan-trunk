#ifndef QUAN_FS_STRIP_FILE_EXTENSION_HPP_INCLUDED
#define QUAN_FS_STRIP_FILE_EXTENSION_HPP_INCLUDED

#include <string>
#include <cstring>

namespace quan{ namespace fs{

   inline std::string strip_file_extension(std::string const & filename_in)
   {
      //assert ( (filename_in != "") && __LINE__);
      if (filename_in == ""){
            return "";
      }
      char* name = ::strdup(filename_in.c_str());
      auto pos = ::strrchr(name,'.');
      if ( pos != nullptr){
         *pos = '\0';
      } 
      std::string result = name;
      ::free(name);
      return result;
   }
}}

#endif // QUAN_FS_STRIP_FILE_EXTENSION_HPP_INCLUDED
