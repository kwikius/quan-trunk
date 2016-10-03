#ifndef QUAN_PLATFORM_MAC_SERIAL_PORT_HPP_INCLUDED
#define QUAN_PLATFORM_MAC_SERIAL_PORT_HPP_INCLUDED

#if !defined(__APPLE__)
#error "only for use on macOS"
#endif

// just reuse the linux one
#include <quan/platform/linux/serial_port.hpp>

#endif //QUAN_PLATFORM_MAC_SERIAL_PORT_HPP_INCLUDED
