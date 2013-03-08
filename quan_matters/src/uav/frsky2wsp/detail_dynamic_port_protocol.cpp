

#include <quan/uav/frsky2wsp/detail/dynamic_port_protocol.hpp>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <cassert>

template <typename Port>
FrSky2WSP::detail::dynamic_port_protocol<Port>::~dynamic_port_protocol()
{
   if ( m_port != nullptr){
      if ( m_port->is_deleteable()){
        delete m_port;
      }
      m_port = nullptr;
  }
}

template <typename Port>
FrSky2WSP::detail::dynamic_port_protocol<Port>::dynamic_port_protocol(Port* port)
:m_port{port}, m_synced{false}, m_buffer_index{0}
{
   assert(port);
   ::memset(m_buffer,0,11);
}

template <typename Port>
bool FrSky2WSP::detail::dynamic_port_protocol<Port>::good() const
{
  return m_port->good();
}

/*
 return true if we got a frame else false
  will return if not enough in buffer yet
 throw on bad error
 returned Frame has had head and tail markers removed
*/
template <typename Port>
bool FrSky2WSP::detail::dynamic_port_protocol<Port>::get_frame(unsigned char(& destbuf)[9])
{
   for(;;){
      if ( m_port->in_avail() < 3){ // serial port has no more data yet
         return false; // not got the full frame yet
      }
      if (!m_synced){
         switch ( m_buffer_index){
            case 0:
            {
               raw_get();
               if ( m_buffer[0] == 0x7E){
                  m_buffer_index = 1; // got end or start of frame so advance
                  // note not synced yet as may have a start of frame yet
               }
               break; // not got the full frame yet
            }
            case 1:
            {
               //#######################
               // ideally make sure min 3 in buffer to avoid blocking?
               // but need to know size of port buffer!
               //##############################
               raw_get();
               if ( m_buffer[1] == 0x7E){ // this was start of frame
                  raw_get();  // so overwrite with first data byte
               }
               // cant be a 0x7E now!
               if ( m_buffer[1] == 0x7E){
                  fprintf(stderr,"unexpected start of frame in data");
                  m_buffer_index = 0;
                  return false; // not got the full frame yet
               }
               //check if what is there is an escape
               if ( m_buffer[1] == 0x7D){ 
                  raw_get();  // read data
                  m_buffer[1] ^= 0x20;   // and unescape it
               }
               ++m_buffer_index; // advance
               m_synced = true; // now synced
               break; // not got the full frame yet
            }
            default:
            {
               assert(false && "shouldnt get here");
               m_buffer_index = 0;
               return false;
            }
         }
      } else { // already synced
         switch ( m_buffer_index){
            // expect header
            case 0:
            {
               raw_get();
               if (this->m_buffer[0] == 0x7E) {
                  ++m_buffer_index;
                  break;
               }else{
                  fprintf(stderr,"invalid start of frame in getframe");
                  m_synced = false;
                  m_buffer_index = 0;
                  return false; // not got the full frame yet
               }
            }
            //expect end of frame
            case 10:
            {
               raw_get();
               if (this->m_buffer[10] == 0x7E) {
                  memcpy(destbuf,this->m_buffer+1,9);
                  m_buffer_index = 0;
                  return true; // success!
               }else{
                  fprintf(stderr,"invalid end of frame in getframe");
                  m_synced = false;
                  m_buffer_index = 0;
                  return false; // not got the full frame yet
               }
            }
            default: // expect data
            {
               get();
               ++m_buffer_index;
               break; // get more of frame if possible
            }
         } // switch
      } // synced
   }// (continuous loop)
}


/*
 read input ignore esapes
*/
template <typename Port>
void FrSky2WSP::detail::dynamic_port_protocol<Port>::raw_get()
{
  if (m_port->read(m_buffer + m_buffer_index,1) == 0) {
      throw std::logic_error( "failed to read byte\n");
  }
}
/*
 read input and expand escapes
*/
template <typename Port>
void FrSky2WSP::detail::dynamic_port_protocol<Port>::get()
{
  if (m_port->read(m_buffer + m_buffer_index,1) == 0) {
      throw std::logic_error( "failed to read byte\n");
  }
  // could also filter out if its a 0x 7E which is invalid in the frame
  if ( m_buffer[m_buffer_index] == 0x7D) {
      if (m_port->read(m_buffer + m_buffer_index,1) ==0) {
          throw std::logic_error ("failed to read byte\n");
      }
      m_buffer[m_buffer_index] ^= 0x20;
  }
}
