#ifndef QUAN_GX_MFC_MOUSE_CONTEXT_HPP_INCLUDED
#define QUAN_GX_MFC_MOUSE_CONTEXT_HPP_INCLUDED

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
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <afxwin.h>
#include <quan/two_d/vect.hpp>
#include <quan/length.hpp>

/*
   mouse_context must be kept in step with window_context
   converts a CPoint to a point in the drawing
*/
   
namespace quan { namespace gx { namespace mfc{ 

// turns a mouse point input to a drawing point in the drawing
   class mouse_context{
      
       public:
      virtual ~mouse_context(){}
      
      typedef quan::length::mm mm;
      typedef quan::two_d::vect<mm> vect;
      typedef quan::two_d::vect<double> dvect;
      typedef quan::two_d::vect<int> ivect;

      mouse_context(
         vect const & drawing_size,
         vect const & drawing_origin, 
         dvect const & scroll_ratio,
         vect const & window_size_in_mm,
         ivect const & window_size_in_px,
         double const & scale
      ): m_drawing_size(drawing_size),
         m_drawing_origin(drawing_origin),
         m_scroll_ratio(scroll_ratio),
         m_window_size_in_mm(window_size_in_mm),
         m_window_size_in_px(window_size_in_px),
         m_scale(scale),
         m_drawing_scroll_pos(
            drawing_size.x * scroll_ratio.x,
            drawing_size.y * scroll_ratio.y
         )
         {}
      // for mouse to drawing position
      // essentially do the inverse of the
      // drawing to device in window_context below
      // with an adjustment for the raw device mouse position
      vect mouse_transform_out( CWnd* pWnd, CPoint const & point)const
      {
         CDC * pDC = pWnd->GetDC();
         int oldmode = pDC->SetMapMode(MM_HIMETRIC);
         CPoint oldorg = pDC->SetViewportOrg(
            m_window_size_in_px.x/2,
            m_window_size_in_px.y/2
         );

         CPoint p1 = point;
         pDC->DPtoLP(&p1);

         pDC->SetViewportOrg(oldorg);
         pDC->SetMapMode(oldmode);
         pWnd->ReleaseDC(pDC);

         vect p2(mm(p1.x / 100.),mm(p1.y / 100.));
         vect p3 = p2 / m_scale;
         vect p4 = p3 + m_drawing_scroll_pos;
         vect p5 = p4 - m_drawing_origin;

         return p5;
      }
      
     private:
     
     vect m_drawing_size;
     vect m_drawing_origin;
     dvect m_scroll_ratio;
     vect m_drawing_scroll_pos;
     vect m_window_size_in_mm;
     ivect m_window_size_in_px;
     double m_scale;

   };
}}}

#endif
