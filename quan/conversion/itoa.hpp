#ifndef QUAN_ITOA_HPP_INCLUDED
#define QUAN_ITOA_HPP_INCLUDED

#include <cstring>
#include <cstdint>
/*
  include <quan_matters/src/itoa.cpp>
  and  instantiate as required
*/

namespace quan{

   template <typename IntType>
   inline char * itoasc( IntType in, char * array,  int base )
   {
      if ( (base > 16) || ( base < 2)){
        return nullptr;
      }
      static constexpr size_t arlen = sizeof(IntType) * 8 + 2;
      char local_array[arlen];
      char* ptr = local_array + arlen-1;
      *ptr = '\0';
      --ptr;
      if ( in == 0){
         *ptr = '0';
      }else{
         int32_t const sign = (in>=0)?1:-1;
         IntType abs_in = in * sign;
         for(size_t i = 0; i < arlen; ++i){

            IntType rem = (abs_in % base);
            char ch = ( rem < 10)
               ? static_cast<char>(rem + '0') 
               : static_cast<char>(rem + ('A' - 10));
            *ptr = ch;
            abs_in /= base;
            if( abs_in != 0){
               -- ptr;
               continue;
            }else{
              break;
            }
         }
         if ( sign == -1){
            --ptr;
            *ptr = '-';
         }
      }
      strcpy(array,ptr) ;
      return array;
   }
}


#endif // QUAN_ITOA_HPP_INCLUDED
