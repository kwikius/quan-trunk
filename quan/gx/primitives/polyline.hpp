#ifndef QUAN_GX_PRIMITIVE_POLYLINE_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_POLYLINE_HPP_INCLUDED
// Copyright Andrew Little 2008

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
      typename std_vect::size_type get_num_elements()const
      {
         return m_points.size();
      }
      std_vect const & get_points()const
      {
         return m_points;
      }
   
      private:
      length_type m_width;
      std_vect m_points;
      abc_color::ptr m_color;
      
   };

}}}

#endif