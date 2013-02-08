// Copyright Andrew Little 2005
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
