#ifndef QUAN_FS_SET_WKG_DIR_HPP_INCLUDED
#define QUAN_FS_SET_WKG_DIR_HPP_INCLUDED
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
