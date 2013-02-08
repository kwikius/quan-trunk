#include "bigint_test.hpp"

void quan::test::bigint_shl_test()
{
  std::cout << "bigint shl_test\n";
  quan::bigint v1 = "1212121200000000";
  v1 <<= "2";
//  std::cout << v1.to_string() <<'\n';
  QUAN_CHECK(v1.to_string() == "4848484800000000");

  v1 = "1";
  v1 <<= "20";
// std::cout << "???" << v1.to_binary_string() <<'\n';
  QUAN_CHECK(v1.to_binary_string() == "0b100000000000000000000")
}