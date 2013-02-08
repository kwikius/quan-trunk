#include "bigint_test.hpp"

void quan::test::bigint_or_test()
{
  std::cout << "bigint or_test\n";
  quan::bigint v1 =                    "0xF0A0000000000000000000000000007";
  v1 |=                            "0x1000FF0E000000000000000000000000000";
  QUAN_CHECK(v1.to_hex_string() == "0x1000FFAE000000000000000000000000007")
 // std::cout << v1.to_hex_string() <<'\n';
}
