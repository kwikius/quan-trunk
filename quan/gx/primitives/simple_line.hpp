#ifndef QUAN_GX_PRIMITIVE_LINE_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_LINE_HPP_INCLUDED

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

#include <quan/two_d/line.hpp>
#include <quan/gx/abc_color.hpp>
#include <quan/gx/static_rgb_color.hpp>

namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct simple_line{
     
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;

      simple_line(
         vect const & to, vect const & from,
         length_type const & width = length_type{1},
         abc_color::ptr color = quan::gx::rgb::colors::black)
      : m_line(to,from),m_width(width),m_color(color){}

      quan::two_d::line<vect> get_line() const
      {return m_line;}

      length_type get_line_width() const
      {return m_width;}

      abc_color::ptr const & get_color()const
      {return m_color;}
      
      vect get_from()const {return m_line.from;}
      vect get_to()const {return m_line.to;}
      
      private:
      quan::two_d::line<vect> m_line;
      length_type m_width;
      abc_color::ptr m_color;
   };

}}}

#endif
