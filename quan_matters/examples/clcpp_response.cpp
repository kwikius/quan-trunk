
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

// See <QUAN_ROOT/quan_matters/index.html> for documentation.

#include <quan/config.hpp>
#include <quan/out/length.hpp>
#include <quan/out/area.hpp>
#include <quan/out/volume.hpp>
#include <quan/out/time.hpp>
#include <string>

// Quan can adopt the single type approach
void f_first()
{
    std::string str = " min" "()";
    typedef quan::length::km distance;
    typedef quan::time::s time;

    distance const km(1.0); 
    distance const miles = quan::length::mi(1);
    time const sec(1.0); 

    time const min = quan::time::min  (1);
    time const hr = quan::time::h(1); 

    // However it is probably not optimal for output:

    std::cout << "pqs can provide output using a single type:\n\n"; 
    std::cout << km << '\n';
    std::cout << miles << '\n';
    std::cout << sec << '\n';
    std::cout << min << '\n';
    std::cout << hr  <<  "\n\n";;
}

void f_pqs()
{
    using quan::length;
    using quan::time;

    length::km km(1);

// for convenience...
    typedef length distance;

    distance::mi miles(1);

// units symbols are based on those in the SI
    std::cout.precision(6);
    time::s   sec(1);
    time::min min (1);
    time::h   hr(1);

    std::cout << "but also provide output for each unit:\n\n"; 
    std::cout << km << '\n';
    std::cout << miles << '\n';
    std::cout << sec << '\n';
    std::cout << min << '\n';
    std::cout << hr  << "\n\n";

    length::m  meter(1);
    std::cout << "pqs has a wide range of pre-defined units,"
    " for consistency and repeatability across applications:\n\n";

    std::cout << meter << '\n' ;
   
    std::cout << " = " << length::AU(meter) << '\n'; 
    std::cout << " = " << length::angstrom(meter) << '\n'; 
    std::cout << " = " << length::ch(meter) << '\n'; 
    std::cout << " = " << length::fathom(meter) << '\n'; 
    std::cout << " = " << length::fathom_us(meter) << '\n';
    std::cout << " = " << length::ft(meter) << '\n'; 
    std::cout << " = " << length::ft_us(meter) << '\n';  
    std::cout << " = " << length::in(meter) << '\n'; 
    std::cout << " = " << length::l_y_(meter) << '\n';  
    std::cout << " = " << length::mi(meter) << '\n'; 
    std::cout << " = " << length::naut_mile(meter) << '\n'; 
    std::cout << " = " << length::pc(meter) << '\n'; 
    std::cout << " = " << length::pica_comp(meter) << '\n';  
    std::cout << " = " << length::pica_prn(meter) << '\n'; 
    std::cout << " = " << length::point_comp(meter) << '\n'; 
    std::cout << " = " << length::point_prn(meter) << '\n'; 
    std::cout << " = " << length::rd(meter) << '\n'; 
    std::cout << " = " << length::yd(meter) << '\n'; 
    
}
void calcs_comparison()
{
  //  std::cout.setf(std::ios_base::fixed/*,std::ios_base::floatfield*/);
    std::cout.precision(20);
    std::cout << "\nA distinct unit for each type";
    std::cout << " is efficient and accurate when adding"
    " two values of the same very big or very small type:\n\n";

    typedef float real;
    using quan::length_;

    length_<real>::fm L1A(2);
    length_<real>::fm L2A(3);
    length_<real>::fm LrA = L1A + L2A;

    std::cout << L1A << " + " << L2A << "\n = " << LrA << "\n\n";

    std::cout << "The single unit method must convert large"
    " or small values in other units to meters."
    " This is both inefficient and inaccurate\n\n";

    length_<real>::m L1B = L1A;
    length_<real>::m L2B = L2A;
    length_<real>::m LrB = L1B + L2B;

    std::cout << L1B << " + " << L2B << "\n = " << LrB << "\n\n";

    std::cout << "In multiplication and division:\n\n";
    using quan::area_;
    area_<real>::fm2 ArA = L1A * L2A ;
    std::cout << L1A << " * " << L2A << "\n = " << ArA << "\n\n";
    std::cout <<"similar problems arise\n\n";
    area_<real>::m2 ArB = L1B * L2B;
    std::cout << L1B << " * " << L2B << "\n = " << ArB << '\n';

}
int main()
{
   f_first();
   f_pqs();
   calcs_comparison();
}
