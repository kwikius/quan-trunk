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
#include <quan/min.hpp>
#include <quan/gx/primitives/box.hpp>
#include <quan/gx/rgb_color.hpp>
#include <quan/gx/abc_color.hpp>

/*
 If problems try m_pDC->Flush()?;
*/

void quan::gx::wxwidgets::graphics_context::draw_filled_box(
   quan::gx::primitives::box<mm> const & box
) const
{
   auto rgb_col = box.get_color()->get_uchar_rgb();
      wxColour wx_colour{rgb_col.red,rgb_col.green,rgb_col.blue};

   auto px_line_width = quan::max(
      quan::arithmetic_convert<int>(
         box.get_line_width() * m_scale * m_px_per_mm.x
      ),
      1
   );
   wxBrush brush(wx_colour);
   m_pDC->SetBrush(brush);
   wxPen pen(wx_colour,px_line_width);
   m_pDC->SetPen(pen);
   
   auto const & b = box.get_box();
   auto tl = device_transform_in(top_left(b));
   auto br = device_transform_in(bottom_right(b));
   double left = quan::min(tl.x,br.x);
   double right = quan::max(tl.x,br.x);
   double top = quan::min(tl.y,br.y);
   double bottom = quan::max(tl.y,br.y);
   vect2_d size = {right-left,bottom - top};
   // TODO add clip
   m_pDC->DrawRectangle(
         quan::arithmetic_convert<int>(left),
         quan::arithmetic_convert<int>(top),
         quan::arithmetic_convert<int>(size.x),
         quan::arithmetic_convert<int>(size.y)
   );
// 
//   ll_draw_line({top_left(b), top_right(b)});
//   ll_draw_line({top_right(b),bottom_right(b)});
//   ll_draw_line({bottom_right(b), bottom_left(b)});
//   ll_draw_line({bottom_left(b),top_left(b)});

   m_pDC->SetPen(wxNullPen);
   m_pDC->SetBrush(wxNullBrush);
}
