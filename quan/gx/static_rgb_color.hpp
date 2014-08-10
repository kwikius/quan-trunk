#ifndef QUAN_GX_STATIC_RGB_COLOR_HPP_INCLUDED
#define QUAN_GX_STATIC_RGB_COLOR_HPP_INCLUDED
// Copyright Andrew Little 2008
//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/gx/abc_color.hpp>
#include <quan/gx/rgb_color.hpp>

namespace quan{ namespace gx{

   template < typename T, T R, T G, T B>
   struct static_rgb_color : abc_color{
      rgb_color<unsigned char> get_uchar_rgb() const
      {
         return rgb_color<unsigned char>
         (
            static_cast<unsigned char>(
               static_cast<double>(R) * max_rgb_color_value<unsigned char>()()
               / max_rgb_color_value<T>()()
            ),
            static_cast<unsigned char>(
               static_cast<double>(G) * max_rgb_color_value<unsigned char>()()
               / max_rgb_color_value<T>()()
            ),
             static_cast<unsigned char>(
               static_cast<double>(B) * max_rgb_color_value<unsigned char>()()
               / max_rgb_color_value<T>()()
            )
         );
      }
      ptr clone() const 
      {
         ptr p(new static_rgb_color);
         return p;
      }
   };

}}
namespace quan{ namespace gx{ namespace rgb{

   typedef quan::gx::static_rgb_color<unsigned char,0,0,0> black;
   typedef quan::gx::static_rgb_color<unsigned char,0xff,0xff,0xff> white;
   typedef quan::gx::static_rgb_color<unsigned char,0xff,0,0> red;
   typedef quan::gx::static_rgb_color<unsigned char,0,0xff,0> green;
   typedef quan::gx::static_rgb_color<unsigned char,0,0,0xff> blue;
   typedef quan::gx::static_rgb_color<unsigned char,0xff,0xff,0> yellow;
   typedef quan::gx::static_rgb_color<unsigned char,0,0xff,0xff> aqua;
   typedef quan::gx::static_rgb_color<unsigned char,0xC0,0xC0,0xC0> silver;
   typedef quan::gx::static_rgb_color<unsigned char,0x80,0x80,0x80> gray;
   //typedef quan::gx::static_rgb_color<unsigned char,0x80,0x80,0x80> gray;

   namespace colors{
    extern quan::gx::abc_color::ptr black;
   extern  quan::gx::abc_color::ptr white;
   extern  quan::gx::abc_color::ptr red;
   extern  quan::gx::abc_color::ptr green;
   extern  quan::gx::abc_color::ptr blue;
   extern  quan::gx::abc_color::ptr yellow;
   extern  quan::gx::abc_color::ptr aqua;
   extern  quan::gx::abc_color::ptr silver;
   extern  quan::gx::abc_color::ptr gray;

   }

}}}

#endif
