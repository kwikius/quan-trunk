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
 along with this program. If not, see http://www.gnu.org/licenses.
*/


#include <quan_matters/test/test.hpp>
#include <quan/three_d/quat.hpp>
#include <quan/three_d/vect.hpp>
#include <quan/length.hpp>
#include <quan/current.hpp>

/*
    Basic go-no-go of quan::three_d::quat
*/

void quat_test()
{
    // The use of these types is unorthodox, but it shows that
    // the quat is independent of the type of elements!
    // IOW its only the ratio between them that matters
    typedef quan::current::A type1;
    typedef quan::length::m type2;
    
    typedef quan::three_d::quat<type1> quat;
    typedef quan::three_d::vect<type2> vect;
    quat q(type1(2.5),type1(3.2),type1(-4.8),type1(.5));
    vect v(type2(2),type2(.5),type2(-20));
    vect v1 = q * v;
    vect v2 = multiply(q,v);
    // multiply is the previous version of operator*(quat,vect) 
    // just to check the result is equivalent
    // The calcs are done differently, with division on a different value
    // so there will be some difference in result
    // accuracy. Thats why I use a tolerance bucket:
    
    type2 epsilon(FP_MAX_DIFFERENCE);
    QUAN_CHECK( 
        (compare(v1.x,v2.x,epsilon)==0)
     && (compare(v1.y,v2.y,epsilon)==0)
     && (compare(v1.z,v2.z,epsilon)==0)
    );
}

#if 0
int errors = 0;
int main()
{
   quat_test();
   EPILOGUE
}
#endif



