
#include <quan/uav/cobs/protocol.hpp>

/*
   Not great!
   src array is length of src data to be encoded + 1 for checksum .. yeeurch!
   is checksum part of cobs protocol?.. no
   Should cobbs be dependent on Port ... no
   so should copy data locally, make data length a template param?

   I do it this way so that the encoded array is local to the function I guess. 
   Reuses src array, no need for temp array in a small mx and Requires no malloc

   Alternativee would be to encode into a bufffer and then write the buffer externally
*/
template <typename Port>
void quan::uav::cobs_tx_protocol<Port>::encode(uint8_t * src, uint32_t src_size)
{
   // put in checksum as last byte
   src[src_size-1] = do_checksum(src, src_size-1);
   // +1 for encoding, +1 for terminating 0
   size_t const encoded_size = src_size + 2;
   uint8_t encoded [encoded_size];
   // do cobs encoding
   stuff_data(src,src_size,encoded);
   // add terminating 0
   encoded[src_size + 1] = 0U;

   for ( size_t i = 0; i < encoded_size; ++i){
     Port::put(encoded[i]);
   }
}

/*
 * StuffData byte stuffs "length" bytes of
 * data at the location pointed to by "src",
 * writing the output to the location pointed
 * to by "dst".
 * No dependency on Port...
 */

template <typename Port>
void quan::uav::cobs_tx_protocol<Port>:: stuff_data(const unsigned char *src,unsigned long length, unsigned char *dst)
{
  unsigned char *code_ptr = dst++;
  unsigned char code = 0x01;
 
  for (const unsigned char *end = src + length; src < end ;++src)
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

// iterative .. keep calling the function until 
// the result is non-zero
// then return value is length of valid data in buffer
// in case of errors returns 0 and resyncs ready for new input
template <typename Port, size_t Size>
uint32_t quan::uav::cobs_rx_protocol<Port,Size>::decode(uint8_t * decoded)
{
   if ( ! synced ){
      sync();
      return 0U;
   }

   if ( Port::in_avail() > 0){
      input_buffer[cur_idx] =  Port::get();
      if (input_buffer[cur_idx] == 0 ){ // end of frame
         if ( cur_idx == 0)
         {  // empty frame
            return 0U;
         }
         if ( ll_decode(cur_idx,decoded) )
         {
            // subtract 2 from length to remove checksum and terminating 0 from frame
            auto const result_len = cur_idx -2;
            // zero index for next frame
            cur_idx = 0;
            return result_len;
         }
         else
         {
            Port::write("checksum failed");
            synced = 0U;
            // zero index for next frame
            cur_idx = 0;
            return 0U;
         }

      }else{ // not end of frame yet. check max frame size not exceeded
         if ( ++cur_idx < (max_frame_size +2) )
         {
            return 0U;
         }
         else 
            {
            Port::write("frame too long");
            synced = 0U;
            // zero index for next frame
            cur_idx = 0;
            return 0U;
         }
      }
   }
   else
   {
   // no change
      return 0U;
   }
}

template <typename Port, size_t Size>
void quan::uav::cobs_rx_protocol<Port,Size>::sync()
{
   if ( (Port::in_avail() ) && (Port::get() == 0U) ){
         synced = true;
   }
}

template <typename Port, size_t Size>
void quan::uav::cobs_rx_protocol<Port,Size>::unstuff_data(unsigned long length, unsigned char *dst)
{
  const unsigned char *src = input_buffer;
  for(const unsigned char *end = src + length; src < end;)
  {
    int const code = *src++;
    for (int i=1 ; i < code ; ++i){
      *dst++ = *src++;
    }
    if (code < 0xFF){
      *dst++ = 0;
    }
  }
}

template <typename Port, size_t Size>
bool quan::uav::cobs_rx_protocol<Port,Size>::ll_decode( uint32_t src_bufsize, uint8_t* dest)
{
    unstuff_data(src_bufsize, dest);
    return do_checksum(dest,src_bufsize-2) == dest[src_bufsize-2];
}

template <typename Port, size_t Size>
uint8_t quan::uav::cobs_rx_protocol<Port,Size>::input_buffer[max_frame_size + 2];

template <typename Port,size_t Size>
uint32_t quan::uav::cobs_rx_protocol<Port,Size>::cur_idx = 0U;

// for a real stream it wont be synced but for sym it is

template<typename Port,size_t Size>
bool quan::uav::cobs_rx_protocol<Port,Size>::synced = false;

