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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#if ! defined __MBED__

#include <quan/uav/frsky2wsp/protocol.hpp>
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <cassert>

#define DYNAMIC_MODEL  typename quan::where_<quan::is_model_of<quan::DynamicPort,Port> >::type 
#define STATIC_MODEL  typename quan::where_<quan::is_model_of<quan::StaticPort,Port> >::type 

//-------
template <typename Port>
FrSky2WSP::protocol<Port,DYNAMIC_MODEL>::~protocol()
{
   if ( m_port != nullptr){
      if ( m_port->is_deleteable()){
        delete m_port;
      }
      m_port = nullptr;
  }
}

template <typename Port>
FrSky2WSP::protocol<Port,STATIC_MODEL>::~protocol()
{

}
//-----------

FrSky2WSP::basic_protocol::basic_protocol()
: m_synced{false}, m_buffer_index{0}
{
  ::memset(m_buffer,0,11);
}

template <typename Port>
FrSky2WSP::protocol<Port,DYNAMIC_MODEL>::protocol(Port* port)
:m_port{port}
{
   assert(port);
}

template <typename Port>
FrSky2WSP::protocol<Port,STATIC_MODEL>::protocol()
{
 
}
//----------
template <typename Port>
bool FrSky2WSP::protocol<Port,DYNAMIC_MODEL>::good() const
{
  return m_port->good();
}

template <typename Port>
bool FrSky2WSP::protocol<Port,STATIC_MODEL>::good()const
{
  return true;
}

//--------

template <typename Port>
uint32_t FrSky2WSP::protocol<Port,DYNAMIC_MODEL>::in_avail() const
{
  return m_port->in_avail();
}

template <typename Port>
uint32_t  FrSky2WSP::protocol<Port,STATIC_MODEL>::in_avail() const
{
  return Port::in_avail();
}
//------


/*
 read input ignore esapes
*/
template <typename Port>
void FrSky2WSP::protocol<Port,DYNAMIC_MODEL>::raw_get()
{
  if (m_port->read(m_buffer + m_buffer_index,1) == 0) {
      throw std::logic_error( "failed to read byte\n");
  }
}

template <typename Port>
void FrSky2WSP::protocol<Port,STATIC_MODEL>::raw_get()
{
  //Port::read(m_buffer + m_buffer_index,1);
   m_buffer[m_buffer_index] = Port::get();
}

/*
 read input and expand escapes
*/
template <typename Port>
void FrSky2WSP::protocol<Port,DYNAMIC_MODEL>::get()
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

template <typename Port>
void FrSky2WSP::protocol<Port,STATIC_MODEL>::get()
{
     m_buffer[m_buffer_index] = Port::get();
  // could also filter out if its a 0x 7E which is invalid in the frame
  if ( m_buffer[m_buffer_index] == 0x7D) {
      m_buffer[m_buffer_index] = Port::get() ^ 0x20;
  }
}

/*
 return true if we got a frame else false
  will return if not enough in buffer yet
 throw on bad error
 returned Frame has had head and tail markers removed
*/

bool FrSky2WSP::basic_protocol::get_frame(unsigned char(& destbuf)[9])
{
   for(;;){
      if ( in_avail() < 3){ // serial port has not enough data yet
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
               //  make sure min 3 in buffer to avoid blocking or loss
               // but need to know size of port buffer!
               //##############################
               raw_get();
               if ( m_buffer[1] == 0x7E){ // this was start of frame
                  raw_get();  // so overwrite with first data byte
               }
               // cant be a 0x7E now!
               if ( m_buffer[1] == 0x7E){
                 // fprintf(stderr,"unexpected start of frame in data");
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
              // assert(false && "shouldnt get here");
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
                //  fprintf(stderr,"invalid start of frame in getframe");
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
                  // check for user data valid number of bytes
                  if ( this->m_buffer[0] == FrSky2WSP::CommandID::UserData){
                       auto nbytes = this->m_buffer[1];
                       if (( nbytes == 0) || ( nbytes > 6)) { // invalid
                           m_synced = false;
                           m_buffer_index = 0;
                           return false; // not got the full frame yet
                       }
                  }
                  memcpy(destbuf,this->m_buffer+1,9);
                  m_buffer_index = 0;
                  return true; // success!
               }else{
                 // fprintf(stderr,"invalid end of frame in getframe");
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

#endif



