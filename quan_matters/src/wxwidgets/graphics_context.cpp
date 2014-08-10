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

using quan::gx::wxwidgets::graphics_context;

//#############put in separate file#####################
using quan::gx::wxwidgets::graphics_info_context;

 graphics_info_context::graphics_info_context(
   quan::gx::drawing<mm> const * drawing_in,
   quan::gx::drawing_view const * drawing_view_in,
   quan::gx::device_window const * device_window_in
){
 // assert(pDC && m_drawing && m_drawing_view && m_device_window );
  // set up mapping of raw display
  vect2_d scroll_ratio = drawing_view_in->get_scroll_ratio();
  vect2_mm drawing_size = drawing_in->get_size();
  vect2_mm scroll_pos{ 
      scroll_ratio.x * drawing_size.x,
    scroll_ratio.y * drawing_size.y
  };
  this->m_drawing_offset = drawing_in->get_origin() - scroll_pos ;
  this->m_scale = drawing_view_in->get_scale();
  this->m_px_per_mm = device_window_in->get_px_per_mm();
  this->m_dev_size_px = device_window_in->get_size_in_px();

}

graphics_info_context::vect2_mm graphics_info_context::scale_drawing_to_view(vect2_mm const & in)const
{
   return in * m_scale;
}
graphics_info_context:: vect2_mm graphics_info_context::scale_view_to_drawing(vect2_mm const & in)const
{
   return in / m_scale;
}

// drawing_to_view
graphics_info_context::vect2_mm
graphics_info_context::drawing_to_view(graphics_info_context::vect2_mm const & in)const
{
   return scale_drawing_to_view(in + m_drawing_offset ) ;
}

// view_to_drawing
graphics_info_context::vect2_mm
graphics_info_context::view_to_drawing(graphics_info_context::vect2_mm const & in)const
{
   return scale_view_to_drawing(in) - m_drawing_offset;
}

// drawing_to_device = drawing_to_view * view_to_device
graphics_info_context::vect2_d 
graphics_info_context::device_transform_in(
  graphics_info_context::vect2_mm const & in
)const
{
  return view_to_device(drawing_to_view(in));
}

graphics_info_context::vect2_d graphics_info_context::view_to_device(vect2_mm const & in) const
{
    return scale_view_to_device( {in.x, -in.y}) + m_dev_size_px / 2;
}

graphics_info_context::vect2_d graphics_info_context::scale_view_to_device(vect2_mm const & in) const
{
    return {in.x * m_px_per_mm.x,in.y * m_px_per_mm.y};
}

graphics_info_context::vect2_mm graphics_info_context::device_to_view(vect2_d const & in) const
{
     return scale_device_to_view({in.x - m_dev_size_px.x/2.0, m_dev_size_px.y/2.0  - in.y});
}

graphics_info_context::vect2_mm graphics_info_context::scale_device_to_view(vect2_d const & in) const
{
    return {
     in.x / m_px_per_mm.x ,
     in.y / m_px_per_mm.y }
    ;
}

// device_to_drawing = device_To_view * view_to_drawing
graphics_info_context::vect2_mm
graphics_info_context::device_to_drawing(graphics_info_context::vect2_d const & v)const
{
   return view_to_drawing(device_to_view(v));
}

// scale_drawing_to_view_* scale_view_to_device
// = scale_drawing_to_device
double graphics_info_context::scale_to_device_x(mm const & val) const
{
   return val * m_scale * m_px_per_mm.x  ;
}
// scale_drawing_to_view_* scale_view_to_device
// = scale_drawing_to_device
double graphics_info_context::scale_to_device_y(mm const & val) const  
{
   return val * m_scale * m_px_per_mm.y;
}

//############################################################################

graphics_context::graphics_context(
   wxDC* pDC, 
   quan::gx::drawing<mm> const * drawing_in,
   quan::gx::drawing_view const * drawing_view_in,
   quan::gx::device_window const * device_window_in
): graphics_info_context{drawing_in,drawing_view_in,device_window_in}, m_pDC(pDC)  
{

  quan::two_d::box<double> clipbox(0,m_dev_size_px.y,m_dev_size_px.x,0);
  quan::two_d::clip<double> clip(clipbox);
  this->m_clip = clip;
}
// drawing to device
bool graphics_context::clip_into (
   quan::two_d::line<vect2_mm> const & line,
   wxPoint & p1, wxPoint& p2
)const
{
   typedef quan::two_d::line<vect2_d> line2_d;
   // convert to device units
   typedef std::pair<bool,line2_d> res_type;
   //line2_d ln(device_transform_in(line.from),device_transform_in(line.to));
   // clip to device window
   res_type res = this->m_clip(
         {device_transform_in(line.from),
          device_transform_in(line.to)}
   );
   
   // first is true if clipped line is visible
   // if so do opt else ignore
   if( res.first){
      p1.x = quan::arithmetic_convert<int>(res.second.from.x);
      p1.y = quan::arithmetic_convert<int>(res.second.from.y);

      p2.x = quan::arithmetic_convert<int>(res.second.to.x);
      p2.y = quan::arithmetic_convert<int>(res.second.to.y);
      return true;
   }else{
      return false;
   }
}



