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
#include <quan/out/angle.hpp>
#include <quan/fixed_quantity/operations/atan2.hpp>
#include <quan/length.hpp>
//-----------------------------------
// required for linking the definition of
// quan::angle::pi
#include <quan_matters/src/constant.cpp>
#include <quan_matters/src/angle.cpp>

//-------------------------------------

#if 0
void angle_test1();
int errors = 0;

int main()
{
    angle_test1();
   EPILOGUE
}
#endif

void angle_test1()
{
    quan::angle::deg a(90);
    a += quan::angle::min  (1);
    a += quan::angle::s(1);
    quan::angle::rad b = a;
    quan::angle::rad c = quan::angle::deg(180);
    c = quan::angle::min{1};

    c += quan::angle::min{1};
    c -= quan::angle::min{1};
    c = quan::angle::pi;
    a = quan::angle::two_pi;
    quan::angle::sr d = b * c;
//   b = b + 1; // should wotk and promote to mathematic_angle
    b *= 1;  
 //   b = b - 1; //should work and promote to math_angle
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
    b / c;
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
    double sina = sin(a);
    double cosa = cos(a);
    double tana = tan(a);
}


