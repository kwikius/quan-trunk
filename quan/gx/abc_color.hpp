#ifndef QUAN_GX_COLOR_HPP_INCLUDED
#define QUAN_GX_COLOR_HPP_INCLUDED
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

#if ! defined __MBED__
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
#endif
