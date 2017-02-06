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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#include <quan/length.hpp>
#include <quan/out/mass.hpp>
#include <quan/volume.hpp>

namespace {

   QUAN_QUANTITY_LITERAL(mass,kg)
   QUAN_QUANTITY_LITERAL(length,ft)
   QUAN_QUANTITY_LITERAL(volume,m3)
}

int main()
{
   using namespace quan;

   auto const m = 1000_kg * ( pow<3>(1.0_ft) / 1_m3 ) ;

   std::cout << "mass = " << m << '\n';

   double const c1 = 1000 * ( pow<3>(12/39.3701) ) ;

   std::cout << "c1 = " << c1 <<'\n';

   /*
      m kg = 1000 kg * (1 ft) ^ 3 / 1 m^3 ;
      cout <~ m , "\n";

   */
}
