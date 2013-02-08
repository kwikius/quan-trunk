#ifndef QUAN_GX_COLOR_HPP_INCLUDED
#define QUAN_GX_COLOR_HPP_INCLUDED
// Copyright Andrew Little 2008

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/config.hpp>
#include <quan/gx/rgb_color.hpp>
#include <memory>

namespace quan{ namespace gx{

   struct abc_color {
      typedef std::shared_ptr<abc_color> ptr;
      virtual ~abc_color(){}
      virtual rgb_color<unsigned char> get_uchar_rgb() const=0;
      virtual ptr clone() const = 0;
   };

}}

#endif
