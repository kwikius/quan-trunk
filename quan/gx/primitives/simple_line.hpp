#ifndef QUAN_GX_PRIMITIVE_LINE_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_LINE_HPP_INCLUDED

// Copyright Andrew Little 2008

#include <quan/two_d/line.hpp>
#include <quan/gx/abc_color.hpp>

namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct simple_line{
     
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;

      simple_line(
         vect const & to, vect const & from,
         length_type const & width = length_type(),
         abc_color::ptr color = abc_color::ptr())
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
