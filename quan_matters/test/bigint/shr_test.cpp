#include "bigint_test.hpp"

void quan::test::bigint_shr_test()
{
     std::cout << "bigint shr_test\n";
     quan::bigint v1 = "4848484800000000"  ;
     v1 >>= "2";
  //   std::cout << v1.to_string() <<'\n';
     QUAN_CHECK(v1.to_string() == "1212121200000000");
     v1 =  "1";
     v1 <<= "20";
     QUAN_CHECK(v1.to_binary_string() == "0b100000000000000000000")
     v1 >>= "20";
    // std::cout << "???" << v1.to_binary_string() <<'\n';
     QUAN_CHECK(v1.to_binary_string() == "0b1" )

     v1 = "4848484800000001"  ;
     v1 >>= "2";
  //   std::cout << v1.to_string() <<'\n';
     QUAN_CHECK(v1.to_string() == "1212121200000000");
}