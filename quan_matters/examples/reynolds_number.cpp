
#include <iostream>
#include <quan/pressure.hpp>
#include <quan/time.hpp>
#include <quan/density.hpp>
#include <quan/out/velocity.hpp>
#include <quan/out/length.hpp>
#include <map>

/*
Reynolds number
      {\displaystyle \mathrm {Re} ={\frac {\rho uL}{\mu }}={\frac {uL}{\nu }}}

    ρ is the density of the fluid (SI units: kg/m3)
    u is the flow speed (m/s)
    L is a characteristic linear dimension (m) (see the below sections of this article for examples)
    μ is the dynamic viscosity of the fluid (Pa·s or N·s/m2 or kg/(m·s))
    ν is the kinematic viscosity of the fluid (m2/s).

    Re = u * L / ν
*/

namespace {

    // Todo interpolate density and viscosity as a function of temperature
    std::map<std::string,quan::density::kg_per_m3> density_map= {
         {"water",quan::density::kg_per_m3{1000}},
         {"air",quan::density::kg_per_m3{1.225}}
    };

    std::map<std::string,decltype(quan::pressure::Pa{} * quan::time::s{}) > viscosity_map = {
         {"water",quan::pressure::mPa{1} * quan::time::s{1} * 1.0518}, // at 18 degrees celsius
         {"air",quan::pressure::uPa{1} * quan::time::s{1} * 18.03} // at 18 degrees celsius
    };

    // These macros define quantity literals as needed
    // https://en.cppreference.com/w/cpp/language/user_literal

    QUAN_QUANTITY_LITERAL(velocity, m_per_s)
    QUAN_QUANTITY_LITERAL(velocity, knot)
    QUAN_QUANTITY_LITERAL(velocity, mi_per_h)

    QUAN_QUANTITY_LITERAL(length, mm)
    QUAN_QUANTITY_LITERAL(length, m)

}

double reynolds_number(std::string const & material,quan::length::m const & L, quan::velocity::m_per_s const & u)
{
   auto const viscosity = viscosity_map[material];
   auto const density = density_map[material];
   auto const kinematic_viscosity = viscosity / density;
   return  u * L / kinematic_viscosity;
}

int main()
{
#if 1
    auto  medium = "water";
    auto  L = 50.0_mm;
    auto  u = 1.0_m_per_s;
#else
    auto  medium = "air";
    auto  L = 0.1_m;
    auto  u = 10.0_mi_per_h;
#endif

    std::cout << "At chord of " << L << " and velocity of " << u << " in " << medium << ", RE = " << reynolds_number(medium,L,u) << '\n';

}
