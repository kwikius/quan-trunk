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

/*
     some basic electronics calcs
*/

#include <quan/out/voltage.hpp>
#include <quan/out/resistance.hpp>
#include <quan/out/current.hpp>
#include <quan/out/time.hpp>
#include <quan/out/power.hpp>
#include <quan/out/energy.hpp>

namespace {
   QUAN_QUANTITY_LITERAL(voltage,V)
   QUAN_QUANTITY_LITERAL(resistance,kR)
   QUAN_QUANTITY_LITERAL(time,s)
}

int main()
{
    auto                    v = 5.0_V;
    auto                    r = 1.0_kR;

    quan::current::mA       i = v/r;

    auto                    t = 1.0_s;

    quan::power::mW         w = quan::pow<2>(v)/r;
    quan::energy::mJ        e = w * t;
    std::cout
       << "A current of " << i
       << "\nthrough a voltage of " << v
       << "\nrequires a resistance of " << r
       << "\nand produces "  << w << " of heat\n";
    std::cout
       << "total energy used in " << t
       << " is " <<  e  << '\n';
}
