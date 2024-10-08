

#include <quan/config.hpp>
#if ! defined QUAN_MBED_ONLINE_COMPILER

#include <quan/out/length.hpp>
#include <quan/out/area.hpp>
#include <quan/out/volume.hpp>
#include <quan/utility/show_conversion_factor_working.hpp>
#include <quan/fixed_quantity/operations/make_coherent.hpp>

/*
   The make_coherent function turns incoherent quantities into coherent quantities.
*/

namespace quan{

   // require custom output functions
   inline std::ostream & operator<< (std::ostream & os, decltype(make_coherent(quan::length::fathom{})) const & q)
   {
      return os << q.numeric_value() << " fathom(coherent)";
   }
   
   inline std::ostream & operator<< (std::ostream & os, decltype(quan::pow<1,3>(make_coherent(quan::length::fathom{}))) const & q)
   {
      return os << q.numeric_value() << " fathom(coherent)^(1/3)";
   }

   inline std::ostream & operator<< (std::ostream & os, decltype(quan::pow<101,3>(make_coherent(quan::length::fathom{}))) const & q)
   {
      return os << q.numeric_value() << " fathom(coherent)^(101/3)";
   }

}

int main()
{

   std::cout.precision(20);
   quan::length::fathom constexpr v{1000};

   std::cout << "standard fathom : " << v << "\n\n";

   auto constexpr va = quan::pow<1,3>(v);

   std::cout << "cube root of standard fathom (quan semantic) : " << va << "\n\n";

   auto constexpr v1 = make_coherent(v);

   std::cout << "coherent fathom : " << v1 <<  "\n\n";

   auto constexpr v2 = quan::pow<1,3>(v1);

   std::cout << "cube root of coherent fathom : " << v2 <<  "\n\n";

   auto constexpr vN = quan::pow<101,3>( v1 );

   std::cout << "raise to power 101/3 : "  << vN  <<'\n';

   auto constexpr vNN = quan::pow<3,101>(vN);

   std::cout << "and back : " << vNN <<'\n';

}
#else
#include <iostream>
int main()
{
   std::cout << "not supported on mbed compiler\n";
}

#endif
