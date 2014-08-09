#ifndef QUAN_CONVERT_FLOAT_TO_ASCII_HPP_INCLUDED
#define QUAN_CONVERT_FLOAT_TO_ASCII_HPP_INCLUDED
 
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
 