/*
  quan::bigint plus_test
*/

#include "bigint_test.hpp"

void quan::test::bigint_plus_eq_test()
{
   std::cout << "bigint plus_eq test\n";
   quan::bigint v1 = -1;

   QUAN_CHECK(( v1.to_string() == "-1"));

   QUAN_CHECK((v1.to_double() == -1.0))
  // std::cout << v1.to_double() <<'\n';
   v1 += v1;

   QUAN_CHECK(( v1.to_string() == "-2"))

   quan::bigint v2 =              "1000000000000000000000000000000";

   QUAN_CHECK(( v2.to_string() == "1000000000000000000000000000000"))
  // std::cout <<"to string = " << v2.to_string() <<'\n';
   v2 += v1;
   QUAN_CHECK(( v2.to_string() == "999999999999999999999999999998"))
  // std::cout <<"to string = " << v2.to_string() <<'\n';

   v1 += v2;
   QUAN_CHECK(( v1.to_string() == "999999999999999999999999999996"))
  // std::cout <<"to string = " << v1.to_string() <<'\n';
   v1 = 4;
   QUAN_CHECK(( v1.to_string() == "4"))

   v1 += v2;
   QUAN_CHECK(( v1.to_string() == "1000000000000000000000000000002"))

   v1 = "1";
   v2 = "1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="2"))

   v1 = "1";
   v2 = "-1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="0"))

   v1 = "-1";
   v2 = "1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="0"))

   v1 = "-1";
   v2 = "-1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="-2"))

   v1 = "2";
   v2 = "1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="3"))

   v1 = "2";
   v2 = "-1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="1"))

   v1 = "-2";
   v2 = "1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="-1"))

   v1 = "-2";
   v2 = "-1";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="-3"))

   v1 = "1";
   v2 = "2";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="3"))

   v1 = "1";
   v2 = "-2";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="-1"))

   v1 = "-1";
   v2 = "2";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="1"))

   v1 = "-1";
   v2 = "-2";
   v1 += v2;
   QUAN_CHECK((v1.to_string() =="-3"))

  v1 += v1;
   QUAN_CHECK((v1.to_string() =="-6"))
  v2 =                         "11111111111111111111111111111111111111111123";
//   std::cout << "-------------end plus_eq test\n";
 // std::cout << v2.to_string() <<'\n';
  v2 += v2;
   
   QUAN_CHECK((v2.to_string() =="22222222222222222222222222222222222222222246"))
  // std::cout << "------------end plus_eq test1\n";
//   v2.div_eq(10);
  // std::cout << v2.to_string() <<'\n';

}


