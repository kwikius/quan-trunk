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
 
 #if ! defined __MBED__
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/force.hpp>
#include <quan/energy.hpp>

int main()
{
    quan::force::kgf f1(1);
    quan::force::N f2(2);

    quan::force::mN ep(5);
    // These should work!
    compare(f1,f2,ep);
    compare(f2,f1,ep);
    compare(f2,f1);

    quan::energy::kJ e(20.);

    //Error: couldnt find compare
  //  compare(f1,e,ep);

    //Error: couldnt find compare
    compare(f1,e);
}
#endif

