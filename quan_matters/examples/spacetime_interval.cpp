
#include <quan/length.hpp>
#include <quan/time.hpp>
#include <quan/velocity.hpp>
#include <quan/out/length.hpp>
#include <quan/sign.hpp>
#include <quan/abs.hpp>

namespace {
   quan::velocity::m_per_s constexpr c{1};
}


auto spacetime_interval(quan::length::m const & d, quan::time::s const& t)
{
   auto const sqd = quan::pow<2>(c * t) - quan::pow<2>(d) ;
   return sqd;
  // return quan::pow<1,2>( abs(sqd) ) * sign(sqd);
}

int main()
{  
   auto interval = spacetime_interval(quan::length::m{10},quan::time::s{200});
   
   std::cout << interval <<'\n';

}



