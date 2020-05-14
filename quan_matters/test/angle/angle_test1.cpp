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


// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Very preliminary tests on angle types
*/

#include <quan_matters/test/test.hpp>
#include <quan/three_d/out/vect.hpp>
#include <quan/out/acceleration.hpp>
#include <quan/out/angle.hpp>
#include <quan/out/reciprocal_time.hpp>
#include <quan/angle/literal.hpp>
#include <quan/fixed_quantity/operations/atan2.hpp>
#include <quan/length.hpp>
//-----------------------------------
// required for linking the definition of
// quan::angle::pi
#include <quan_matters/src/constant.cpp>
#include <quan_matters/src/angle.cpp>

//-------------------------------------

namespace {
// declare some literal angle functions
   QUAN_ANGLE_LITERAL(rad)
   QUAN_ANGLE_LITERAL(deg)

  // QUAN_QUANTITY_LITERAL(angle,deg);
   QUAN_QUANTITY_LITERAL(acceleration,m_per_s2);

   typedef quan::reciprocal_time_<
      quan::angle::deg 
   >::per_s deg_per_s;

   typedef quan::reciprocal_time_<
      quan::angle::rad 
   >::per_s rad_per_s;

   constexpr inline 
   deg_per_s operator "" _deg_per_s ( long double v)
   {
      return deg_per_s{quan::angle::deg{v}};
   }

   constexpr inline 
   rad_per_s operator "" _rad_per_s ( long double v)
   {
      return rad_per_s{quan::angle::rad{v}};
   }

   quan::three_d::vect<quan::acceleration::m_per_s2>
   constexpr acc_sensor{0.0_m_per_s2,0.0_m_per_s2,-quan::acceleration::g};


   quan::three_d::vect<
      rad_per_s
   > constexpr gyr_sensor{1.0_rad_per_s,0.0_rad_per_s,0.0_rad_per_s};

}

void angle_test1();
void angle_test2();
void deg_modulo_test();
void rad_modulo_test();
void quan_vect_angle_test();

int errors = 0;

int main()
{
   angle_test1();
   angle_test2();
   deg_modulo_test();
   rad_modulo_test();
   quan_vect_angle_test();

   EPILOGUE
}

void angle_test2()
{
   auto constexpr x = 90_deg;

   quan::angle::rad y = x;

   QUAN_CHECK(x == quan::angle::pi / 2);
   QUAN_CHECK(y == quan::angle::pi / 2);

   auto constexpr z = -90_deg;
   QUAN_CHECK(z == -quan::angle::pi / 2);

   typedef decltype (1_rad) int_rad_type;
   static_assert(std::is_same<int_rad_type::value_type,int32_t>::value,"error");

   typedef decltype (1_deg) int_deg_type;
   static_assert(std::is_same<int_deg_type::value_type,int32_t>::value,"error");
   
}

void rad_modulo_test()
{
   QUAN_CHECK( modulo(1.0_rad) == 1_rad);
   QUAN_CHECK( 0_rad == modulo(2 * quan::angle::pi));
   QUAN_CHECK( modulo(2 * quan::angle::pi) == 0_rad); 
   QUAN_CHECK( modulo(4 * quan::angle::pi) == 0_rad); 
   QUAN_CHECK( modulo(-4 * quan::angle::pi) == 0_rad); 
   QUAN_CHECK( modulo(3 * quan::angle::pi) == quan::angle::pi); 
   QUAN_CHECK( modulo(-3 * quan::angle::pi) == -quan::angle::pi); 
   QUAN_CHECK( modulo(0_rad) == 0_rad);
   QUAN_CHECK( modulo(5 * quan::angle::pi) == 180_deg);
   QUAN_CHECK( modulo(-5 * quan::angle::pi) == -180_deg);

   QUAN_CHECK( unsigned_modulo(-5 * quan::angle::pi) == quan::angle::pi);
   QUAN_CHECK( unsigned_modulo(2 * quan::angle::pi) == 0_rad);

   typedef decltype (unsigned_modulo(1_rad)) unsigned_modulo_result_type;
   static_assert(
      std::is_same<
         unsigned_modulo_result_type::value_type,QUAN_FLOAT_TYPE
      >::value
      ,"error"
   );
}

void deg_modulo_test()
{
   QUAN_CHECK( modulo(33_deg) == 33.0_deg); 
   QUAN_CHECK( modulo(393_deg) == 33.0_deg); 
   QUAN_CHECK( modulo(quan::angle_<int>::deg{33}) == quan::angle_<int>::deg{33});
   QUAN_CHECK(signed_modulo(quan::angle::deg{27}) == quan::angle::deg{27});

   QUAN_CHECK( modulo(quan::angle_<int>::deg{370}) == quan::angle_<int>::deg{10});
   QUAN_CHECK( modulo(quan::angle::deg{-370}) == quan::angle::deg{-10});
   QUAN_CHECK( signed_modulo(quan::angle::deg{-370}) == quan::angle::deg{-10});
   QUAN_CHECK( modulo(quan::angle::deg{-376}) == quan::angle::deg{-16});

   QUAN_CHECK(modulo(quan::angle::deg{27}) == quan::angle::deg{27});
   QUAN_CHECK(signed_modulo(quan::angle::deg{181}) == quan::angle::deg{-179});
   QUAN_CHECK(signed_modulo(quan::angle::deg{359}) == quan::angle::deg{-1});
   QUAN_CHECK(unsigned_modulo(quan::angle::deg{359}) == quan::angle::deg{359});
   QUAN_CHECK(modulo(quan::angle::deg{359}) == quan::angle::deg{359});
   QUAN_CHECK(modulo(quan::angle::deg{360}) == quan::angle::deg{0});
   QUAN_CHECK(signed_modulo(quan::angle::deg{360}) == quan::angle::deg{0});
   QUAN_CHECK(modulo(quan::angle::deg{361}) == quan::angle::deg{1}); 
   QUAN_CHECK(signed_modulo(quan::angle::deg{361}) == quan::angle::deg{1});

   QUAN_CHECK(signed_modulo(quan::angle::deg{180}) == quan::angle::deg{180});
   QUAN_CHECK(signed_modulo(quan::angle::deg{181}) == quan::angle::deg{-179});
   QUAN_CHECK(unsigned_modulo(quan::angle::deg{20}) == quan::angle::deg{20});

   QUAN_CHECK(modulo(         quan::angle::deg{-20}) == quan::angle::deg{-20});
   QUAN_CHECK(unsigned_modulo(quan::angle::deg{-20}) == quan::angle::deg{340});

   QUAN_CHECK(         modulo(quan::angle::deg{-430}) == quan::angle::deg{-70});
   QUAN_CHECK(unsigned_modulo(quan::angle::deg{-430}) == quan::angle::deg{290});

   QUAN_CHECK( unsigned_modulo(quan::angle::deg{-90}) == quan::angle::deg{270});
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{360}) == quan::angle::deg{0});
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{361}) == quan::angle::deg{1}); 
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{33}) == quan::angle::deg{33});
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{370}) == quan::angle::deg{10});
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{-370}) == quan::angle::deg{350});
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{-16}) == quan::angle::deg{344});
   QUAN_CHECK( unsigned_modulo(quan::angle::deg{360}) == quan::angle::deg{0});
}


void angle_test1()
{
    quan::angle::deg a{90};
   
    QUAN_CHECK(a.numeric_value() == 90.0);
    a += quan::angle::min{1};
    a += quan::angle::s(1);
    a = 90.0_deg;
    QUAN_CHECK(a == quan::angle::pi/2);

    quan::angle::rad b = a;
    QUAN_CHECK(b == a);

    quan::angle::rad c = quan::angle::deg(180);
    QUAN_CHECK( c == 2 * a);

    QUAN_CHECK(c == quan::angle::pi);
    
    c = quan::angle::min{1};
    QUAN_CHECK ( c == quan::angle::min{1})

    c += quan::angle::min{1};
    QUAN_CHECK ( c == quan::angle::min{2})

    c -= quan::angle::min{1};
    QUAN_CHECK ( c == quan::angle::min{1})
    c = quan::angle::pi;
    QUAN_CHECK ( c == quan::angle::pi)

    a = quan::angle::two_pi;
    QUAN_CHECK ( a == c * 2)
    quan::angle::sr d = b * c;

    QUAN_CHECK((d.numeric_value() == b.numeric_value() * c.numeric_value()))

    
//   b = b + 1; // should wotk and promote to mathematic_angle?
    b *= 1;  
    QUAN_CHECK(b == quan::angle::pi/2)
 
 //   b = b - 1; //should work and promote to math_angle?
    b + c;
    b - c;
    a + b;
    b + a;
    a - b;
    b - a;
 // doesnt work currently by design
 // maybe should work
//    b * a;
//    a * b;
    auto ra = b / c;
    QUAN_CHECK( ( quan::meta::is_angle<
                     quan::meta::strip_cr<decltype(ra)>::type
                  >::value == false)
    )
    b / a;
    a / b;
    b -=c;
    b * c;
    b == c;
    b == a;
    b > c;
    b > a;
    a > b;
    b < c;
    b < a;
    a < b;
    b >= c;
    b >= a;
    a >= b;
    b <= c;
    b <= a;
    a <= b;
    a = atan2(quan::length::m(1),quan::length::m(1));
    quan::angle::rad xx = 0.5;
    QUAN_CHECK(xx.numeric_value()==0.5);
    double sina = sin(a);
    double cosa = cos(a);
    double tana = tan(a);
}

void quan_vect_angle_test()
{

   auto constexpr a1x = norm(acc_sensor);
   auto constexpr ad = quan::pow<1,2>(a1x);

   QUAN_CHECK( ad == quan::acceleration::g)

   QUAN_CHECK( ad == magnitude(acc_sensor) )

   auto constexpr g0x = norm(gyr_sensor);
   auto constexpr gd = quan::pow<1,2>(g0x);
   auto constexpr g1x = magnitude(gyr_sensor);

   QUAN_CHECK( g1x == 1.0_rad_per_s)
   QUAN_CHECK( g1x == gd)
   
   typedef quan::meta::strip_cr<decltype(g1x)>::type g1x_type;

   g1x_type constexpr t{quan::angle::rad{1.0}};

   QUAN_CHECK(t == 1.0_rad_per_s)

}




