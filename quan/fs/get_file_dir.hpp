#ifndef QUAN_FS_GET_FILE_DIR_HPP_INCLUDED
#define QUAN_FS_GET_FILE_DIR_HPP_INCLUDED

#include <quan/fs/get_abs_file_path.hpp>
#include <string>
#include <cassert>

namespace quan{ namespace fs{
    inline 
    std::string get_file_dir(std::string file_name){
       std::string abs_f = get_abs_file_path(file_name);
       for( std::size_t pos = abs_f.length() ;pos >1; --pos ){
        if (abs_f[pos-1] == '/'){
         return abs_f.substr(0,pos-1);
        }
       }
       //shouldnt get here
       assert(false);
       return abs_f;
    }
}}

#endif // QUAN_FS_GET_FILE_DIR_HPP_INCLUDED
