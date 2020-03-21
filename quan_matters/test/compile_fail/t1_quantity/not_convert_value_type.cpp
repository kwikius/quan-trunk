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
 
#if ! defined __MBED__ 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan_matters/test/utility/udt.hpp>
#include <quan/time.hpp>
#include <quan/acceleration.hpp>
#include <quan/velocity.hpp>

/*
    t1_quantity value_type must be implicitly convertible
*/

//using my::udt;

int main()
{
    typedef my::udt<int> udti;
    typedef my::udt<double> udtd;
    udti udt1, udt2;
    udtd udt3, udt4;
// check udt adds work ok
    udt1 + udt2;
    udt3 + udt4;
    udt1 + udt3;
    
    quan::velocity_<udti >::m_per_s      v1( udti(1) );
    quan::velocity_<udti >::m_per_s      v2( udti(1) );

    typedef quan::meta::binary_op<
        quan::velocity_<udti>::m_per_s,
        quan::meta::plus,
        quan::velocity_<udti>::m_per_s
    >::type result;
    v1 + v2;
    std::cout << typeid(result).name() << '\n';
// cross value_type udt
    quan::velocity_<udtd >::mm_per_s      v3( udtd(1) );
    v1 + v3;
 
    quan::velocity::mm_per_s   v4(1); 
//###################################
// should fail here /////////////////
    v4 + v1;
/////////////////////////////
//#################################
}

#endif

