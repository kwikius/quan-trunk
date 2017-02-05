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
#include <sstream>
#include <string>
#include <quan/utility/timer.hpp>

namespace{
   QUAN_QUANTITY_LITERAL(time,s)
}

int main()
{  
   constexpr char const* const inputs[] = { "12 in", "20 in", "20.1 in", "24 in","0.1 in", "-12 in"};

   quan::length::in L;

   auto constexpr wait_time = 1_s;

   for(auto str : inputs){
      quan::timer<quan::time::s> t;

      while ( t() < wait_time){ asm volatile ("nop":::);}

      std::istringstream in{str};
      in >> L;

      if (in.bad()){
         std::cout << "bad input... quitting\n";
         break;
      }
      else{
         quan::length::cm cm = L;
         std::cout << "value is now : " << L << " ( or " << cm << ")\n";
      }
   }
   return EXIT_SUCCESS;
}
