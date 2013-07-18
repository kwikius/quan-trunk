#ifndef COBS_HPP_INCLUDED
#define COBS_HPP_INCLUDED

#include <cstddef>
#include <cstdint>

namespace quan { namespace uav {

   struct cobs_protocol{
      protected:
      static uint8_t do_checksum(uint8_t * ar, uint32_t len);
   };

   template <typename Port>
   struct cobs_tx_protocol : private cobs_protocol{
      static void encode(uint8_t * src, uint32_t src_size);
   private:
      static void stuff_data(const unsigned char *src,unsigned long length, unsigned char *dst);
   };

   template <typename Port, size_t MaxFrameSize>
   struct cobs_rx_protocol : private cobs_protocol{

      static constexpr size_t max_frame_size = MaxFrameSize;
   // if result is not zero then a frame is in the buffer 
   // return value is length of valid data in buffer
      static uint32_t decode(uint8_t * decoded);

   private:
      static bool synced ;
      static uint8_t input_buffer[max_frame_size + 2];
      static uint32_t cur_idx ;

      static void sync();
      static void unstuff_data(unsigned long length, unsigned char *dst);
      static bool ll_decode( uint32_t src_bufsize, uint8_t* dest);
   };

}}// quan::uav

#endif // COBS_HPP_INCLUDED
