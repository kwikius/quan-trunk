#ifndef QUAN_CONVERT_FLOAT_TO_ASCII_HPP_INCLUDED
#define QUAN_CONVERT_FLOAT_TO_ASCII_HPP_INCLUDED
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
 
#include <cmath>
#include <quan/conversion/itoa.hpp>
#include <quan/meta/integer_max.hpp>

namespace quan {

   // Decimals can be up to 7
   // integer part up to 2^31
   template <uint8_t Decimals>
   inline int32_t float_to_ascii (double const & in, char* outbuf)
   {
      static_assert(Decimals < 8,"Only up to 8 decimals allowed");
   // separate into integer and  fraction
      double intpartf;
      double fractf = std::modf (in,&intpartf);
      if ( intpartf > quan::meta::integer_max<int32_t>::value){
        return -1;
      }
      for (uint8_t i = 0; i < Decimals; ++i) {
         fractf *=10;
      }
      int32_t fracti = static_cast<int32_t> (fractf + 0.5);
      char fractbuf[sizeof (int32_t) * 8 + 2];
      quan::itoasc (fracti,fractbuf,10);
      
      int32_t intparti = static_cast<int32_t> (intpartf);
      
      quan::itoasc (intparti,outbuf,10);
      char * ptr = outbuf + strlen (outbuf);
      *ptr = '.';
      strcpy (ptr+1,fractbuf);
      
      return strlen(outbuf);
      
   }
 
}
 
#endif // QUAN_CONVERT_FLOAT_TO_ASCII_HPP_INCLUDED
 
