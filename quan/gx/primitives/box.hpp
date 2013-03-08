#ifndef QUAN_GX_PRIMITIVE_BOX_HPP_INCLUDED
#define QUAN_GX_PRIMITIVE_BOX_HPP_INCLUDED
// Copyright Andrew Little 2008

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/two_d/vect.hpp>
#include <quan/two_d/box.hpp>
#include <quan/gx/abc_color.hpp>
#include <vector>

namespace quan{ namespace gx{ namespace primitives{

   template <typename LengthType>
   struct box{
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      typedef ::quan::two_d::box<length_type> box_t;
      box(
         box_t const & box_in,
         length_type const & width = length_type(),
         abc_color::ptr color = abc_color::ptr()
      )
      : m_box(box_in),m_width(width),m_color(color){}
      
      length_type get_line_width() const
      {return m_width;}

      abc_color::ptr const & get_color()const
      {
         return m_color;
      }
     box_t const &
      get_box()const
      {return m_box;}
     
      private:
     
      box_t m_box;
      length_type m_width;
      abc_color::ptr m_color;
      
   };

}}}

#endif