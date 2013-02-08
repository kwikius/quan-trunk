
#include <quan/length.hpp>
#include <quan/out/mass.hpp>
#include <quan/volume.hpp>

int main()
{
   using namespace quan;

   auto const m = quan::mass::kg{1000} *  ( quan::pow<3>(length::ft{1}) / quan::volume::m3{1} ) ;

   std::cout << "mass = " << m << '\n';

   double c1 = quan::pow<3>(12/39.4) * 1000;

   std::cout << " c1 = " << c1 <<'\n';

   /*
      m kg = 1000 kg * (1 ft) ^ 3 / 1 m^3 ;
      cout <~ m , "\n";

   */


}
