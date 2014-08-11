#ifndef QUAN_GX_PRIMITIVE_CIRCLE_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_CIRCLE_HPP_INCLUDED
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

#include <quan/two_d/vect.hpp>
#include <quan/gx/abc_color.hpp>
#include <quan/gx/static_rgb_color.hpp>
//#include <vector>

namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct circle{
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      circle(
         vect const & center,
         length_type const & radius,
         length_type const & line_width = length_type(),
         abc_color::ptr color = quan::gx::rgb::colors::black
      )
      : m_center(center),
        m_radius(radius),
        m_line_width(line_width),
        m_color(color){}
      
      length_type get_line_width() const
      {return m_line_width;}

      vect get_center()const
      {return m_center;}

      length_type const & get_radius() const
      {
         return m_radius;
      }

      abc_color::ptr const & get_color()const
      {
         return m_color;
      }
    
      private:
      
      vect m_center;
      length_type m_radius;
      length_type m_line_width;
      abc_color::ptr m_color;
      
   };

}}}

#endif
