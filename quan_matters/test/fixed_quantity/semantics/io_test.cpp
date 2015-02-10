
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
    basic test of Input / output
    note :input probably needs work to make pqs input 
    standard conforming

*/
#include <quan_matters/test/test.hpp>
#include <quan/fixed_quantity/io/input.hpp>
#include <quan/out/time.hpp>
#include <quan/out/length.hpp>
#include <fstream>

void  io_test()
{
    quan::time::min t1(1.5);
    quan::time::s t2(22.2);
    quan::length::ft  l1(.222);
    {
        std::ofstream out("data.txt");
        out << t1 << '\n' << t2 << '\n' << l1 ;
    }
    std::ifstream in("data.txt");
    quan::time::min t3;
    quan::time::s t4;
    quan::length::ft  l2(1);
    in >> t3 >> t4 >> l2;    

    QUAN_CHECK(!in.bad());
    QUAN_CHECK(t1 == t3);
    QUAN_CHECK(t2 ==t4);
    QUAN_CHECK(l1 == l2);
 }


