//----------------------------------------
// Copyright Andrew Little 2007
//
 
 
 
//
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
