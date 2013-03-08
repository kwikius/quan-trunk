#ifndef QUAN_GX_WXWIDGETS_GRAPHICS_CONTEXT_HPP_INCLUDED
#define QUAN_GX_WXWIDGETS_GRAPHICS_CONTEXT_HPP_INCLUDED

// devicecontext scaled to a window for wxWidgets

// Copyright Andrew Little 2011

#include <cassert>
#include <wx/wx.h>

#include <quan/length.hpp>
#include <quan/reciprocal_length.hpp>
#include <quan/angle.hpp>
#include <quan/two_d/vect.hpp>
#include <quan/two_d/clip.hpp>
#include <quan/two_d/box.hpp>

#include <quan/gx/graphics_context.hpp>
#include <quan/gx/drawing.hpp>
#include <quan/gx/drawing_view.hpp>
#include <quan/gx/device_window.hpp>

   // sets up graphics for millimeters with origin in center of view
   // graphics_context provides a device context with origin (0,0) at center
   // increasing y up, increasing x to right
   // input in  millimeters using quan::length::mm type
   
namespace quan { namespace gx { namespace wxwidgets{ 

   class graphics_context 
      : public quan::gx::graphics_context<quan::length::mm>{
      public:

      typedef quan::length::mm            mm;
      typedef quan::two_d::vect<mm>       vect2_mm;
      typedef quan::two_d::vect<quan::reciprocal_length::per_mm>       vect2_per_mm;
      typedef quan::two_d::vect<double>   vect2_d;
      typedef quan::two_d::vect<int>      vect2_i;

      graphics_context(
         wxDC* pDC, 
         quan::gx::drawing<mm> const * drawing_in,
         quan::gx::drawing_view const * drawing_view_in,
         quan::gx::device_window const * device_window_in
      );

      void draw_line(primitives::simple_line<mm> const & line) const ;

      void draw_polyline(primitives::polyline<mm> const & poly) const;

      void draw_box(primitives::box<length_type> const & b ) const;

      void draw_text(primitives::simple_text<length_type> const & text) const { }

      // in impl set up circle points to do a polyline
      void draw_circle(primitives::circle<length_type> const & c) const { }

      double scale_to_device_x(mm const & val) const;
      double scale_to_device_y(mm const & val) const;
      // full transform at coordinate level
      vect2_mm logical_transform_in(vect2_mm const & in)const;
      vect2_mm logical_transform_out(vect2_mm const & in)const;

      // transform at logical and device levels
      // still as double not int to preserve precision
      vect2_d device_transform_in(vect2_mm const & in)const;
      vect2_mm device_transform_out(graphics_context::vect2_d const & v)const;
   private:

      wxDC* m_pDC;

      double m_scale;
      vect2_mm m_drawing_offset;
      vect2_per_mm m_px_per_mm;
      vect2_i m_dev_size_px;
      quan::two_d::clip<double> m_clip;

      void ll_draw_line(quan::two_d::line<vect2_mm> const & line) const;

      // if true if line is still visible, output in p1,p2, 
      // if false nothing to draw as line is outside clip box)
      bool clip_into (
         quan::two_d::line<vect2_mm> const & line,
         wxPoint & p1, wxPoint& p2
      )const;
   };
  
 }}}//quan::wxwidgets::graphics_context

#endif
