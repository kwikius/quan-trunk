#ifndef QUAN_GX_WXWIDGETS_GRAPHICS_CONTEXT_HPP_INCLUDED1
#define QUAN_GX_WXWIDGETS_GRAPHICS_CONTEXT_HPP_INCLUDED1

// devicecontext scaled to a window for wxWidgets

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

   // should make this a template on LengthType
    class graphics_info_context {
   public:  

      typedef quan::length::mm            mm;
      typedef quan::two_d::vect<mm>       vect2_mm;
      typedef quan::two_d::vect<quan::reciprocal_length::per_mm>       vect2_per_mm;
      typedef quan::two_d::vect<double>   vect2_d;
      typedef quan::two_d::vect<int>      vect2_i;

      graphics_info_context(
         quan::gx::drawing<mm> const * drawing_in,
         quan::gx::drawing_view const * drawing_view_in,
         quan::gx::device_window const * device_window_in
      );
     
      double scale_to_device_x(mm const & val) const;
      double scale_to_device_y(mm const & val) const;

// drwaing_to_view
      vect2_mm drawing_to_view(vect2_mm const & in)const;
      vect2_mm view_to_drawing(vect2_mm const & in)const;

      vect2_mm scale_drawing_to_view(vect2_mm const & in)const;
      vect2_mm scale_view_to_drawing(vect2_mm const & in)const;

      vect2_d view_to_device(vect2_mm const & in) const;
      vect2_mm device_to_view(vect2_d const & in) const;

      vect2_d scale_view_to_device(vect2_mm const & in) const;
      vect2_mm scale_device_to_view(vect2_d const & in) const;

      vect2_d device_transform_in(vect2_mm const & in)const;
      vect2_mm device_to_drawing(vect2_d const & v)const;
   protected:
      double m_scale;
      vect2_mm m_drawing_offset;
      vect2_per_mm m_px_per_mm;
      vect2_i m_dev_size_px;
    };

}}}
   
namespace quan { namespace gx { namespace wxwidgets{ 

   class graphics_context 
      : public graphics_info_context, public quan::gx::graphics_context<quan::length::mm>{
      public:

      graphics_context(
         wxDC* pDC, 
         quan::gx::drawing<mm> const * drawing_in,
         quan::gx::drawing_view const * drawing_view_in,
         quan::gx::device_window const * device_window_in
      );

      void draw_line(primitives::simple_line<mm> const & line) const ;

      void draw_polyline(primitives::polyline<mm> const & poly) const;

      void draw_box(primitives::box<length_type> const & b ) const;

      void draw_text(primitives::simple_text<length_type> const & text) const;

      // in impl set up circle points to do a polyline
      void draw_circle(primitives::circle<length_type> const & c) const;
      void draw_filled_box(primitives::box<length_type> const & b ) const;

   private:

      wxDC* m_pDC;

      quan::two_d::clip<double> m_clip;

      void ll_draw_line(quan::two_d::line<vect2_mm> const & line) const;

      bool clip_into (
         quan::two_d::line<vect2_mm> const & line,
         wxPoint & p1, wxPoint& p2
      )const;
   };
  
 }}}//quan::wxwidgets::graphics_context

#endif
