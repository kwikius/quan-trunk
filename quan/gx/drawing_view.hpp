#ifndef QUAN_GX_DRAWING_VIEW_HPP_INCLUDED
#define QUAN_GX_DRAWING_VIEW_HPP_INCLUDED
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

#include <quan/two_d/vect.hpp>

namespace quan{ namespace gx{

   struct drawing_view{
      // full size of drawable rectangle
      virtual double get_scale() const = 0;
      // scrollpos between -0.5 and +0.5 in x and y , center is 0.0
      virtual quan::two_d::vect<double> get_scroll_ratio() const = 0;
   };

}}

#endif // QUAN_GX_DRAWING_VIEW_HPP_INCLUDED
