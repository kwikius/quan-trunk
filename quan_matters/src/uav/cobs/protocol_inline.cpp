
#include <quan/uav/cobs/protocol.hpp>

/*
   For some input data of length N  the src array src must have a length of N + 1.
   The last byte of the arry will be used to store the checksum
   I do it this way so that the encoded array is local to the function. 
   Reuses src array, no need for temp array in a small mx and Requires no malloc

   Alternativee would be to encode into a bufffer and then write the buffer externally
*/

/*
   actually only need 

   bool in_avail()

   put( byte)

   write(char*)

   byte get();
      
*/

template <typename Port>
void quan::uav::cobs_tx_protocol<Port,
   typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type
 >:: template <uint32_t PayloadSize> encode(uint8_t * src, )
{
   // put in checksum as last byte
   src[array_length-1] = do_checksum(src, array_length-1);
   // +1 for encoding, +1 for terminating 0
   size_t const encoded_size = array_length + 2;
   uint8_t encoded [MaxFrameSize];
   // do cobs encoding
   stuff_data(src,array_length,encoded);
   // add terminating 0
   encoded[array_length + 1] = 0U;

   for ( size_t i = 0; i < encoded_size; ++i){
     Port::put(encoded[i]);
   }
}

template <typename Port, size_t MaxFrameSize>
void quan::uav::cobs_tx_protocol<Port,MaxFrameSize, 
   typename quan::where_<quan::is_model_of<quan::DynamicPort,Port> >::type
 >::encode(uint8_t * src, uint32_t array_length)
{
   // put in checksum as last byte
   src[array_length-1] = do_checksum(src, array_length-1);
   // +1 for encoding, +1 for terminating 0
   size_t const encoded_size = array_length + 2;
   uint8_t encoded [MaxFrameSize];
   // do cobs encoding
   stuff_data(src,array_length,encoded);
   // add terminating 0
   encoded[array_length + 1] = 0U;

   for ( size_t i = 0; i < encoded_size; ++i){
     m_port->put(encoded[i]);
   }
}

// stateful .. keep calling the function until 
// the result is non-zero
// then return value is length of valid data in buffer
// in case of errors returns 0 and resyncs ready for new input
template <typename Port, size_t Size>
uint32_t quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type
>::decode(uint8_t * decoded)
{
   if ( ! synced ){
      sync();
      return 0U;
   }

   if ( Port::in_avail() > 0){
      input_buffer[cur_idx] =  Port::get();
      if (input_buffer[cur_idx] == 0 ){ 
         // got end of frame...
         if ( cur_idx == 0)
         {  // empty frame
            return 0U;
         }
         // else decode it into data
         if ( ll_decode(input_buffer,cur_idx,decoded) )
         {
            // subtract 2 from length to remove checksum and terminating 0 from frame
            auto const result_len = cur_idx -2;
            // zero index for next frame
            cur_idx = 0;
            return result_len;
         }
         else // checksum failed
         {
            Port::write("checksum failed");
            synced = false;
            // zero index for next frame
            cur_idx = 0;
            return 0U;
         }

      }else{ // not end of frame yet. check max frame size not exceeded
         if ( ++cur_idx < (max_frame_size + 2) )
         {
            return 0U;
         }
         else 
            {
            Port::write("frame too long");
            synced = false;
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
uint32_t quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::DynamicPort,Port> >::type
>::decode(uint8_t * decoded)
{
   if ( ! m_synced ){
      sync();
      return 0U;
   }

   if ( m_port->in_avail() > 0){
      input_buffer[m_cur_idx] =  m_port->get();
      if (input_buffer[m_cur_idx] == 0 ){ 
         // got end of frame...
         if ( m_cur_idx == 0)
         {  // empty frame
            return 0U;
         }
         // else decode it into data
         if ( ll_decode(input_buffer,m_cur_idx,decoded) )
         {
            // subtract 2 from length to remove checksum and terminating 0 from frame
            auto const result_len = m_cur_idx -2;
            // zero index for next frame
            m_cur_idx = 0;
            return result_len;
         }
         else // checksum failed
         {
            m_port->write("checksum failed");
            m_synced = false;
            // zero index for next frame
            m_cur_idx = 0;
            return 0U;
         }

      }else{ // not end of frame yet. check max frame size not exceeded
         if ( ++m_cur_idx < (max_frame_size + 2) )
         {
            return 0U;
         }
         else 
            {
            m_port->write("frame too long");
            m_synced = false;
            // zero index for next frame
            m_cur_idx = 0;
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
void quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type
>::sync()
{
   if ( (Port::in_avail() ) && (Port::get() == 0U) ){
         synced = true;
   }
}
template <typename Port, size_t Size>
void quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::DynamicPort,Port> >::type
>::sync()
{
   if ( (m_port->in_avail() ) && (m_port->get() == 0U) ){
         m_synced = true;
   }
}



template <typename Port, size_t Size>
uint8_t quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type
>::input_buffer[max_frame_size + 2];

template <typename Port,size_t Size>
uint32_t quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type
>::cur_idx = 0U;

// for a real stream it wont be synced but for sym it is
template<typename Port,size_t Size>
bool quan::uav::cobs_rx_protocol<Port,Size,
   typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type
>::synced = false;

