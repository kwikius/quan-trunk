

#include <quan/uav/cobs/protocol.hpp>


// no packet may be more than 254 bytes in length!
void quan::uav::cobs::encode(uint8_t const *src,uint32_t length, uint8_t *dst)
{
  uint8_t *code_ptr = dst++;
  uint8_t code = 0x01;
  for (uint8_t const* const end = src + length; src < end ;++src)
  {
    if (*src)
    {
      *dst++ = *src;
      if (++code == 0xFF)
      {
        *code_ptr = code;
         code_ptr = dst++;
         code = 0x01;
      }
    }
    else
    {
      *code_ptr = code;
      code_ptr = dst++;
      code = 0x01;
    }
  }
  *code_ptr = code;
}




bool  quan::uav::cobs::decode(uint8_t const * src,uint32_t const length, uint8_t * dest)
{
 ;
  uint8_t * dest_end = dest + length;
  
  for(uint8_t const * const end = src + length; src < end;)
  {
    int const code = *src++;
    for (int i=1 ; i < code ; ++i){
      // sanity check for corrupted data
      if (dest < dest_end){
         *dest++ = *src++;
      }
      else{
         return false;
      }
    }
    //  if final buyte != 0xff then add terminating 0
    if (code != 0xFF){
       // sanity check for corrupted data
       if (dest < dest_end){
          *dest++ = 0;
       }
       else{
         return false;
       }
    }
  }
  return true;
}




