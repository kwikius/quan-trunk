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

//


 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

/*
    Extended implementation of the pq_box example dicussed in the abstract
*/

#include <quan/acceleration.hpp>
#include <quan/out/length.hpp>
#include <quan/out/volume.hpp>
#include <quan/out/time.hpp>
#include <quan/out/force.hpp>
#include <quan/out/mass.hpp>
#include <quan/out/density.hpp>

#include <quan_matters/src/acceleration_g.cpp>

class Box{
public:
    Box(quan::length::m const & l,
        quan::length::m const& w,
        quan::length::m const& h
    ): length{l},width{w},height{h}{}

    quan::force::N filled_weight()const
    {
        quan::volume::m3 volume
        = this->length * this->width * this->height;
        quan::mass::kg mass = this->contents.density * volume;
        return mass * quan::acceleration::g;
    }
    quan::length::m fill_level(quan::mass::kg const & measured_mass)const
    {
        return this->height
        * (measured_mass * quan::acceleration::g)
        / filled_weight();
    }
    struct contents{
        contents(){}
        quan::density::kg_per_m3 density;
    }contents;
    void set_contents_density(quan::density::kg_per_m3 const & density_in)
    {
        this->contents.density = density_in;
    }

    quan::length::m const length;
    quan::length::m const width;
    quan::length::m const height;

};
//
int main()
{
   using quan::length;
   using quan::time;
   using quan::mass;
   using quan::density;

   auto box = Box{length::mm{1000}, length::mm{500}, length::mm{200}};
   box.set_contents_density(density::kg_per_m3{1000});

   auto fill_time = time::s{200};      // time since starting fill
   auto measured_mass = mass::kg{20};  // measured mass at fill_time

   std::cout << "fill level at " << fill_time << " = "
   << box.fill_level(measured_mass) <<'\n';
   std::cout << "input flow rate after " << fill_time
   << " = " << measured_mass / fill_time <<'\n';
   std::cout << "fill level rate = "
   << box.fill_level(measured_mass) / fill_time <<'\n';
   time::s fill_time_left
   = (box.height / box.fill_level(measured_mass) - 1) * fill_time ;
   std::cout << "fill time left = " << fill_time_left <<'\n';

}
