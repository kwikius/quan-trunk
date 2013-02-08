#include "bigint_test.hpp"

void quan::test::bigint_and_test()
{
  std::cout << "bigint and_test\n";
  quan::bigint v1 =                  "0xFF02000000000000000000000000000000000000000";
  v1 &=                            "0xFFFE03000000000000000000000000000000000000000";
  QUAN_CHECK(v1.to_hex_string() ==   "0xFE02000000000000000000000000000000000000000")
}

