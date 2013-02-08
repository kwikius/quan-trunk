/*

 Copyright (c) 2012 Andy Little

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
 
*/

#include <quan/length.hpp>
#include <quan/force.hpp>
#include <quan/volume.hpp>
#include <quan/mass.hpp>
#include <quan/density.hpp>
#include <quan/acceleration.hpp>

//!-!-!start-example
   struct quan_box {
      quan::length::m length;
      quan::length::m width;
      quan::length::m height;
      quan::density::kg_per_m3 density;

      quan::force::N weight()
      {
         quan::volume::m3 volume = length * width * height;
         quan::mass::kg mass = density * volume;
         return mass * quan::acceleration::g;
      }
   };
//!-!-!end-example


