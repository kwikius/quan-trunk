
#include "bigint_test.hpp"

void quan::test::bigint_minus_eq_test()
{
   std::cout << "bigint minus_eq test\n";
   quan::bigint v1 = "-1";

   QUAN_CHECK(( v1.to_string() == "-1"))

   v1 -= v1;
   QUAN_CHECK(( v1.to_string() == "0"))

   v1                           = "10000000";
   quan::bigint v2 =            "1000000000";
   v1 -= v2;
   QUAN_CHECK(( v1.to_string() == "-990000000"))
   QUAN_CHECK((v1.to_double() ==   -990000000. ))
  // std::cout << "to double = " << v1.to_double() <<'\n';

   v1+= quan::bigint("1");
   QUAN_CHECK(( v1.to_string() == "-989999999"))

   v1+= quan::bigint("-1");
   QUAN_CHECK(( v1.to_string() == "-990000000"))

   v1 = "1";
   v2 = "1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "0"))

   v1 = "1";
   v2 = "-1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "2"))

   v1 = "-1";
   v2 = "1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "-2"))

   v1 = "-1";
   v2 = "-1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "0"))

   v1 = "2";
   v2 = "1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "1"))

   v1 = "2";
   v2 = "-1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "3"))

   v1 = "-2";
   v2 = "1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "-3"))

   v1 = "-2";
   v2 = "-1";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "-1"))


   v1 = "1";
   v2 = "2";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "-1"))

   v1 = "1";
   v2 = "-2";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() == "3"))

   v1 = "-1";
   v2 = "2";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() =="-3"))

   v1 = "-1";
   v2 = "-2";
   v1 -= v2;
   QUAN_CHECK((v1.to_string() =="1"))

   v1 -= v1;
   QUAN_CHECK((v1.to_string() =="0"))

}