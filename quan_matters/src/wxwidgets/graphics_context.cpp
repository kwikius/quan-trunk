#include <quan/gx/wxwidgets/graphics_context.hpp>

using quan::gx::wxwidgets::graphics_context;
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

// drawing_to_view
graphics_info_context::vect2_mm
graphics_info_context::logical_transform_in(graphics_info_context::vect2_mm const & in)const
{
   return (in + m_drawing_offset ) * m_scale;
}

// view_to_drawing
graphics_info_context::vect2_mm
graphics_info_context::logical_transform_out(graphics_info_context::vect2_mm const & in)const
{
   return ( in / m_scale) - m_drawing_offset;
}

// drawing_to_device = drawing_to_view * view_to_device
graphics_info_context::vect2_d 
graphics_info_context::device_transform_in(
  graphics_info_context::vect2_mm const & in
)const
{
  // drawing_to_view
  vect2_mm p1 = logical_transform_in(in);
  return {
     // view_to_device
     m_dev_size_px.x/2.0 + p1.x * m_px_per_mm.x ,
     m_dev_size_px.y/2.0 - p1.y * m_px_per_mm.y 
  };
}

// device_to_drawing = device_To_view * view_to_drawing
graphics_info_context::vect2_mm
graphics_info_context::device_transform_out(graphics_info_context::vect2_d const & v)const
{
   // device_to_view
   auto x = ( v.x - m_dev_size_px.x/2.0)/ m_px_per_mm.x ;
   auto y = (m_dev_size_px.y/2.0  - v.y) / m_px_per_mm.y ;

   // view_to_drawing
   return   logical_transform_out({x,y});
}

/*
   used for getting line width but prob use better alg
   // scale a y distance to pixels
// no translation
  // scale_drawing_to_device
*/
double graphics_info_context::scale_to_device_x(mm const & val) const
{
   return val * m_scale * m_px_per_mm.x  ;
}
// scale a y distance to pixels
// no translation
double graphics_info_context::scale_to_device_y(mm const & val) const  
{
   return val * m_scale * m_px_per_mm.y;
}

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



