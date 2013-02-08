// Copyright Andrew Little 2006
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/out/length.hpp>
#include <quan/fixed_quantity/operations/ceil_floor.hpp>

/*
    split a length in feet into feet and inches
*/

int main()
{
    quan::length::ft L1(1.25);
    std::cout <<  L1 << " = ";
    quan::length_<int>::ft L2 = floor(L1);
    std::cout << L2 ;
    quan::length_<int>::in L3 = L1 - L2;
    std::cout << " " << L3 <<'\n';
}

