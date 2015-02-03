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
    very simple fixed_quantity stream input demo. after C++ 3rd Ed 621.
*/

#include <quan/fixed_quantity/io/input.hpp>
#include <quan/out/length.hpp>

int main()
{  
    quan::length::in L;
    while (std::cin){
        std::cout << " value of L is : " <<  L <<'\n';
        std::cout << "enter length in inches ie 12 in\n...or bad units to quit\n";
        std::cin >> L;
        if (std::cin.bad()){
            std::cout << "bad input... quitting\n";
        }
        else{
            std::cout << "value is now : " << L <<'\n';
        }
    }
}
