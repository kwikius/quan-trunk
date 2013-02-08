#include "bigint_test.hpp"

namespace quan{ namespace test{


   void test_assign()
   {
      std::cout << "bigint assign test\n";
      bigint v1 = -1;
      QUAN_CHECK(( v1.to_string() == "-1"));
      bigint v2;
      QUAN_CHECK(( v2.to_string() == "0"));
      v2 = v1;
      QUAN_CHECK(( v2.to_string() == "-1"));
      
      
   }


}}
