#include "bigint_test.hpp"

void quan::test::bigint_div_eq_test()
{

   std::cout << "bigint div_eq_test\n";
   quan::bigint v1 = "1000";
   v1.div_eq("3");
   QUAN_CHECK(v1.to_string() == "333");
   v1 = "1000";
   v1.mod_eq("3");
   QUAN_CHECK(v1.to_string() == "1");
   v1 =      "1000000000000000000";
   v1.div_eq( "999000000000000000");
   //  std::cout << v1.to_string() <<'\n';
   QUAN_CHECK(v1.to_string() == "1");
   v1 = "234567";
   QUAN_CHECK(v1.to_string() == "234567");
   v1.div_eq( v1);
   QUAN_CHECK(v1.to_string() == "1");

}