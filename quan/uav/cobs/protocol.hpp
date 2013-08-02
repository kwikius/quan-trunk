#ifndef COBS_HPP_INCLUDED
#define COBS_HPP_INCLUDED

#include <cstdint>

namespace quan { namespace uav { namespace cobs{

   // N.B. The encoded length of the data not including the unencoded framing 0 byte
   template <uint8_t RawLength>
   constexpr inline uint8_t get_encoded_length()
   {
      static_assert(RawLength < 255, "data length too long");
      return RawLength + 1;
   }

   // Length is length of the unencoded data, which must be less than 255 bytes
   // N.B. data does not include the unencoded framing 0 byte
   // length of the array src is assumed to be Length
   // length of the array dest is assumed to be get_encoded_length(length)
   // This function does not add the unencoded framing 0 byte
   inline bool encode(uint8_t const *src, uint8_t src_length, uint8_t *dest)
   {
      if ( src_length < 255){
         uint8_t *code_ptr = dest++;
         uint8_t code = 0x01;
         for(uint8_t const * const src_end = src + src_length;src < src_end;++src){
            if (*src == 0){
               *code_ptr = code;
               code_ptr = dest++;
               code = 0x01;
            }
            else {
               *dest++ = *src;
               if (++code == 0xFF) {
                 *code_ptr = code;
                  code_ptr = dest++;
                  code = 0x01;
               } 
            }
         }
         *code_ptr = code;
         return true;
      }else{
         return false;
      }
   }
   
   // length is length of the encoded data, which must be less than or equal to 255 bytes
   // data does not include the unencoded framing 0 byte
   // length of the array src is assumed to be   length
   // length of the array dest is assumed to be length -1
   // returns true if the data was decoded or 
   // false if it is detected that the decoding process
   // would put data outside the dest buffer indicating corrupted data
   inline bool decode(uint8_t const *src, uint8_t const src_length, uint8_t *dest)
   {
      uint8_t const * const src_end = src + src_length -1;
      uint8_t const * const dest_end = dest + src_length -1;
      while (src < src_end){
         for (int i=1, code = *src++; i<code; ++i) {
          if ( dest < dest_end){
            *dest++ = *src++;
            }
            else {
               return false;
            }
         }
         if ( dest < dest_end){
            *dest++ = 0;
         }
      }
      return true;
   }

}}}// quan::uav::cobs

#endif // COBS_HPP_INCLUDED
