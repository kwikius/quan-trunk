#ifndef QUAN_GX_PRIMITIVE_POLYLINE_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_POLYLINE_HPP_INCLUDED
// Copyright Andrew Little 2008
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/two_d/vect.hpp>
#include <quan/gx/abc_color.hpp>
#include <vector>
namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct polyline{
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      typedef std::vector<vect> std_vect;
      polyline(){}
      polyline(
         length_type const & width ,
         abc_color::ptr color = abc_color::ptr())
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