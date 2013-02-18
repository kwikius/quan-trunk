

#include <quan/uav/cobs/protocol.hpp>

/*
  will also need cobs_inline.cpp
*/

uint8_t quan::uav::cobs_protocol::do_checksum(uint8_t * ar, uint32_t len)
{
    uint8_t sum = ar[0];
    for ( size_t i = 1; i < len; ++i) {
        uint16_t const sum1 = sum  + static_cast<uint16_t>(ar[i]);
        sum += static_cast<uint8_t>(sum1 & 0xff)  + static_cast<uint8_t>((sum1 >> 8) && 0xff);
    }
    return sum;
}


