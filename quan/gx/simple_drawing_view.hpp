#ifndef QUAN_GX_SIMPLE_DRAWING_VIEW_HPP_INCLUDED
#define QUAN_GX_SIMPLE_DRAWING_VIEW_HPP_INCLUDED
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

#include <quan/gx/drawing_view.hpp>

namespace quan{ namespace gx{

   struct simple_drawing_view : drawing_view{
      // full size of drawable rectangle
      simple_drawing_view(): m_scale{1.0},m_scroll_ratio{0.0,0.0}{}
      double get_scale() const
      { return m_scale;}
       double& get_scale_ref()
      { return m_scale;}
      // scrollpos between 0 and 1 in x and y , center is 0.5
      quan::two_d::vect<double> get_scroll_ratio() const
      { return m_scroll_ratio;}
      void set_scale(double const & scale)
      { m_scale = scale;}
      void set_scroll_ratio(quan::two_d::vect<double> sr)
      { m_scroll_ratio = sr;}
       void set_x_scroll_ratio(double const & sr)
      { m_scroll_ratio.x = sr;}
        void set_y_scroll_ratio(double const & sr)
      { m_scroll_ratio.y = sr;}
     private:
      double m_scale;
      quan::two_d::vect<double> m_scroll_ratio;
   };

}}

#endif // QUAN_GX_SIMPLE_DRAWING_VIEW_HPP_INCLUDED
