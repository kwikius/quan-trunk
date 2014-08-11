#ifndef QUAN_BYTESIZE_FROM_BITSIZE_HPP_INCLUDED
#define QUAN_BYTESIZE_FROM_BITSIZE_HPP_INCLUDED
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
/*
  for storage that cant be at bit level
  make a byte the smallest size
*/
namespace quan{
   
   inline
   std::size_t 
   bytesize_from_bitsize(std::size_t bitsize)
   {
      std::size_t rem = ( (bitsize % 8U) ==0) ? 0:1;
      return bitsize / std::size_t{8} + rem ;
   }
}

#endif // QUAN_BYTESIZE_FROM_BITSIZE_HPP_INCLUDED
