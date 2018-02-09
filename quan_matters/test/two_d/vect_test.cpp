
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
    Preliminary tests on two_d vects
*/

#include <quan_matters/test/test.hpp>
#include <quan/two_d/vect.hpp>
#include <quan/length.hpp>
#include <quan/area.hpp>
#include <quan/fixed_quantity/literal.hpp>

void vect_test1();
void vect_t1_quantity_test1();
void vect_test3();
void vect_valid_binary_op_test();
void complex_test1();
void complex_test2();

int errors = 0;
int main()
{
   vect_test1();
   vect_t1_quantity_test1();
   vect_test3();
   vect_valid_binary_op_test();
   complex_test1();
   complex_test2();

   EPILOGUE
}

namespace {

   QUAN_QUANTITY_LITERAL(length,mm) 
   QUAN_QUANTITY_LITERAL(length,m) 
}

void vect_test3()
{
     typedef quan::length::mm mm;
     typedef quan::two_d::vect<mm> vect;

     constexpr auto v = 20_mm;

     constexpr vect x{v,18.5_mm};

     QUAN_CHECK(x.x == 20.0_mm);
     static_assert(x.x == 20.0_mm,"error");
     static_assert(x.x == 20_mm,"error");

     
}

void vect_test1()
{
    typedef quan::two_d::vect<double> vect;

    constexpr vect c1{20,-20};
    constexpr vect c2{20,-20};
    constexpr vect c3 = c1 - c2;

    static_assert( c3 == vect{},"error");
    constexpr vect c4 = c1 * 2;
    static_assert(c4.x == 40,"error");
    static_assert(c4.y == -40,"error");
    vect v1(1.,2.);
    QUAN_CHECK(v1.x == 1.);
    QUAN_CHECK(v1[0] == 1.);
    QUAN_CHECK(v1.y == 2.);
    QUAN_CHECK(v1[1] == 2.);

    constexpr vect c5 = c4 / 2;
    static_assert( c5 == c1,"error");


#if ! defined QUAN_NO_EXCEPTIONS
    bool caught = false;
    try{
       v1[3] = 1;
    }catch(std::exception & e){
      caught = true;
    }
    QUAN_CHECK(caught == true);
#endif

    vect v2 = v1 * 2;
    QUAN_CHECK(v2.x == 2.);
    QUAN_CHECK(v2.y == 4.);

    vect v3 = v1 + v2;
    QUAN_CHECK(v3.x == 3.);
    QUAN_CHECK(v3.y == 6.);

    vect v4 = v1 - v2;
    QUAN_CHECK(v4.x == -1.);
    QUAN_CHECK(v4.y == -2.);

    
    typedef quan::two_d::vect<int> vect1;

    vect1 v5(1,2);
    vect  v6 = v5 + v1;
    QUAN_CHECK(v6.x == 2.);
    QUAN_CHECK(v6.y == 4.);

    v5 = vect(1,2);
    v6 = vect(1,2);
    v5 += v6;

    QUAN_CHECK(v5.x == 2.);
    QUAN_CHECK(v5.y == 4.);

    auto vq = v5 * 20_mm;

    QUAN_CHECK( (vq == quan::two_d::vect<quan::length::mm>{40_mm,80_mm}) ); 
}

void vect_t1_quantity_test1()
{
    typedef quan::length::mm len;
    typedef quan::two_d::vect<len> vect;
    vect v1(len(1.),len(2.));
    QUAN_CHECK(v1.x.numeric_value() == 1.);
    QUAN_CHECK(v1[0] == len{1.});
    QUAN_CHECK(v1.y.numeric_value() == 2.);

    vect v2 =v1 * 2.;
    QUAN_CHECK(v2.x.numeric_value() == 2.);
    QUAN_CHECK(v2.y.numeric_value() == 4.);
    QUAN_CHECK( v2 != v1)
    QUAN_CHECK( v2 == 2. * v1)
    QUAN_CHECK( v1 == v2 / 2.);

    vect v3 = v1 + v2;
    QUAN_CHECK(v3.x.numeric_value() == 3.);
    QUAN_CHECK(v3.y.numeric_value() == 6.);

    vect v4 = v1 - v2;
    QUAN_CHECK(v4.x.numeric_value() == -1.);
    QUAN_CHECK(v4.y.numeric_value() == -2.);

    
    typedef quan::length_<int>::mm len1;
    typedef quan::two_d::vect<
        len1
    > vect1;

    vect1 v5(len1(1),len1(2));
    vect  v6 = v5 + v1;
    QUAN_CHECK(v6.x.numeric_value() == 2.);
    QUAN_CHECK(v6.y.numeric_value() == 4.);

}

void  vect_valid_binary_op_test()
{
    typedef quan::two_d::vect<double> vect_d;

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::plus,double>::value == false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double,quan::meta::plus,vect_d>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::plus,vect_d>::value == true))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::minus,vect_d>::value == true))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double,quan::meta::minus,vect_d>::value == false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double,quan::meta::minus,vect_d>::value ==false))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::times,double>::value))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double,quan::meta::times,vect_d>::value))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::divides,double>::value))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::times,vect_d>::value) == false)

    typedef quan::length::mm mm;

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::times,mm>::value))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<mm,quan::meta::times,vect_d>::value))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::divides,mm>::value))
   
  // should this work? vect/scalar  ->  1/scalar * vect which seems ok
  //  QUAN_CHECK( (quan::meta::is_valid_binary_op<double,quan::meta::divides,vect_d>::value))
   // QUAN_CHECK( (quan::meta::is_valid_binary_op<mm,quan::meta::divides,vect_d>::value))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::equal_to,vect_d>::value ))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d,quan::meta::not_equal_to,vect_d>::value))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<mm, quan::meta::equal_to,vect_d>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d,quan::meta::not_equal_to,mm>::value == false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::equal_to,mm>::value == false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<mm,quan::meta::not_equal_to,vect_d>::value == false))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::less,double>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double, quan::meta::less,vect_d>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::less,vect_d>::value ==false))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::greater,double>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double, quan::meta::greater,vect_d>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::greater,vect_d>::value ==false))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::less_equal,double>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double, quan::meta::less_equal,vect_d>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::less_equal,vect_d>::value ==false))

    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::greater_equal,double>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<double, quan::meta::greater_equal,vect_d>::value ==false))
    QUAN_CHECK( (quan::meta::is_valid_binary_op<vect_d, quan::meta::greater_equal,vect_d>::value ==false))

}

 


