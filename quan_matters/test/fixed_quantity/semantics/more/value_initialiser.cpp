// Copyright Andrew Little 2006
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>

#include <quan/velocity.hpp>
#include <quan/volume.hpp>
#include <quan/energy.hpp>

namespace {

#define QUAN_TEST_FUN(fun) void fun ();

   QUAN_TEST_FUN(value_init)
   QUAN_TEST_FUN(down_cast_value_init)
   QUAN_TEST_FUN(out_of_range_value_init)

#undef QUAN_TEST_FUN
}

void value_initialiser_test()
{
#define QUAN_TEST_FUN(fun) fun();

   QUAN_TEST_FUN(value_init)
   QUAN_TEST_FUN(down_cast_value_init)
   QUAN_TEST_FUN(out_of_range_value_init)

#undef QUAN_TEST_FUN
}

namespace {

   void value_init()
   {
      quan::velocity::m_per_s V1(1.2345);
      QUAN_CHECK(V1.numeric_value() == 1.2345);

      quan::velocity::km_per_h V2(250);
      QUAN_CHECK(V2.numeric_value() == 250); 

      quan::velocity::ft_per_s V3(200.7654321);
      QUAN_CHECK(V3.numeric_value() == 200.7654321);

   }

   void down_cast_value_init()
   {
       quan::energy_<int>::kJ  E1(100.2);
       QUAN_CHECK(E1.numeric_value() == 100);
       
       quan::energy_<int>::kJ  E2(-100.2);
       QUAN_CHECK(E2.numeric_value() == -100);

       quan::energy_<int>::kJ  E3(99.49999999);
       QUAN_CHECK(E3.numeric_value() == 99);

       quan::energy_<int>::kJ  E4(-99.49999999);
       QUAN_CHECK(E4.numeric_value() == -99);

       quan::energy_<int>::kJ  E5(99.5000001);
       QUAN_CHECK(E5.numeric_value() == 100);

       quan::energy_<int>::kJ  E6(-99.5000001);
       QUAN_CHECK(E6.numeric_value() == -100);

   }

   void out_of_range_value_init()
   {
   #ifndef __AVR__
       bool caught = false;

       try{
           quan::volume_<QUAN_FLOAT_TYPE>::in3 Vo1(QUAN_FLOAT_TYPE(INT_MAX)+1); 
       } 
       catch ( std::exception & ){
           caught = true;
       }
       QUAN_CHECK(caught == false);

       caught = false;
       try{
           quan::volume_<int>::in3 Vo1(QUAN_FLOAT_TYPE(INT_MAX)+1); 
       } 
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught);

       caught = false;
       try{
           quan::volume_<QUAN_FLOAT_TYPE>::in3 Vo1(QUAN_FLOAT_TYPE(INT_MIN)-1); 
       } 
       catch ( std::exception & ){
           caught = true;
       }
       QUAN_CHECK(caught == false);

       caught = false;
       try{
           quan::volume_<int>::in3 Vo1(QUAN_FLOAT_TYPE(INT_MIN)-1); 
       } 
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught);
   #endif
   }

}//anon
