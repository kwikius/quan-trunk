// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/test.hpp>
#include <quan/time.hpp>
#include <quan/pressure.hpp>
#include <quan/out/length.hpp>
#include <quan/out/force.hpp>
#include <quan/out/torque.hpp>
#include <quan/out/energy.hpp>

namespace {
   void minus_test1();
   void subtract_semantics_test();
}

void minus_test()
{
   minus_test1();
   subtract_semantics_test();

}

namespace {
   void minus_test1()
   {
       quan::time::s t0(30.);
       quan::time::s t1(60);
       quan::time::s t2 = t1 - t0;
       QUAN_CHECK(t2.numeric_value() == 30);
       
       quan::time::min t3(1);
       quan::time::s t4 = t3 - t0;
       QUAN_CHECK(t4.numeric_value() == 30);
       quan::time::s t5 = t1 - t3;
       QUAN_CHECK_CLOSE(t5.numeric_value(),0., 1e-9);
       QUAN_CHECK(compare(t3,t1, quan::time::s(1e-8)) ==0);
       QUAN_CHECK(compare(t3,quan::time::s(60), quan::time::s(1e-8)) ==0);

       quan::time::h t6(1);
       quan::time::min t7 = t3 - t6;
       QUAN_CHECK_CLOSE(t7.numeric_value(),- 59.,1e-9);

       quan::pressure_<int>::mPa P1(5000);
       quan::pressure_<int>::Pa  P2(5);
       quan::pressure_<int>::mPa P3 = P1 - P2;
       QUAN_CHECK(P3 == P2 - P2);
       QUAN_CHECK(P3 == P1 - P1); 
       QUAN_CHECK(P3 == P1 - P2);
   }

   void subtract_semantics_test()
   {
       std::ostringstream out;

       quan::length::mm  L1(1); 
       quan::length::m   L2(1);  

       out << L1 - L2 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "-999 mm\n" );
     
       out.str("");
       out << L2 - L1 << '\n';
      // std::cout << out.str();
       QUAN_CHECK( out.str() == "999 mm\n" );
       
       out.str("");
        //larger coherent - smaller incoherent --> smaller units but coherent wins
       quan::length::in  L3(1);  
       out << L2 - L3 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "97.46 cm\n" );

       out.str("");
        //small coherent - larger incoherent --> small coherent wins
       out << L1 - L3 << '\n';
      // std::cout << out.str();
       QUAN_CHECK( out.str() == "-24.4 mm\n" );

       out.str("");
       //small incoh - big incoh -> small incoh wins
       quan::length::ft  L4(1);
       out <<  L3 - L4 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "-11 in\n" );
       out .str("");
       quan::force::kgf F1(1), F2(1);      // kgf is an incoherent-quantity
       out << F1 + F2 << '\n';     // but subtraction of exactly matching units.
      // std::cout << out.str();
       QUAN_CHECK( out.str() == "2 kgf\n" );

       // different named_quantities
       out.str("");
       quan::torque::N_m torque(1);
       quan::energy::J  energy(1);
       out << torque - energy << '\n';
      // std::cout << out.str();
       QUAN_CHECK( out.str() == "0 kg.m+2.s-2\n" );  
   }
}
