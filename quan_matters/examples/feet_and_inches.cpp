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

