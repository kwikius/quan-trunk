#ifndef QUAN_GX_PRIMITIVE_SIMPLE_TEXT_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_SIMPLE_TEXT_HPP_INCLUDED
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
#include <vector>

namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct simple_text{
      enum horz_align { align_left = 1, align_center= 2, align_right = 4};
      enum vert_align { align_top = 1, align_bottom = 2};
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      simple_text(
         std::string const & str,
         vect const & pos,
         length_type const & height,
         std::string const & font_face = "Times New Roman",
         abc_color::ptr color = abc_color::ptr(),
         horz_align horzizontal_alignment = horz_align::align_left,
         vert_align vertical_alignment  = vert_align::align_bottom
      )
      : m_text(str), 
         m_pos(pos),
         m_height(height),
         m_font_face(font_face),
         m_color(color),
         m_horizontal_alignment(horzizontal_alignment),
         m_vertical_alignment(vertical_alignment)
      {}
      
      length_type get_height() const
      {return m_height;}

      vect get_position()const
      {return m_pos;}

      std::string const & get_text() const
      {
         return m_text;
      }
      std::string const & get_font_face()const
      {
         return m_font_face;
      }
      abc_color::ptr const & get_color()const
      {
         return m_color;
      }
      horz_align get_horz_align() const
      {
         return m_horizontal_alignment;
      }
      vert_align get_vert_align() const
      {
         return m_vertical_alignment;
      }
    
      private:
      std::string m_text;
      vect m_pos;
      length_type m_height;
      std::string m_font_face;
      abc_color::ptr m_color;
      horz_align m_horizontal_alignment;
      vert_align m_vertical_alignment;
      
   };

}}}

#endif
