/*
  quan::bigint plus_test
*/

#include "bigint_test.hpp"

void quan::test::bigint_plus_test()
{
   std::cout << "bigint plus test\n";
   quan::bigint v1 = -1;

   QUAN_CHECK(( v1.to_string() == "-1"));

   QUAN_CHECK((v1.to_double() == -1.0))
  // std::cout << v1.to_double() <<'\n';
   auto v2 = v1 + v1;

   QUAN_CHECK(( v2.to_string() == "-2"))
   
   v2 = v2 + "20";

   QUAN_CHECK((v2.to_string() == "18"));
   v1 = "100000000000000000000000000000000000000000900";
   v2 = "100000000000000000000000000000000000000000011";
   auto v3 = v1 + v2;

   QUAN_CHECK((v3.to_string() == "200000000000000000000000000000000000000000911"));
}


