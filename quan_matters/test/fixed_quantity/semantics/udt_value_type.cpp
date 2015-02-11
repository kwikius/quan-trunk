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
#include <quan_matters/test/utility/udt.hpp>
#include <quan/length.hpp>
#include <quan/area.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>
#include <quan/reciprocal_time.hpp>
#include <quan/out/angle.hpp>


/*
    Do udt value_types work in t1_quantity?

*/


namespace {

#define QUAN_TEST_FUN(fun) void fun ();

    QUAN_TEST_FUN(udt_value_type_test1)
    QUAN_TEST_FUN(angle_value_type_test)

#undef QUAN_TEST_FUN
}

void udt_value_type_test()
{
#define QUAN_TEST_FUN(fun) fun();
    QUAN_TEST_FUN(udt_value_type_test1)
    QUAN_TEST_FUN(angle_value_type_test)

#undef QUAN_TEST_FUN
}

namespace {

   void udt_value_type_test1()
   {
       using quan::length_;
       using quan::velocity_;
       using quan::time_;
       using quan::area_;
       using quan::reciprocal_time_;
       typedef my::udt<double> udt;

       length_<udt>::m   L1(udt(1));
       time_<udt>::s     t(udt(1));
       reciprocal_time_<udt>::per_s per_s = udt(1) / t;
       velocity_<udt>::m_per_s v = L1 / t;
       QUAN_CHECK(L1.numeric_value() == udt(1));
       length_<udt>::m   L2(udt(1));
       length_<udt>::m   L3 = L1 + L2;
       QUAN_CHECK(L3.numeric_value() == udt(2));

       length_<udt>::m   L4 = L1 - L2;
       QUAN_CHECK(L4.numeric_value() == udt(0));

       area_<udt>::m2  a = L1 * L2;
       QUAN_CHECK(a.numeric_value() == udt(1));

       udt dimless = L1 /L1;
       QUAN_CHECK(dimless == udt(1));
      // length_<udt>::m   L5 = L1 * 2; n/a on my::udt
     //  length_<udt>::m   L6 = 2 * L1; n/a on my::udt
       length_<udt>::m   L7 = L1 * udt(2);
       length_<udt>::m   L8 = udt(2) * L1;
       quan::reciprocal_time_<udt>::per_s rs1 = udt(1) / quan::time_<udt>::s(udt(1));
       //n/a on my::udt
      // quan::reciprocal_time_<udt>::per_s rs2 = 1. / quan::time_<udt>::s(udt(1.));
       quan::length_<udt>::mm L9 = L8;
       quan::length_<udt>::ft L10 = L9;
       quan::area_<udt>::mi2 A2= L10 * L9;
       udt val =  L9 / L10;
       quan::pow<4>(L9);
       quan::area_<udt>::ft2 A3 = quan::pow<2>(L9);
       A2 += A3;
       A2 -= A3;
       A2 *= udt(2);
     //  A2 *= 2; n/a on my::udt
       A2 /= udt(2);
      // A2 /= 2; n/a on my::udt
       

   }

   void angle_value_type_test()
   {

       quan::reciprocal_time_<
           quan::angle::rad
       >::per_ms rad_per_ms(1);
       quan::length::ft radius(1);
       quan::velocity::m_per_s v = rad_per_ms * radius;
       quan::angle::rad angle = rad_per_ms * quan::time::ms(1);
      
   }

}//anon
