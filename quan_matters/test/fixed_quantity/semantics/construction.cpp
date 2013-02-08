// Copyright Andrew Little 2005

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>
#include <quan/mass.hpp>
#include <quan/volume.hpp>
#include <quan/energy.hpp>
#include <quan/force.hpp>
#include <type_traits>
#include <limits>
/*
    check t1_quantity construction
    default ctor, value init
    copy ctor , anonymous copy ctor
    down conv value_type copy ctor
    downccast out of range checking
    downcast value init rounding checking

    see also compile_fail/t1_quantity
*/
namespace {
  void default_ctor();
  void value_init();
  void down_cast_value_init();
  void out_of_range_value_init();
  void down_cast_copy_ctor();
  void anonymous_copy_ctor();
  void copy_ctor();
  void value_type_cast_copy_ctor();

}
void construction_test()
{
   default_ctor();
   value_init();
   down_cast_value_init();
   out_of_range_value_init();
   down_cast_copy_ctor();
   anonymous_copy_ctor();
   copy_ctor();
   value_type_cast_copy_ctor();

}
namespace {

   void default_ctor()
   {
       quan::length::m L1;
       QUAN_CHECK( L1.numeric_value() == 0. );
       quan::time_<int>::ps  T1;
       QUAN_CHECK( T1.numeric_value() == 0 );
   }

   void value_init()
   {
       quan::velocity::m_per_s V1(1.2345);
       QUAN_CHECK(V1.numeric_value() == 1.2345);

       quan::velocity::km_per_h V2(250);
       QUAN_CHECK(V2.numeric_value() == 250); 
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
   }

   void out_of_range_value_init()
   {
       bool caught = false;

       try{
           quan::volume_<double>::in3 Vo1(double(INT_MAX)+1); 
       } 
       catch ( std::exception & ){
           caught = true;
       }
       QUAN_CHECK(caught == false);

       caught = false;
       try{
           quan::volume_<int>::in3 Vo1(double(INT_MAX)+1); 
       } 
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught);

       caught = false;
       try{
           quan::volume_<double>::in3 Vo1(double(INT_MIN)-1); 
       } 
       catch ( std::exception & ){
           caught = true;
       }
       QUAN_CHECK(caught == false);

       caught = false;
       try{
           quan::volume_<int>::in3 Vo1(double(INT_MIN)-1); 
       } 
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught);
   }

   void copy_ctor()
   {
   //incoherent
       quan::velocity::mm_per_min V1(54321.12345);
       quan::velocity::mm_per_min V2 = V1;


       QUAN_CHECK( V1.numeric_value() == V2.numeric_value()); 
   //coherent
       quan::time::ms  T1(100000.99999999);
       quan::time::ms  T2 = T1;
       QUAN_CHECK( T2.numeric_value() == T1.numeric_value());

       quan::force_<int>::kgf F1(3.4567);
       quan::force::kgf F2 = F1;

       QUAN_CHECK(F1.numeric_value() == F2.numeric_value());
   }

   void down_cast_copy_ctor()
   {
   //incoherent
       quan::velocity::mm_per_min V1(54321.12345);
       quan::velocity_<int>::mm_per_min V2 = V1;
       QUAN_CHECK( V2.numeric_value() == 54321); 

       quan::velocity::mm_per_min V3(-54321.12345);
       quan::velocity_<int>::mm_per_min V4 = V3;
       QUAN_CHECK( V4.numeric_value() == -54321);

       quan::velocity::mm_per_min V5(54321.52345);
       quan::velocity_<int>::mm_per_min V6 = V5;
       QUAN_CHECK( V6.numeric_value() == 54322); 

       quan::velocity::mm_per_min V7(-54321.52345);
       quan::velocity_<int>::mm_per_min V8 = V7;
       QUAN_CHECK( V8.numeric_value() == -54322);  

   //coherent
       quan::velocity::mm_per_s Va1(54321.12345);
       quan::velocity_<int>::mm_per_s Va2 = Va1;
       QUAN_CHECK( Va2.numeric_value() == 54321); 

       quan::velocity::mm_per_s Va3(-54321.12345);
       quan::velocity_<int>::mm_per_s Va4 = Va3;
       QUAN_CHECK( Va4.numeric_value() == -54321);

       quan::velocity::mm_per_s Va5(54321.52345);
       quan::velocity_<int>::mm_per_s Va6 = Va5;
       QUAN_CHECK( Va6.numeric_value() == 54322); 

       quan::velocity::mm_per_s Va7(-54321.52345);
       quan::velocity_<int>::mm_per_s Va8 = Va7;
       QUAN_CHECK( Va8.numeric_value() == -54322);  
   }

   void anonymous_copy_ctor()
   {
       quan::velocity::m_per_s V1 = quan::length::m(10000) / quan::time::s( 250);
       QUAN_CHECK_EQUAL(V1.numeric_value(), 10000./250); 

       typedef quan::meta::binary_op<
          quan::length::m,
          quan::meta::divides,
          quan::time::s
       >::type anon;

       QUAN_CHECK( (
           std::is_same<
           anon::unit::abstract_quantity::named_quantity_traits,
           quan::meta::anonymous_quantity_traits
           >::value
       ));
            
   }

   void value_type_cast_copy_ctor()
   {
       bool caught = false;

       try {
           quan::length_<double>::m L3( static_cast<double>(INT_MAX)+1 );
           quan::length_<double>::m L4 = L3;
       }
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught == false);

       caught = false;
       try {
           quan::length_<double>::m L3( static_cast<double>(INT_MAX)+1 );
           quan::length_<int>::m L4 = L3;
       }
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught);

       caught = false;
       try {
           quan::length_<double>::m L3( static_cast<double>(INT_MIN)-1 );
           quan::length_<double>::m L4 = L3;
       }
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught==false);

       caught = false;
       try {
           quan::length_<double>::m L3( static_cast<double>(INT_MIN)-1 );
           quan::length_<int>::m L4 = L3;
       }
       catch ( std::exception & ){
          caught = true;
       }
       QUAN_CHECK(caught);
   }

}//anon
