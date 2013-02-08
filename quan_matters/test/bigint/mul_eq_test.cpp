#include "bigint_test.hpp"

void quan::test::bigint_mul_eq_test()
{

   std::cout << "bigint mul_eq test\n";
   quan::bigint v1 = "1";
   quan::bigint v2 = "2";

   v1 *= v2;
   QUAN_CHECK((v1.to_string() == "2"))

   v2 = "-2";
   v1 *= v2;
   QUAN_CHECK((v1.to_string() == "-4"))

   v1 = "-5";
   v2 = v1;
   v1 *= v2;
   QUAN_CHECK((v1.to_string() == "25"))

   v2 = "-5";
   v1 *= v2;
   QUAN_CHECK((v1.to_string() =="-125"))

   v1 = "100000";
   v2 = "-9876543210000000";
   v1 *= v2;
   QUAN_CHECK((v1.to_string() == "-987654321000000000000"))

   v1 = "-9";
   v1 *= v1;
   QUAN_CHECK((v1.to_string() == "81"))
  //  std::cout << v1.to_string() << '\n';
   v1 = "-10000000000000000000000001";
   v2 = "7";
   v1 *= v2;

   QUAN_CHECK((v1.to_string() == "-70000000000000000000000007"))

  v2 *= v2;
  // quan::bigint v3 = v2;

 //  v2 *= v3;
   QUAN_CHECK((v2.to_string() == "49"))

}