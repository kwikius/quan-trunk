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

// Calculation of amount of substance in a gas using gas constant

#include <quan/temperature.hpp>
#include <quan/pressure.hpp>
#include <quan/length.hpp>
#include <quan/volume.hpp>
#include <quan/out/substance.hpp>


#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/constant.cpp>
#include <quan_matters/src/gas_constant.cpp>
#else 
// pi etc
#include <quan/constants/constant.hpp>
// dimensionally correct gas_constant
#include <quan/constants/gas_constant.hpp>
#endif

void f1()
{
   
    using quan::gas_constant;
    using quan::pow;
    using quan::temperature;
    using quan::pressure;
    using quan::length;
    using quan::volume;
    using quan::substance;
    double const & pi = quan::constant::pi;

    temperature::K  T(310);
    pressure::Pa    P(1.01325e5);
    length::m       r(0.5e-6);
    volume::m3      V = 4.0 / 3.0 * pi * pow<3>(r);
    substance::mol  subst = P * V /(gas_constant::R * T);
    std::cout << subst << '\n';
}

double const gas_constant_R(8.3145);
void f2()
{
    using quan::pow;
    using quan::gas_constant;

    double const & pi = quan::constant::pi;
    double  T(310);
    double     P(1.01325e5);
    double      r(0.5e-6);
    double      V = 4.0 / 3.0 * pi * pow<3>(r);
    double  subst = P * V /(gas_constant_R * T);
    std::cout << subst << '\n';

}

int main()
{  
 f1();
 f2();
}
