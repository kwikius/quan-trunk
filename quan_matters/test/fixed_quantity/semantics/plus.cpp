/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
*/

//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/simple_test.hpp>
#include <quan/time.hpp>
#include <quan/pressure.hpp>
#include <quan/out/length.hpp>
#include <quan/out/force.hpp>
#include <quan/out/torque.hpp>
#include <quan/out/energy.hpp>
#include <string>
#include <sstream>


namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(plus_test1)
    QUAN_TEST_FUN(add_semantics_test)

#undef QUAN_TEST_FUN
}

void plus_test()
{
#define QUAN_TEST_FUN(fun) fun();
    QUAN_TEST_FUN(plus_test1)
    QUAN_TEST_FUN(add_semantics_test)
#undef QUAN_TEST_FUN
}

namespace {

   void plus_test1()
   {
       quan::time::s t0(30.);
       quan::time::s t1 = t0 + t0;
       QUAN_CHECK(t1.numeric_value() == 60.);
       quan::time::min t3(1);
       quan::time::s t4 = t1 + t3;
       QUAN_CHECK_CLOSE(t4.numeric_value(),120., 1e-9);
       QUAN_CHECK(compare(t3,t1, quan::time::s(1e-8)) ==0);
       QUAN_CHECK(compare(t3,quan::time::s(60), quan::time::s(1e-8)) ==0);

       quan::pressure_<int>::mPa P1(5000);
       quan::pressure_<int>::Pa  P2(5);
       quan::pressure_<int>::mPa P3 = P1 + P2;
       QUAN_CHECK(P3 == P2 + P2);
       QUAN_CHECK(P3 == P1 + P1); 
   }

   void add_semantics_test()
   {
       std::ostringstream out;

       quan::length::mm  L1(1); 
       quan::length::m   L2(1);  

       out << L1 + L2 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "1001 mm\n" );
     
       out.str("");
       out << L2 + L1 << '\n';
      // std::cout << out.str();
       QUAN_CHECK( out.str() == "1001 mm\n" );
       
       out.str("");
        //larger coherent + smaller incoherent --> smaller units but coherent wins
       quan::length::in  L3(1);  
       out << L2 + L3 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "102.54 cm\n" );

       out.str("");
        //small coherent + larger incoherent --> small coherent wins
       out << L1 + L3 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "26.4 mm\n" );

       out.str("");
       //small incoh + big incoh -> small incoh wins
       quan::length::ft  L4(1);
       out << L3 + L4 << '\n';
     //  std::cout << out.str();
       QUAN_CHECK( out.str() == "13 in\n" );
       out.str("");
       quan::force::kgf F1(1), F2(1);      // kgf is an incoherent-quantity
       out << F1 + F2 << '\n';     // but addition of exactly matching units.
      // std::cout << out.str();
       QUAN_CHECK( out.str() == "2 kgf\n" );

       // different named_quantities
       out.str("");
       quan::torque::N_m torque(1);
       quan::energy::J  energy(1);
       out << torque + energy << '\n';
       QUAN_CHECK( out.str() == "2 kg.m+2.s-2\n" );  
   }

}
