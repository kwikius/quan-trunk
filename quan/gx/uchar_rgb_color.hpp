#ifndef QUAN_GX_UCHAR_RGB_COLOR_HPP_INCLUDED
#define QUAN_GX_UCHAR_RGB_COLOR_HPP_INCLUDED

#include <quan/gx/abc_color.hpp>

namespace quan{ namespace gx{

   struct uchar_rgb_color : abc_color{
      uchar_rgb_color(unsigned char red_in, unsigned char green_in, unsigned char  blue_in )
      : red{red_in},green{green_in},blue{blue_in}{}
      //virtual ~abc_color(){}
      rgb_color<unsigned char> get_uchar_rgb() const
      {
        return rgb_color<unsigned char>{red,green,blue};
      }
      ptr clone() const {
         ptr p {new uchar_rgb_color{red,green,blue}};
         return p;
      }
      unsigned char red;
      unsigned char green;
      unsigned char blue;
   };

}}// quan::gx

#endif // QUAN_GX_UCHAR_RGB_COLOR_HPP_INCLUDED
