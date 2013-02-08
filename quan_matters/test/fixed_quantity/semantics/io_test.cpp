
// Copyright Andrew Little 2005

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


