// Copyright Andrew Little 2005
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/* 
    This example shows how it is possible to use integer value_types,
    in different units without loss of precision (eg int 1/1000)
    up in the code at compile time the function attempts to decide 
    how to do the adds, subs, divs and muls to give best resolution. 

    NB Only works accurately for coherent-quantities.
    (for incoherent-quantities use a floating point value_type).
*/

#include <quan/out/length.hpp>

int main()
{
    quan::length_<int>::m L1(1);
    quan::length_<int>::mm L2(1000);

    std::cout << L1 + L2 <<'\n';
    std::cout << L2 + L1 <<'\n';
  
    std::cout << L2 - L1 <<'\n';
    std::cout << L1 - L2 <<'\n';
  
    std::cout << L1 / L2 <<'\n';
    std::cout << L2 / L1 <<'\n'; 

    std::cout << L1 * L2 <<'\n';
    std::cout << L2 * L1 <<'\n';   

    quan::length_<int>::mm L3 = L1;
    std::cout << L3 << '\n'; 
    
    quan::length_<int>::m L4 = L2;
    std::cout << L4 <<'\n';

}
