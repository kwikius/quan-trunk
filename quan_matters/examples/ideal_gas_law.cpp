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

/*
gas constant using quantities and doubles
*/

namespace {

   QUAN_QUANTITY_LITERAL(temperature,K)
   QUAN_QUANTITY_LITERAL(pressure,Pa)
   QUAN_QUANTITY_LITERAL(length,m)

}

#define let constexpr auto

namespace {
   let gas_constant_R = 8.3145;
}

void f_doubles()
{
   let     pi = quan::constant::pi;
   let     T = 310.0;
   let     P = 1.01325e5;
   let     r = 0.5e-6;

   double  V = 4.0 / 3.0 * pi * std::pow(r,3);
   double  subst = P * V /(gas_constant_R * T);

   std::cout << subst << '\n';
}

void f_quantities()
{
   let                    pi = quan::constant::pi;
   let                    T = 310.0_K;
   let                    P = 1.01325e5_Pa;
   let                    r = 0.5e-6_m;

   quan::volume::m3       V = 4.0 / 3.0 * pi * quan::pow<3>(r);
   quan::substance::mol   subst = P * V /(quan::gas_constant::R * T);

   std::cout << subst << '\n';
}

int main()
{  
   std::cout << "--------- doubles ---------\n";

   f_doubles();

   std::cout << "-------- quantities ---------\n";

   f_quantities();

}
