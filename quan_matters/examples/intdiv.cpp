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
