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
 along with this program. If not, see http://www.gnu.org/licenses.
*/

#include <quan/gx/wxwidgets/graphics_context.hpp>
#include <quan/max.hpp>
#include <quan/gx/primitives/circle.hpp>
#include <quan/gx/primitives/polyline.hpp>
#include <quan/gx/rgb_color.hpp>
#include <quan/gx/abc_color.hpp>
#include <quan/constants/constant.hpp>
#include <quan/angle.hpp>
#include <quan/max.hpp>
#include <quan/min.hpp>

// decide on pixel length or screen size in length units
//for minimum seg

void quan::gx::wxwidgets::graphics_context::draw_circle(
   quan::gx::primitives::circle<mm> const & circle
) const
{
   // make this settable...
   const mm view_segment_length{2};
   const int32_t max_segments = 100;
   const int32_t min_segments = 6;
   mm const r =  circle.get_radius();
   mm const view_circle_perim = (r * this->m_scale) * 2 * quan::constant::pi;

   int32_t const num_segments = quan::max(
         quan::min(static_cast<int32_t>(view_circle_perim / view_segment_length),max_segments),
         min_segments
   );
   quan::gx::primitives::polyline<mm> poly{circle.get_line_width(),circle.get_color()};
   
   typedef quan::gx::primitives::circle<mm>::vect cvect;
   cvect centre = circle.get_center();
   poly.push_back(cvect{r,mm{0}} + centre);
   for ( int32_t i = 1; i < num_segments; ++i){
      quan::angle::rad const angle = (2 * quan::angle::pi  * i )/num_segments;
      mm const x = quan::cos(angle) * r + centre.x;
      mm const y = quan::sin(angle) * r + centre.y;
      poly.push_back({x,y});
   }
   poly.push_back(cvect{r,mm{0}} + centre);
   this->draw_polyline(poly);
}

