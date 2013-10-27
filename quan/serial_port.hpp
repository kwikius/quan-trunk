#ifndef QUAN_SERIAL_PORT_HPP_INCLUDED
#define QUAN_SERIAL_PORT_HPP_INCLUDED

#ifdef __linux
#include <quan/platform/linux/serial_port.hpp>
#else
#error need to write serial port code for this platform
#endif


#endif // QUAN_SERIAL_PORT_HPP_INCLUDED
