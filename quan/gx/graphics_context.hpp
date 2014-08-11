#ifndef  QUAN_GX_GRAPHICS_CONTEXT_HPP_INCLUDED
#define  QUAN_GX_GRAPHICS_CONTEXT_HPP_INCLUDED

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

#include <quan/gx/primitives/simple_line.hpp>
#include <quan/gx/primitives/polyline.hpp>
#include <quan/gx/primitives/box.hpp>
#include <quan/gx/primitives/simple_text.hpp>
#include <quan/gx/primitives/circle.hpp>
#include <quan/gx/static_rgb_color.hpp>

#include <quan/two_d/vect.hpp>

namespace quan{ namespace gx{

   template <typename LengthType>
   struct graphics_context{
 
      graphics_context(){}
      virtual ~graphics_context(){}
      typedef LengthType length_type;

      virtual void draw_line(primitives::simple_line<length_type> const & ) const= 0;
      virtual void draw_polyline(primitives::polyline<length_type> const & ) const= 0;
      virtual void draw_box(primitives::box<length_type> const & ) const= 0;
      virtual void draw_text(primitives::simple_text<length_type> const & ) const= 0;
      virtual void draw_circle(primitives::circle<length_type> const & ) const= 0;

   };

}}

#endif
