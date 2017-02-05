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
    calculate very small force due to gravity
*/

#include <quan/out/length.hpp>
#include <quan/out/density.hpp>
#include <quan/out/mass.hpp>
#include <quan/out/force.hpp>
#include <quan/constants/constant.hpp>

#ifndef QUAN_DEFINE_PHYSICAL_CONSTANTS_IN_HEADERS
#include <quan_matters/src/gravitational_constant.cpp>
#include <quan_matters/src/constant.cpp>
#else
#include <quan/constants/gravitational_constant.hpp>
#endif

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
    length::km         const planet_radius(6400); //roughly !
    density::kg_per_m3 const planet_density(5487); // roughly!
    mass::kg const planet_mass = (4.0/3.0)* constant::pi * pow<3>(planet_radius) * planet_density;

    std::cout << "mass of planet is roughly " << planet_mass <<'\n';

    //an object
    mass::kg const object_mass(1);

    // ...on the planet surface
    force::N const exerted_force_at_surface 
       = (object_mass * planet_mass * gravitational_constant::G)
       / pow<2>(planet_radius);

    std::cout << "force on object at surface is roughly " 
    << exerted_force_at_surface <<'\n';

    // ...and a long way away
    length::pc object_distance(64e13/3.085678); // pc =  3.085678e16 m

    std::cout << "force on object at " << object_distance << " is roughly "
       << force::yN((object_mass * planet_mass * gravitational_constant::G)
           / pow<2>(object_distance)) <<'\n';
}

