#ifndef QUAN_GX_DEVICE_WINDOW_HPP_INCLUDED
#define QUAN_GX_DEVICE_WINDOW_HPP_INCLUDED
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

#include <quan/two_d/vect.hpp>
#include <quan/length.hpp>
#include <quan/reciprocal_length.hpp>

namespace quan{ namespace gx{
  
   struct device_window{
      // current size of client area of pane in px
      virtual quan::two_d::vect<int>  get_size_in_px() const = 0;
      // current size of client area of pane in mm
      virtual quan::two_d::vect<quan::length::mm> get_size_in_mm() const = 0;

      quan::two_d::vect<quan::reciprocal_length::per_mm> get_px_per_mm() const
      {
           quan::two_d::vect<quan::length::mm> mm = get_size_in_mm();
           quan::two_d::vect<int> px = get_size_in_px();
           return quan::two_d::vect<quan::reciprocal_length::per_mm>{
               px.x/mm.x,
               px.y/mm.y
           };
      } 

      quan::two_d::vect<quan::length::mm> get_mm_per_px() const
      {
           quan::two_d::vect<quan::length::mm> mm = get_size_in_mm();
           quan::two_d::vect<int> px = get_size_in_px();
           return quan::two_d::vect<quan::length::mm>{
               mm.x/px.x,
               mm.y/px.y
           };
      }
      
      virtual ~device_window(){}
   };

}}

#endif
