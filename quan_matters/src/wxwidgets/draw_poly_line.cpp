
#if ! defined __MBED__
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
#include <quan/gx/primitives/polyline.hpp>
#include <quan/gx/rgb_color.hpp>
#include <quan/gx/abc_color.hpp>

void quan::gx::wxwidgets::graphics_context::draw_polyline(
   quan::gx::primitives::polyline<mm> const & polyline
) const
{

   auto length =  polyline.get_num_elements();

   if ( length < 2){
      return;
   }
   //TODO assert that colour is not null
   auto rgb_col = polyline.get_color()->get_uchar_rgb();
   wxColour wx_colour{rgb_col.red,rgb_col.green,rgb_col.blue};
  

   auto px_line_width = quan::max(
      quan::arithmetic_convert<int>(
         polyline.get_line_width() * m_scale * m_px_per_mm.x
      ),
      1
   );
   wxPen pen(wx_colour,px_line_width);

   m_pDC->SetPen(pen);

   auto const & vect = polyline.get_points();
   for ( size_t i = 0; i < (length-1); ++i){
      ll_draw_line(quan::two_d::line<vect2_mm>{vect[i],vect[i+1]});
   }
   m_pDC->SetPen(wxNullPen);

}

#endif
