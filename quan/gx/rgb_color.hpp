#ifndef QUAN_GX_RGB_COLOR_HPP_INCLUDED
#define QUAN_GX_RGB_COLOR_HPP_INCLUDED
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
