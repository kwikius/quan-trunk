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
#include <quan/gx/primitives/simple_line.hpp>
#include <quan/gx/rgb_color.hpp>
#include <quan/gx/abc_color.hpp>

void quan::gx::wxwidgets::graphics_context::ll_draw_line(
  quan::two_d::line<vect2_mm> const & line
) const 
{
   wxPoint p1;
   wxPoint p2;

   if( this->clip_into(line, p1,p2)){
      m_pDC->DrawLine(p1,p2);
   }
}
void quan::gx::wxwidgets::graphics_context::draw_line(
   primitives::simple_line<mm> const & line
) const 
{
  
   auto rgb_col = line.get_color()->get_uchar_rgb();
     wxColour wx_colour{rgb_col.red,rgb_col.green,rgb_col.blue};

   //do line width
   auto px_line_width = quan::max(
      quan::arithmetic_convert<int>(
         line.get_line_width() * m_scale * m_px_per_mm.x
      ),
      1
   );
     // create a pen
   wxPen pen(wx_colour,px_line_width);

   m_pDC->SetPen(pen);

   ll_draw_line(line.get_line());

   m_pDC->SetPen(wxNullPen);
}
