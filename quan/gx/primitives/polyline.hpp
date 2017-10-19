#ifndef QUAN_GX_PRIMITIVE_POLYLINE_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_POLYLINE_HPP_INCLUDED
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

#include <quan/two_d/vect.hpp>
#include <quan/gx/abc_color.hpp>
#include <quan/gx/static_rgb_color.hpp>
#include <vector>
#include <initializer_list>

namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct polyline{
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      typedef std::vector<vect> std_vect;
      polyline(): m_width{length_type{1}},m_color{quan::gx::rgb::colors::black}{}
      polyline(
         length_type const & width ,
         abc_color::ptr color = quan::gx::rgb::colors::black)
      : m_width(width),m_color(color){}

      polyline(std_vect const & v, 
         length_type const & width = length_type{0},
         abc_color::ptr color = quan::gx::rgb::colors::black
      ) : m_width{width},m_points(v),m_color{color}{}
      
      length_type get_line_width() const
      {return m_width;}
      abc_color::ptr const & get_color()const
      {
         return m_color;
      }

      void push_back(vect const& v)
      {
         m_points.push_back(v);
      }

      void push_back(std::initializer_list<vect> list)
      {
         for(vect const & v: list){
             push_back(v);
         }
      }

      void push_back(std_vect const & list)
      {
         for(vect const & v: list){
             push_back(v);
         }
      }

      typename std_vect::size_type get_num_elements()const
      {
         return m_points.size();
      }

      std_vect const & get_points()const
      {
         return m_points;
      }

      polyline & operator += (vect const & t)
      {
         for(vect & v: m_points){
             v += t;
         }
         return *this;
      }
      polyline & operator -= (vect const & t)
      {
         for(vect & v: m_points){
             v -= t;
         }
         return *this;
      }
   
      private:
      length_type m_width;
      std_vect m_points;
      abc_color::ptr m_color;
      
   };

}}}

#endif
