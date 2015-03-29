#ifndef QUAN_FS_GET_FILE_DIR_HPP_INCLUDED
#define QUAN_FS_GET_FILE_DIR_HPP_INCLUDED
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

#include <quan/fs/get_abs_file_path.hpp>
#include <string>
#include <cassert>

/*
n.b check file exists before calling
*/
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
