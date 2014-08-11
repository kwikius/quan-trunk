#ifndef QUAN_GX_MFC_WINDOW_CONTEXT_HPP_INCLUDED
#define QUAN_GX_MFC_WINDOW_CONTEXT_HPP_INCLUDED

// devicecontext scaled to a window for MFC

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

// See QUAN_ROOT/quan_matters/index.html for documentation.

/*

 removed is_printing from base class
*/

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <afxwin.h>
#include <quan/two_d/vect.hpp>
#include <quan/two_d/clip.hpp>
#include <quan/length.hpp>
#include <quan/gx/graphics_context.hpp>
#include <quan/two_d/box.hpp>
#include <quan/angle.hpp>

   // sets up graphics for millimeters with origin in center of view
   // window_context provides a device context with origin (0,0) at center
   // increasing y up, increasing x to right
   // input in  millimeters using quan::length::mm type
   
namespace quan { namespace gx { namespace mfc{ 

   class window_context 
      : public quan::gx::graphics_context<quan::length::mm>{
      public:

      typedef quan::length::mm mm;
      typedef quan::two_d::vect<mm> vect;
      typedef quan::two_d::vect<double> dvect;
      typedef quan::two_d::vect<int> ivect;

      window_context(
         CDC* pDC, 
         bool in_print_preview, 
         vect const & drawing_size, // actual size in mm
         vect const & drawing_origin,  // position of drawing origin from centre at center of drawing rect
         dvect const & scroll_ratio,   // between 0 and 1?
         vect const & window_size_in_mm, // window on screen
         ivect const & window_size_in_px, // window on screen
         double const & scale            // scale from actual to screen
                                         // 0 to 1 or -0.5 to + 0.5 ?
      ):m_pDC(pDC), 
         //quan::gx::graphics_context<quan::length::mm>(in_print_preview),
         m_drawing_size(drawing_size),
         m_drawing_origin(drawing_origin), 
         m_scroll_ratio(scroll_ratio),
         m_window_size_in_mm(window_size_in_mm),
         m_window_size_in_px(window_size_in_px),
         m_scale(scale),
         m_drawing_scroll_pos(
            drawing_size.x * scroll_ratio.x,
            drawing_size.y * scroll_ratio.y
         )
         {
            ASSERT(pDC != 0);
           // set up mapping of raw display
           set_up_device_transform();
         }
      bool is_printing()const {return m_pDC->IsPrinting() != 0;}
      void draw_line(primitives::simple_line<mm> const & line) const 
      {
        
         typedef quan::two_d::line<dvect> dline;
         typedef std::pair<bool,dline> res_type;
         // max size of clipping in Windows
         quan::two_d::box<double> clipbox(-32767,32767,32767,-32767);
         quan::two_d::clip<double> clip(clipbox);
     
         dvect from = device_transform_in(line.get_from());
         dvect to   = device_transform_in(line.get_to());

         dline ln(from,to);
         res_type res = clip(ln);
         
         // first is true if clipped line is visible
         if( res.first){
            double line_width = absolute_to_dev_x(line.get_line_width());
            if ( line_width < 1){
               line_width = 1;
            }
            COLORREF mfc_pencolor =static_cast<COLORREF>(0);
            quan::gx::abc_color::ptr color_ptr = line.get_color();
            if(color_ptr){
               quan::gx::rgb_color<unsigned char> pen_color = color_ptr->get_uchar_rgb();
               mfc_pencolor = RGB(pen_color.red,pen_color.green,pen_color.blue);
            }
            CPen pen(PS_SOLID,static_cast<int>(line_width),mfc_pencolor);
	         CPen* oldpen = m_pDC->SelectObject(&pen);

           // TRACE ("Outputting Line\n");
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);

            m_pDC->SelectObject(oldpen);
         }
        
      }
      void draw_polyline(primitives::polyline<mm> const & poly) const
      {
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
         typedef quan::two_d::line<dvect> dline;
         typedef std::pair<bool,dline> res_type;

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
            dline ln(from,to);
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
      }

      void draw_box(primitives::box<length_type> const & b ) const
      {
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

         typedef quan::two_d::line<dvect> dline;
         typedef std::pair<bool,dline> res_type;
        
         dvect p1 = device_transform_in(bottom_left(b.get_box()));
         dvect p3 = device_transform_in(top_right(b.get_box()));
         
         dvect p2(p3.x,p1.y);
         dvect p4(p1.x,p3.y);

         quan::two_d::box<double> clipbox(-32767,32767,32767,-32767);
         quan::two_d::clip<double> clip(clipbox);

          dline ln1(p1,p2);
          res_type res = clip(ln1);
         // first is true if clipped line is visible
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         dline ln2(p2,p3);
         res = clip(ln2);
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         dline ln3(p3,p4);
         res = clip(ln3);
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         dline ln4(p4,p1);
         res = clip(ln4);
         if( res.first){
            CPoint p1(static_cast<int>(res.second.from.x),static_cast<int>(res.second.from.y));
            CPoint p2(static_cast<int>(res.second.to.x),static_cast<int>(res.second.to.y));
            m_pDC->MoveTo(p1);
            m_pDC->LineTo(p2);        
         }
         m_pDC->SelectObject(oldpen); 
      }
      void draw_text(primitives::simple_text<length_type> const & text) const
      {
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
      }

      // in impl set up circle points to do a polyline
      void draw_circle(primitives::circle<length_type> const & c) const
      {
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
      }
      double get_scale() const
      {
         return m_scale;
      }
      bool is_in_print_preview() const{return m_in_print_preview;}
      private:
      // scale an x distance to pixels
      // no translation
      double absolute_to_dev_x(mm const & val) const
      {
         return val.numeric_value() * m_scale * 100;
      }
      // scale a y distance to pixels
      // no translation
      double absolute_to_dev_y(mm const & val) const  
      {
         return val.numeric_value() * m_scale * 100;
      }
      // full transform at coordinate level
      vect logical_transform_in(vect const & in)const
      {
         vect p1 = in + m_drawing_origin;
         vect p2 = p1 - m_drawing_scroll_pos;
         vect p3 = p2 * m_scale;
         return p3;
      }
      // transform at logical and device levels
      dvect device_transform_in(vect const & in)const
      {
         vect p1 = logical_transform_in(in);
         return dvect(p1.x.numeric_value() * 100,p1.y.numeric_value() * 100);
      }
     
      // set up raw GDI device
      void set_up_device_transform()const
      {
         m_pDC->SetMapMode(MM_HIMETRIC);
         if ( this->is_printing()){
            m_pDC->SetViewportOrg(
               m_pDC->GetDeviceCaps(HORZRES)/2,
               m_pDC->GetDeviceCaps(VERTRES)/2
            );
         }else{
            m_pDC->SetViewportOrg(
               m_window_size_in_px.x/2,
               m_window_size_in_px.y/2
            );
         }
      }
     CDC* m_pDC;
     vect m_drawing_size;
     vect m_drawing_origin;
     dvect m_scroll_ratio;
     vect m_drawing_scroll_pos;
     vect m_window_size_in_mm;
     ivect m_window_size_in_px;
     double m_scale;
     bool const m_in_print_preview;    

   };
  
 }}}//quan::mfc::window_context

#endif
