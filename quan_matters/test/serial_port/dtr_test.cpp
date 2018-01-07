
#include <quan/serial_port.hpp>
#include <iostream>

int main()
{
  quan::serial_port sp{"/dev/ttyUSB0"};

  sp.init(B9600);
  if ( sp.good()){
     std::cout << "sp good\n";

     sp.set_dtr(true); // N.B The actual pin will read 0 when arg is true on the FTDI I tested anyway
  }else{
     std::cout << "sp bad\n";
  }

  std::cin.get();

  std::cout << "done\n";
   
}