
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

#include <quan_matters/test/test.hpp>
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>

#if 1

void dimensionally_equivalent_test();
int errors =0;
int main()
{
   dimensionally_equivalent_test();
   EPILOGUE
}
#endif

void dimensionally_equivalent_test()
{
    typedef quan::meta::binary_op<
        quan::length::m,
        quan::meta::divides,
        quan::time::s
    >::type vely1;
    bool val1 = quan::meta::dimensionally_equivalent<
        vely1,
        quan::velocity::m_per_s
    >::value;
    QUAN_CHECK(val1);

    bool val2 = quan::meta::dimensionally_equivalent<
        vely1::unit,
        quan::velocity::m_per_s::unit
    >::value;
    QUAN_CHECK(val2);

   
  
    bool val4 = quan::meta::dimensionally_equivalent<
        quan::length::m,
        quan::velocity::m_per_s
    >::value;
    QUAN_CHECK(val4 == false);

    bool val5 = quan::meta::dimensionally_equivalent<
        quan::length::m::unit,
        quan::velocity::m_per_s::unit
    >::value;
    QUAN_CHECK(val5 ==false);
}

