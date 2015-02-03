#ifndef QUAN_STD_TR1_UINT16_T_HPP_INCLUDED
#define QUAN_STD_TR1_UINT16_T_HPP_INCLUDED
/*
 Copyright (c) 2005 - 2013 Andy Little 

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
   
#if  (UCHAR_MAX >= 0xffff)
   typedef unsigned char uint16_t ;
#elif  (USHRT_MAX >= 0xffff)
   typedef unsigned  short uint16_t ;
#elif (UINT_MAX >= 0xffff)
   typedef unsigned int uint16_t ;
#else
#error no 16 bit int available for uint16_t
#endif

}}

#endif
#endif

