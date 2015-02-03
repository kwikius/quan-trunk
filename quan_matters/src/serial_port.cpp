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


#include <sys/ioctl.h>
//#include <asm/ioctls.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdexcept>

//#include <termio.h>
#include <err.h>
#include <linux/serial.h>
//#include <errno.h>
//#include <string.h>

#include <quan/serial_port.hpp>


quan::serial_port::serial_port( const char* filename)
: m_filename{filename},
m_fd{0},
m_old_termios{nullptr}, 
m_good_state(false)
{

}

bool quan::serial_port::good()const
{
  return m_good_state == true;
}

bool quan::serial_port::is_deleteable() const
{
   return true;
}

void quan::serial_port::init()
{
    this->m_fd = open(this->m_filename.c_str(),O_RDWR | O_NOCTTY );
  
    if (this->m_fd < 0) {
        perror(this->m_filename.c_str());
        this->m_good_state = false;
       return;
    }

    m_old_termios = new termios;
    bzero(m_old_termios,sizeof(termios));

    termios new_termios; // new serial port settings
    bzero(&new_termios,sizeof(new_termios)); //set all serial port settings to zero
 
    new_termios.c_cflag |= CS8;      // set 8 data bits
    new_termios.c_cflag |= CLOCAL;   // doesnt own port
    new_termios.c_cflag |= CREAD;    // enable reading serial port also
 
    new_termios.c_cc[VTIME] =5;      // wait 5 tenths of a second for between characters
    new_termios.c_cc[VMIN] = 1;      // min number of characters to read before return
 
    // set baud rate for i/o
    if( cfsetospeed(&new_termios,B9600) < 0) {
        perror("failed to set output baudrate");
        this->cleanup();
        throw std::logic_error("open serial port failed");
 
    }
    if(cfsetispeed(&new_termios,B9600) < 0) {
        perror("failed to set input baudrate");
        this->cleanup();
        throw std::logic_error("open serial port failed");
    }
 
    if(tcgetattr(this->m_fd,this->m_old_termios) < 0) {
        perror(this->m_filename.c_str());
        this->cleanup();
        throw std::logic_error("open serial port failed");
    }

    tcflush(this->m_fd, TCIOFLUSH);
    tcsetattr(this->m_fd,TCSANOW,&new_termios);
    this->m_good_state = true;
}

size_t quan::serial_port::in_avail()
{
   int num_in_buffer;
   if ( ::ioctl(this->m_fd, FIONREAD, &num_in_buffer) >=0){
      return num_in_buffer;
   }else{
      perror("failed to get serial port num in buffer status");
      this->cleanup();
      throw std::logic_error("get serial port num in buffer failed");
   }
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

bool quan::serial_port::set_dtr(bool val)
{
    
    int sp_state ;
    if ( ::ioctl(this->m_fd, TIOCMGET, &sp_state) !=0){
      perror("failed to get sp pin state");
      this->cleanup();
      throw std::logic_error("get sp pin state failed");
    }
    sp_state = val ? (sp_state | TIOCM_CTS) : (sp_state & ~TIOCM_CTS);
    if ( ::ioctl(this->m_fd, TIOCMSET, &sp_state) !=0){
      perror("failed to set dtr state");
      this->cleanup();
      throw std::logic_error("set dtr state failed");
    }
    return true;
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
     close(this->m_fd);
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
		B(57600);  B(115200); B(230400); B(460800); B(500000); 
		B(576000); B(921600); B(1000000);B(1152000);B(1500000); 
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






