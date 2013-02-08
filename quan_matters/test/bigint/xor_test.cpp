#include "bigint_test.hpp"

void quan::test::bigint_xor_test()
{
  std::cout << "bigint xor_test\n";
  quan::bigint v1 =               "0xF00000000000000000000000000065000000000000000000";
  v1 ^=                           "0xF1F000000000000000000000000050000000000000000000";
  //std::cout << "!? " << v1.to_hex_string() <<'\n';
  QUAN_CHECK(v1.to_hex_string() == "0x1F000000000000000000000000035000000000000000000")

}

