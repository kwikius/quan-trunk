
#include <quan/out/length.hpp>
#include <quan/out/area.hpp>
#include <quan/out/volume.hpp>
#include <quan/utility/show_conversion_factor_working.hpp>
#include <quan/fixed_quantity/operations/make_coherent.hpp>

/*
   Sometimes it is usefult to treat incoherent quantities as coherent quantities.
   The make_coherent function turns incoherent quantities into coherent quantities.
*/

namespace quan{

   // require custom output functions
   inline std::ostream & operator<< (std::ostream & os, decltype(make_coherent(quan::length::fathom{})) const & q)
   {
      return os << q.numeric_value() << "fathom(coherent)";
   }
   
   
   inline std::ostream & operator<< (std::ostream & os, decltype(quan::pow<1,3>(make_coherent(quan::length::fathom{}))) const & q)
   {
      return os << q.numeric_value() << " fathom(coherent)^(1/3)";
   }
}

int main()
{

   std::cout.precision(20);
   quan::length::fathom constexpr v{1000};

   std::cout << "standard fathom : " << v << "\n\n";

   auto va = quan::pow<1,3>(v);

   std::cout << "cube root of standard fathom (quan semantic) : " << va << "\n\n";

   auto  v1 = make_coherent(v);

   std::cout << "coherent fathom : " << v1 <<  "\n\n";

   auto v2 = quan::pow<1,3>(v1);

   std::cout << "cube root of coherent fathom : " << v2 <<  "\n\n";

}