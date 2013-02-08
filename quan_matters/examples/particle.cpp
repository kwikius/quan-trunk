
// Copyright Andy Little, Martin Stennet 2006

/*
    model particle(s) settling under gravity in three dimensions. 
    also includes inter-particle gravity

    This example is designed to show alternate use of quan physical quantities or doubles 
    for quantity types in the same code . 
    The idea is to use the quantities for checking dimensional analysis and then to 
    switch to using doubles for release.
    
    The main body is contained in particle1.cpp which is included twice, once for doubles and once    for quantities.
    
    
*/

#include <quan/macro/cat.hpp>
#include <iostream>
#include <quan/utility/timer.hpp>

#define DATA_STRUCT m_inbuilt
#include "particle1.cpp"
void QUAN_MACRO_CAT(DATA_STRUCT,function)();
#define USE_QUAN
#undef DATA_STRUCT
#define DATA_STRUCT m_quan
#include "particle1.cpp"
void QUAN_MACRO_CAT(DATA_STRUCT,function)();
#undef DATA_STRUCT
#undef USE_QUAN

quan::time::ms do_fun( void (*pf)(), int nloops)
{
    typedef quan::timer<quan::time::ms> timer;
    timer t;
    for(int i = 0; i < nloops; ++i){
         pf();
    }
    t.stop();
    return t();
}

int main()
{
    int const num_loops = 1000;

    auto inbuilt_time = do_fun(m_inbuiltfunction,num_loops);
    auto quan_time =    do_fun(m_quanfunction,num_loops);

    std::cout << "inbuilt timing for " << num_loops << " iters = " << inbuilt_time << '\n';
    std::cout << "quan    timing for " << num_loops << " iters = " << quan_time << '\n';
    std::cout << "ratio = " << (quan_time / inbuilt_time)*100 << "%\n";
    
}
