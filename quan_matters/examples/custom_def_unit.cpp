//----------------------------------------
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
    Overload units output for SI units of energy_per_area_time_length
*/

// overload shown here in the source for convenience
#include <quan/out/energy_per_area_time_length.hpp>

namespace quan{ namespace meta{

//####################
// change to if(0) to see default output included with the implementation
#if (1)
//###################

// where ConvFactor is a model of SI Conversion Factor

   template <typename ConvFactor>
   inline
   typename quan::where_<
      is_si<ConvFactor>,
      std::ostream&
   >::type
    operator << ( 
       std::ostream & os,
       unit<
          energy_per_area_time_length::abstract_quantity,
          ConvFactor 
        >const & )
   {

   // (details of the si conversion factors are in <quan/meta/si_unit.hpp>)

      os << "W.m-2." << quan::meta::si_unit::prefix<ConvFactor>::template symbol<char>() << "m-1";
      return os;
   }

#endif

}}//quan::meta

int main()
{
   quan::energy_per_area_time_length::uW_per_m2_per_m var1(1);
   std::cout << var1 <<'\n';
// show base unit
   std::cout << quan::energy_per_area_time_length::W_per_m2_per_m(20) <<'\n';

//test other unit...
   quan::energy_per_area_time_length::kW_per_m2_per_m var3(12345);
   std::cout << var3 <<'\n';
}
