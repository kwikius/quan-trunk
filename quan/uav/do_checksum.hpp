#ifndef QUAN_UAV_DO_CHECKSUM_HPP_INCLUDED
#define QUAN_UAV_DO_CHECKSUM_HPP_INCLUDED
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

#include <cstdint>

namespace quan{ namespace uav{
/*
do checksum. All bytes except last which is used to hold checksum if creating
 and not read if checking
*/
//!-!-!start-example
   template< uint32_t len>
   inline
   uint8_t do_checksum(uint8_t (&ar)[len])
   {
      uint8_t sum = ar[0];
      for ( uint32_t i = 1; i < (len-1);++i)
     {
        uint16_t sum1 = static_cast<uint16_t>(sum )  + static_cast<uint16_t>( ar[i]);
        sum += sum1 + (sum1 >> 8);
     }
     return sum;
   }
//!-!-!end-example
}}



#endif // QUAN_UAV_DO_CHECKSUM_HPP_INCLUDED
