
#include <quan_matters/test/test.hpp>

#include <quan/gcd.hpp>
#include <quan/sign.hpp>
#include <quan/abs.hpp>

namespace {

   void sign_test()
   {
      QUAN_CHECK(quan::sign(1) == 1)
      QUAN_CHECK(quan::sign(0) == 1)
      QUAN_CHECK(quan::sign(0) == 1)
      QUAN_CHECK(quan::sign(0U) == 1)
      QUAN_CHECK(quan::sign(1000U) == 1)
      QUAN_CHECK(quan::sign(-1000) == -1)
      QUAN_CHECK(quan::sign(static_cast<int8_t>(-16)) == -1)
      QUAN_CHECK(quan::sign(static_cast<int8_t>(16)) == 1)
   }

   void abs_test()
   {
      QUAN_CHECK(quan::abs(1) == 1)
      QUAN_CHECK(quan::abs(0) == 0)
      QUAN_CHECK(quan::abs(-1) == 1)
      QUAN_CHECK(quan::abs(0U) == 0U)
      QUAN_CHECK(quan::abs(1000U) == 1000U)
      QUAN_CHECK(quan::abs(-1000) == 1000)
      QUAN_CHECK(quan::abs(static_cast<int8_t>(-16)) == 16)
      QUAN_CHECK(quan::abs(static_cast<int8_t>(16)) == 16)
   }

   void ll_gcd_test()
   {
      QUAN_CHECK (quan::gcd(1,1) == 1)
      QUAN_CHECK (quan::gcd(-1,1) == 1)
      QUAN_CHECK (quan::gcd(1,-1) == 1)
      QUAN_CHECK (quan::gcd(-1,-1) == 1)

      QUAN_CHECK (quan::gcd(5,1) == 1)
      QUAN_CHECK (quan::gcd(450,27) == 9)
     // std::cout << "gcd = " << quan::gcd(450,-27) <<'\n';
      QUAN_CHECK (quan::gcd(450,-27) == 9)
      QUAN_CHECK (quan::gcd(1024,256) == 256)
      
   }
}

void gcd_test()
{
  ll_gcd_test();
  sign_test();
  abs_test();
}


