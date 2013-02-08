#ifndef QUAN_GX_RGB_COLOR_HPP_INCLUDED
#define QUAN_GX_RGB_COLOR_HPP_INCLUDED
// Copyright Andrew Little 2008

// See QUAN_ROOT/quan_matters/index.html for documentation.

namespace quan{ namespace gx{

   template <typename ValueType>
   struct max_rgb_color_value;

   template <>
   struct max_rgb_color_value<unsigned char>{
      unsigned char operator()()const 
      {
         return static_cast<unsigned char> (0xFF);
      }
   };

   template <>
   struct max_rgb_color_value<double>{
      double operator()()const 
      {
         return 1.0;
      }
   };
// add float uint etc
   // valuetype float uint uchar

   template <typename ValueType>
   struct rgb_color{
      typedef ValueType value_type;
      rgb_color(value_type const & r, value_type const & g, value_type const & b)
      : red(r),green(g),blue(b){}
      value_type red;
      value_type green;
      value_type blue;
   };

}}
#endif
