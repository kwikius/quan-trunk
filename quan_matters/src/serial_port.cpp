/*
 Copyright (c) 2012 - 2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

 #if ! defined __MBED__

#include <sys/ioctl.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>
#include <err.h>

#ifdef __linux
#include <linux/serial.h>
#include <linux/usbdevice_fs.h>
#endif

#include <quan/serial_port.hpp>
#include <quan/utility/timer.hpp>

quan::serial_port::serial_port( const char* filename)
: m_filename{filename},
m_fd{0},
m_old_termios{nullptr}, 
m_good_state(false)
{

}

namespace {

   bool check_valid_baud( int baud)
   {
      switch (baud){
         case B50:     case B75:     case B110:    case B134:    case B150:
         case B200:    case B300:    case B600:    case B1200:   case B1800:
         case B2400:   case B4800:   case B9600:   case B19200:  case B38400:
         case B57600:  case B115200: case B230400:
         #ifdef __linux
         case B460800: case B500000:
         case B576000: case B921600: case B1000000:case B1152000:case B1500000:
         #endif
            return  true;
         default:
            return false;
      }
   }
}

bool quan::serial_port::good()const
{
  return m_good_state == true;
}

bool quan::serial_port::is_deleteable() const
{
   return true;
}
  // 8,N 1
// baud baud constant, bits parity, stop bits
 // databits 5,6,7,8,
 // parity 0= none, 1 = even , -1 = odd, stopbits 1 or 2
void quan::serial_port::init(int baud, int databits, int parity, int stopbits)
{
    if ( ! check_valid_baud(baud)){
        throw std::logic_error("invalid baud rate constant");
    }
    this->m_fd = open(this->m_filename.c_str(),O_RDWR | O_NOCTTY );
  
    if (this->m_fd < 0) {
      //  perror(this->m_filename.c_str());
        this->m_good_state = false;
       return;
    }

    m_old_termios = new termios;
    bzero(m_old_termios,sizeof(termios));

    termios new_termios; // new serial port settings
    bzero(&new_termios,sizeof(new_termios)); //set all serial port settings to zero

    switch (databits){
       case 8:
         new_termios.c_cflag |= CS8;
         break;
       case 7:
         new_termios.c_cflag |= CS7;
         break;
       case 6:
         new_termios.c_cflag |= CS6;
         break;
       case 5:
         new_termios.c_cflag |= CS5;
         break;
       default:
        throw std::logic_error("init serial port invalid databits");
         break;
    }

    switch (parity){
      
         case 0:
           // default none
            break;
         case 1:
            new_termios.c_cflag |= PARENB;
            break;
         case -1:
            new_termios.c_cflag |= (PARENB | PARODD);
            break;
         default:
            throw std::logic_error("init serial port invalid parity");
            break;
    }

    switch (stopbits){
      case 1:
          //default 1 stop bit
          break;
      case 2:
          new_termios.c_cflag |= CSTOPB;
          break;
      default:
         throw std::logic_error("init serial port invalid stop bits");
         break;
    }
   // stop bits = 1,1/1/2,2

   // CSTOPB means 2 stop bits

   // data bits = 5,6,7,8
 
    // add PARENB for even parity
    // add PARENB | PARODD for odd parity
    // 
   // new_termios.c_cflag |= CS8;      // set 8 data bits
    new_termios.c_cflag |= CLOCAL;   // doesnt own port
    new_termios.c_cflag |= CREAD;    // enable reading serial port also
 
    new_termios.c_cc[VTIME] =12;      // wait 12 tenths of a second for between characters
    new_termios.c_cc[VMIN] = 1;      // min number of characters to read before return
 
    // set baud rate for i/o
    if( cfsetospeed(&new_termios,baud) < 0) {
       // perror("failed to set output baudrate");
        this->cleanup();
        throw std::logic_error("open serial port failed");
 
    }
    if(cfsetispeed(&new_termios,baud) < 0) {
       // perror("failed to set input baudrate");
        this->cleanup();
        throw std::logic_error("open serial port failed");
    }
 
    if(tcgetattr(this->m_fd,this->m_old_termios) < 0) {
       // perror(this->m_filename.c_str());
        this->cleanup();
        throw std::logic_error("open serial port failed");
    }

    tcflush(this->m_fd, TCIOFLUSH);
    tcsetattr(this->m_fd,TCSANOW,&new_termios);
    this->m_good_state = true;
}

void quan::serial_port::flush()
{
   // may require apparently due to kernel bug
   sleep(2);
   tcflush(this->m_fd, TCIFLUSH);
}

size_t quan::serial_port::in_avail()
{
   int num_in_buffer;
   if ( ::ioctl(this->m_fd, FIONREAD, &num_in_buffer) >=0){
      return num_in_buffer;
   }else{
     // perror("failed to get serial port num in buffer status");
      this->cleanup();
      throw std::logic_error("get serial port num in buffer failed");
   }
}

size_t quan::serial_port::in_avail(quan::time::ms const & t, size_t n_in )
{
   quan::timer<quan::time::ms> timer;
   while ( timer() < t){
     size_t n = in_avail();
     if( n >= n_in){
         return n;
     }
   }
   return in_avail();
}


ssize_t quan::serial_port::read( data_type* buf,size_t num)
{
   return ::read(this->m_fd,buf,num);
}

ssize_t quan::serial_port::write(const data_type* buf, size_t num) 
{
    return ::write(this->m_fd,buf,num);
}

ssize_t quan::serial_port::write(const char* buf, size_t num) 
{
    return ::write(this->m_fd,reinterpret_cast<const data_type*>(buf),num);
}

bool quan::serial_port::set_pin( int pin, bool val)
{
    
    int sp_state ;
    if ( ::ioctl(this->m_fd, TIOCMGET, &sp_state) !=0){
      perror("failed to get sp pin state");
      this->cleanup();
      throw std::logic_error("get sp pin state failed");
    }
    sp_state = val ? (sp_state | pin) : (sp_state & ~ pin);
    if ( ::ioctl(this->m_fd, TIOCMSET, &sp_state) !=0){
      perror("failed to set dtr state");
      this->cleanup();
      throw std::logic_error("set dtr state failed");
    }
    return true;
}

bool quan::serial_port::set_dtr(bool val)
{
   return set_pin(TIOCM_DTR,val);
}

bool quan::serial_port::set_rts(bool val)
{
   return set_pin(TIOCM_RTS,val);
}


void quan::serial_port::close()
{
   cleanup();
}

quan::serial_port::~serial_port()
{

  this->cleanup();
}
void quan::serial_port::cleanup()
{
   if (this->m_fd > 0) {
     if (this->m_old_termios != nullptr) {
         tcflush(this->m_fd,TCIFLUSH);
         tcsetattr(this->m_fd,TCSANOW,m_old_termios);
         delete m_old_termios;
         m_old_termios = nullptr;
     }
     ::close(this->m_fd);
     this->m_fd = 0;
   }
}
namespace{
int rate_to_constant(int baudrate) 
{
#define B(x) case x: return B##x
	switch(baudrate) {
		B(50);     B(75);     B(110);    B(134);    B(150);
		B(200);    B(300);    B(600);    B(1200);   B(1800);
		B(2400);   B(4800);   B(9600);   B(19200);  B(38400);
		B(57600);  B(115200); B(230400);
#ifdef __linux
        B(460800); B(500000);
		B(576000); B(921600); B(1000000);B(1152000);B(1500000);
#endif
	default: return 0;
	}
#undef B
}    
}



// look at http://stackoverflow.com/questions/4968529/how-to-set-baud-rate-to-307200-on-linux
int quan::serial_port::set_baud( uint32_t baudrate)
{

  if ( !this->good()){
      return -1;
  }

	int speed = rate_to_constant(baudrate);
   int res = 0;
	if (speed == 0) {
       return -1;
	}

    
	fcntl(this->m_fd, F_SETFL, 0);

   struct termios options;
	tcgetattr(this->m_fd, &options);
   cfsetispeed(&options, speed );
	cfsetospeed(&options, speed );
	//cfsetispeed(&options, speed ?: B38400);
	//cfsetospeed(&options, speed ?: B38400);
	cfmakeraw(&options);
	options.c_cflag |= (CLOCAL | CREAD);
	options.c_cflag &= ~CRTSCTS;
   res = tcsetattr(this->m_fd, TCSANOW, &options);


  return res;

}

#endif
