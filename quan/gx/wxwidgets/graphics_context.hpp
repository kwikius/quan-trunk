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

      void draw_polyline(primitives::polyline<mm> const & poly) const
      {
/*
         // output something here ?
         if ( poly.get_num_elements() < 2) return;

         double line_width = absolute_to_dev_x(poly.get_line_width());
         
         if ( line_width < 1){
            line_width = 1;
         }
         COLORREF mfc_pencolor =static_cast<COLORREF>(0);
         quan::gx::abc_color::ptr color_ptr = poly.get_color();
         if(color_ptr){
            quan::gx::rgb_color<unsigned char> pen_color = color_ptr->get_uchar_rgb();
            mfc_pencolor = RGB(pen_color.red,pen_color.green,pen_color.blue);
         }
         CPen pen(PS_SOLID,static_cast<int>(line_width),mfc_pencolor);
	      CPen* oldpen = m_pDC->SelectObject(&pen);

         typedef primitives::polyline<mm>::std_vect std_vect_t;
         typedef std_vect_t::const_iterator iter_t;
         typedef quan::two_d::line<dvect> line2_d;
         typedef std::pair<bool,line2_d> res_type;

         std_vect_t const & v = poly.get_points();
         iter_t iter = v.begin();
         iter_t const end = v.end();
       
         quan::two_d::box<double> clipbox(-32767,32767,32767,-32767);
         quan::two_d::clip<double> clip(clipbox);

         vect last_pt = *iter;
         ++iter;
         while (iter!= end){
            dvect from = device_transform_in(last_pt);
            dvect to = device_transform_in(*iter);
            last_pt = *iter;
            line2_d ln(from,to);
            res_type res = clip(ln);
         // first is true if clipped line is visible
            if( res.first){
               CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
               CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
               m_pDC->MoveTo(p1);
               m_pDC->LineTo(p2);        
            }
            ++iter;
         }
         m_pDC->SelectObject(oldpen); 
*/
      }

      void draw_box(primitives::box<length_type> const & b ) const
      {
/*
         double line_width = absolute_to_dev_x(b.get_line_width());
         if ( line_width < 1){
            line_width = 1;
         }
         COLORREF mfc_pencolor =static_cast<COLORREF>(0);
         quan::gx::abc_color::ptr color_ptr = b.get_color();
         if(color_ptr){
            quan::gx::rgb_color<unsigned char> pen_color = color_ptr->get_uchar_rgb();
            mfc_pencolor = RGB(pen_color.red,pen_color.green,pen_color.blue);
         }
         CPen pen(PS_SOLID,static_cast<int>(line_width),mfc_pencolor);
	      CPen* oldpen = m_pDC->SelectObject(&pen);

         typedef quan::two_d::line<dvect> line2_d;
         typedef std::pair<bool,line2_d> res_type;
        
         dvect p1 = device_transform_in(bottom_left(b.get_box()));
         dvect p3 = device_transform_in(top_right(b.get_box()));
         
         dvect p2(p3.x,p1.y);
         dvect p4(p1.x,p3.y);

         quan::two_d::box<double> clipbox(-32767,32767,32767,-32767);
         quan::two_d::clip<double> clip(clipbox);

          line2_d ln1(p1,p2);
          res_type res = clip(ln1);
         // first is true if clipped line is visible
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         line2_d ln2(p2,p3);
         res = clip(ln2);
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         line2_d ln3(p3,p4);
         res = clip(ln3);
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         line2_d ln4(p4,p1);
         res = clip(ln4);
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         m_pDC->SelectObject(oldpen); 
*/
      }
      void draw_text(primitives::simple_text<length_type> const & text) const
      {
/*
         typedef primitives::simple_text<length_type> txt_t;
         // check is in range
         dvect p1 = device_transform_in(text.get_position());
         if( (p1.x < 32767 ) && ( p1.x > -32767) 
               && (p1.y < 32767) && ( p1.y > -32767)){

            int align =0;
            switch (text.get_horz_align()){
               case txt_t::align_left:
                  align |= TA_LEFT;
                  break;
               case txt_t::align_right:
                  align |= TA_RIGHT;
                  break;
               case txt_t::align_center:
                  align |= TA_CENTER;
                  break;
               default:
                  break;
            }
            switch (text.get_vert_align()){
               case txt_t::align_top:
                  align |= TA_TOP;
                  break;
               case txt_t::align_bottom:
                  align |= TA_BOTTOM;
                  break;
               default:
                  break;
            }

            double dev_height = absolute_to_dev_y(text.get_height());
            CFont font;

            font.CreateFont( 
               static_cast<int>(dev_height +.5), // height
               0,                // width
               0,                // escapement
               0,                // orientation
	            FW_NORMAL,        //weight
               0,                // italic
               0,                // underline
               0,                // strikeout
	            DEFAULT_CHARSET, // character set
               OUT_DEFAULT_PRECIS, // Precision
               CLIP_CHARACTER_PRECIS, // ClipPrecision
	            PROOF_QUALITY, // quality
               DEFAULT_PITCH | FF_ROMAN, //pitch and family
               text.get_font_face().c_str() // facename
            );

            CFont* oldfont = m_pDC->SelectObject(&font);
            m_pDC->SetTextAlign(align);	
            m_pDC->TextOut(
               static_cast<int>(p1.x), static_cast<int>(p1.y),
               text.get_text().c_str(),
               text.get_text().length()
            );
            m_pDC->SelectObject(oldfont);
            font.DeleteObject();
         }
*/
      }

      // in impl set up circle points to do a polyline
      void draw_circle(primitives::circle<length_type> const & c) const
      {
/*
         vect center = c.get_center();
         mm radius = c.get_radius();
         
         static const int N = 72;
         quan::angle::deg const rev(360);
         quan::angle::deg const da = rev / N;
         double const sin_da = quan::sin(da);
         double const cos_da = quan::cos(da);
         
         quan::gx::primitives::polyline<mm> poly(
            c.get_line_width(),
            c.get_color()
         );
         vect last_point = center + vect(radius,mm(0));
         poly.push_back(last_point);
         for ( int i = 0 ; i < N ; ++i){
            vect diff = last_point - center;
            vect next_point = center
               + vect(
                  diff.x * cos_da - diff.y * sin_da,
                  diff.x * sin_da + diff.y * cos_da
            );
            poly.push_back(next_point);
            last_point = next_point;
         }
         poly.push_back(center + vect(radius,mm(0)));
         
         this->draw_polyline(poly);
*/
      }

   private:

      double scale_to_device_x(mm const & val) const;
      double scale_to_device_y(mm const & val) const;
      // full transform at coordinate level
      vect2_mm logical_transform_in(vect2_mm const & in)const;

      // transform at logical and device levels
      // still as double not int to preserve precision
      vect2_d device_transform_in(vect2_mm const & in)const;

      wxDC* m_pDC;

      double m_scale;
      vect2_mm m_drawing_offset;
      vect2_per_mm m_px_per_mm;
      vect2_i m_dev_size_px;
      quan::two_d::clip<double> m_clip;

      // if true if line is still visible, output in p1,p2, 
      // if false nothing to draw as line is outside clip box)
      bool clip_into (
         quan::two_d::line<vect2_mm> const & line,
         wxPoint & p1, wxPoint& p2
      )const;
   };
  
 }}}//quan::wxwidgets::graphics_context

#endif
