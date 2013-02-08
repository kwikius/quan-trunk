
#include "bigint_test.hpp"

namespace quan{ namespace test{

   void test_no_arg_ctor();
   void test_string_ctor();
   void test_hex_string_ctor();
   void test_char_array_ctor();
   void test_int_ctor();
   void test_unsigned_int_ctor();

   void test_ctor()
   {
      std::cout << "bigint ctor tests\n";
      test_no_arg_ctor();
      test_string_ctor();
      test_hex_string_ctor();
      test_char_array_ctor();
      test_int_ctor();
      test_unsigned_int_ctor();
   }

   void test_no_arg_ctor()
   {
     quan::bigint v1;
     QUAN_CHECK(( v1.to_string() == "0"))
   }

   void test_string_ctor()
   {
      std::string str= "1";
      quan::bigint v1 = str;
      QUAN_CHECK(( v1.to_string()== "1"))

      str = "-1";
      quan::bigint v2 = str;
      QUAN_CHECK(( v2.to_string()== "-1"))

      bool throw_check = false;
      try{
         str = "x";
         quan::bigint v3 = str;
      }
      catch ( std::runtime_error & ){ throw_check = true;}
      QUAN_CHECK(throw_check)
      throw_check = false;
      quan::bigint v4 =              "1000000000000000000000000000000";
      QUAN_CHECK(( v4.to_string() == "1000000000000000000000000000000"))
   }

   void test_hex_string_ctor()
   {
        std::cout << "hex string ctor test\n";
        std::string str = "0x1FF";
        quan::bigint v1 = str;
        QUAN_CHECK(v1.to_string() == "511");
        v1 = "0x10000";
        QUAN_CHECK(v1.to_string() == "65536");
   }

   void test_char_array_ctor()
   {
      quan::bigint v1 = "1";
      QUAN_CHECK(( v1.to_string()== "1"))

      quan::bigint v2 = "-1";
      QUAN_CHECK(( v2.to_string()== "-1"))

      bool throw_check = false;
      try{
         quan::bigint v3 = "x";
      }
      catch ( std::runtime_error & ){ throw_check = true;}
      QUAN_CHECK(throw_check)
      throw_check = false;
   }

   void test_int_ctor()
   {
      quan::bigint v1 = 1;
      QUAN_CHECK(( v1.to_string()== "1"))
      
      quan::bigint v2 = -1;
      QUAN_CHECK(( v2.to_string()== "-1"))

      quan::bigint v1a = 1000000;
      QUAN_CHECK(( v1a.to_string()== "1000000"))

      quan::bigint v3 = 4563879007LL;
      QUAN_CHECK(( v3.to_string()== "4563879007"))

      quan::bigint v4 = -123456787654LL;
      QUAN_CHECK(( v4.to_string()== "-123456787654"))
//#if defined( QUAN_HAS_LONG_LONG)
//  add a zero here compiles no warn but fails
      quan::bigint v5 =              -1234567876540000000LL;
      QUAN_CHECK(( v5.to_string()== "-1234567876540000000"))
   //   std::cout << v5.to_string() <<'\n';
//#endif
   }

   void test_unsigned_int_ctor()
   {
#if(0)
      quan::bigint v1 = 1U;
      QUAN_CHECK(( v1.to_string()== "1"))
      
      quan::bigint v1a = 1000000UL;
      QUAN_CHECK(( v1a.to_string()== "1000000"))

      quan::bigint v3 = 4563879007UL;
      QUAN_CHECK(( v3.to_string()== "4563879007"))

      quan::bigint v5 =              1234567876540000000ULL;
      QUAN_CHECK(( v5.to_string()== "1234567876540000000"))
#endif
   }
}}
