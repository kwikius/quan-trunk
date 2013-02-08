#ifndef QUAN_FS_DETAIL_GET_DIR_LIST_HPP_INCLUDED
#define QUAN_FS_DETAIL_GET_DIR_LIST_HPP_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#if defined (_MSC_VER)
#include <direct.h>
#elif defined (linux) || defined (__linux)
#include <unistd.h>
#endif
#include <stdexcept>
#include <cassert>


namespace quan { namespace fs{namespace detail{
   inline
   void get_dir_list( 
      std::vector<std::string> & v,
      std::string const & dir, 
      std::string const & ext,
      std::string const & switch_)
   {
#if defined (_MSC_VER)
     // get current dir
      char buffer[_MAX_PATH];
      if(_getcwd( buffer, _MAX_PATH ) == NULL){
         throw std::runtime_error("cannot get current dir");
      }
      // change to input dir
      if (chdir( dir.c_str()) != NULL)
      {
         throw std::runtime_error("cannot get dir \"" + dir + "\"");
      }
      // make a tmp file to put dir names in
      const char* tmp = tmpnam(NULL);

      if(tmp ==NULL){
         throw std::runtime_error("couldnt get temp file name");
      }
      // call dir to put in tmp file
      std::string sys_string = "\"dir " + ext + " "  + switch_ + " > " + std::string(tmp) + "\"";
      fflush(stdout);
      fflush(stdin);
      if ( system(sys_string.c_str()) == -1){
         throw std::runtime_error("sys call \"" + sys_string + "\" failed\n");
      }

      std::ifstream in(tmp);

      while (in && ! in.eof())
      {
      std::string str;
         getline(in,str);
         v.push_back(str);
      }
       //change back to old dir
      if ( chdir(buffer) != NULL){
         throw std::runtime_error("return to \"" + std::string(buffer) + "\" failed\n");
      }     
#else
  #error "need to define get_dir_list on this platform"
#endif 
   }
}}}

#endif

