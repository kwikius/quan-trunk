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

/*
    calculate very small force due to gravity
*/

#include <quan/out/length.hpp>
#include <quan/out/density.hpp>
#include <quan/out/mass.hpp>
#include <quan/out/force.hpp>
#include <quan/constants/constant.hpp>
#include <quan/fixed_quantity/literal.hpp>
#include <quan/three_d/sphere_volume.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/gravitational_constant.cpp>
#include <quan_matters/src/constant.cpp>
#else
#include <quan/constants/gravitational_constant.hpp>
#endif

namespace {

   // macros to create UDLs for quantities as required
   QUAN_QUANTITY_REAL_LITERAL(length, km);
   QUAN_QUANTITY_REAL_LITERAL(length, pc);
   QUAN_QUANTITY_REAL_LITERAL(density, kg_per_m3);
   QUAN_QUANTITY_REAL_LITERAL(mass, kg);

}

int main()
{
    using quan::constant;
    using quan::gravitational_constant;
    using quan::length;
    using quan::density;
    using quan::mass;
    using quan::force;
    using quan::pow;

    std::cout.precision(5);

    auto constexpr planet_radius = 6400.0_km;
    auto constexpr planet_sphere = quan::three_d::sphere<length::km>{planet_radius};

    auto constexpr planet_density = 5487.0_kg_per_m3;
    mass::kg constexpr planet_mass = get_volume( planet_sphere ) * planet_density;

    std::cout << "mass of planet is roughly " << planet_mass <<'\n';

    // An object...
    auto constexpr object_mass = 1.0_kg;

    // ...on the planet surface
    force::N constexpr exerted_force_at_surface 
       = (object_mass * planet_mass * gravitational_constant::G)
       / pow<2>(planet_radius);

    std::cout << "force on object at surface is roughly " << exerted_force_at_surface <<'\n';

    // ...and a long way away
   //2.074098464e14 = 64e13/3.085678); // 1 pc =  3.085678e16 m
    auto constexpr object_distance = 2.074098464e14_pc;
   
    force::yN constexpr force_at_distance = 
      (object_mass * planet_mass * gravitational_constant::G)
           / pow<2>(object_distance);

    std::cout << "force on object at a distance of " << object_distance 
              << " is roughly " << force_at_distance << '\n';
}

