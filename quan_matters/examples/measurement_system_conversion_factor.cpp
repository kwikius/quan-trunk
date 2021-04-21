

#include <quan/out/mass.hpp>
#include <quan/out/length.hpp>
#include <quan/out/area.hpp>
#include <quan/out/velocity.hpp>
#include <quan/time.hpp>
#include <quan/where.hpp>

/**
  algorithm to work out conversion factor to convert a quantity
  from one measurement_system to another
*/

namespace quan{

    template <
        typename Target,
        typename Source
    >
    inline constexpr
    typename quan::where_<
       quan::meta::dimensionally_equivalent<Target,Source>,
       typename quan::meta::arithmetic_promote<
           typename Target::value_type,
           typename Source::value_type
       >::type
    >::type
    conversion_factor()
    {
       return Target{Source{1}}.numeric_value();
    }

}//quan

/**
* The dimension of the quantity which is the same in both systems
* for simplicity just use an array here
* of integer dimension of Mass, Length, Time
*/
struct dimension {
   static int constexpr numdims = 3;
   dimension(int M,int L,int T)
   : dim{M,L,T}{} 
   int dim[numdims];
};

/**
 * The conversion_factor to convert the numeric value of a quantity expressed in base_units of one measuremnt system
 * to a quantity in base_units of the other using the array of base unit conversion factors.
 * @param q , the exponents of dimension of the quantity to be converted
 * @param base_unit_conversion_factors , an array of conversion factors to convert from a base_unit in the source system
 * to a base unit in the target system
 * @return the conversion_factor k such that for quantities qin, qout , qout.numeric_value = qin.numeric_value * k
 */
double get_conversion_factor( dimension const & q, double const base_unit_conversion_factors[])
{
   double res = 1; // for a dimensioless quantity the factor is 1
 
   for ( int d = 0; d < dimension::numdims; ++d){
      res *= std::pow(base_unit_conversion_factors[d],q.dim[d] );
   }
   return res;
}

#include <iostream>

int main()
{
   // calculate the conversion factors from si to fps base units
   double constexpr base_unit_conversion_factors[] = {
      quan::conversion_factor<quan::length::ft,quan::length::m>(),
      quan::conversion_factor<quan::mass::lb,quan::mass::kg>(),
      quan::conversion_factor<quan::time::s,quan::time::s>()
   };
    
// test it out
   dimension d1{1,0,0}; // a length

   std::cout << get_conversion_factor(d1,base_unit_conversion_factors) << '\n';

   quan::length::m x{1};

   quan::length::ft y = x;

   std::cout << "length = " << y.numeric_value() <<'\n';

   std::cout << "-------------------\n";

   dimension d2{2,0,0}; // an area

   std::cout << get_conversion_factor(d2,base_unit_conversion_factors) <<'\n';

   quan::area::m2 xa{1};

   quan::area::ft2 ya = xa;

   std::cout << "a = " << ya.numeric_value() <<'\n';

   std::cout << "-------------------\n";

   dimension d3{1,0,-1}; // a speed

   std::cout << get_conversion_factor(d3,base_unit_conversion_factors) <<'\n';

   quan::velocity::m_per_s xb{1};

   quan::velocity::ft_per_s yb = xb;

   std::cout << "v = " << yb.numeric_value() <<'\n';

   std::cout << "-------------------\n";
}

