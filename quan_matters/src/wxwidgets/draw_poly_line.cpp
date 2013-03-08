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

   auto rgb_col = polyline.get_color()->get_uchar_rgb();
   wxColour wx_colour{rgb_col.red,rgb_col.blue, rgb_col.green};

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