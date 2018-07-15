

#include <cstdint>
#include <quan_matters/test/test.hpp>

/*
  CRC test for Sensirion SDP3x digital differential pressure sensor
*/

namespace {

   // input: data must be a non null pointer to an array of data to be crced of length num_elements
   // output: the calculated crc
   uint8_t sdp3x_crc(const uint8_t * data, uint32_t num_elements)
   {

      uint8_t constexpr init_crc_value = 0xFF;
      uint8_t constexpr polynomial = 0x31;

      uint8_t crc_value = init_crc_value;

      for (uint32_t i = 0U; i < num_elements; ++i) {
         crc_value ^= data[i];
         for (uint8_t j = 0U; j < 8U; ++j) {
            crc_value = ((crc_value & 0x80) == 0U) 
            ? (crc_value << 1U)
            : (crc_value << 1U) ^ polynomial;
         }
      }

      return crc_value;
   }

}

int errors = 0;

int main()
{
  // Test data as provided in sdp3x i2c manual section 5.4

  uint8_t data[] = {0xBE, 0xEF};
  uint8_t constexpr expected_crc = 0x92;

  QUAN_CHECK(sdp3x_crc(data, sizeof(data)/ sizeof(data[0])) == expected_crc);

  QUAN_EPILOGUE
   
}


