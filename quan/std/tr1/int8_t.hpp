#ifndef QUAN_STD_TR1_INT8_T_HPP_INCLUDED
#define QUAN_STD_TR1_INT8_T_HPP_INCLUDED
/*
 Copyright (c) 2003 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <quan/config.hpp>

#if defined( QUAN_USE_QUAN_STD_TR1)

#include <limits.h>

namespace std{ namespace tr1{
   
#if  (SCHAR_MAX == 0x7f)
   typedef signed char int8_t ;
#else
#error no 8 bit int available for int8_t
#endif

}}

#endif

#endif

