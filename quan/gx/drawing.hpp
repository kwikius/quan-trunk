
#ifndef QUAN_GX_DRAWING_HPP_INCLUDED
#define QUAN_GX_DRAWING_HPP_INCLUDED
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

   template <typename LengthType>
   struct drawing{
      virtual ~drawing(){}
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      // the x, y dimensions of the drawing
      virtual vect get_size() const =0;
      // the origin of the drawing relative to dead center
      virtual vect get_origin() const =0;
   };

}}//quan::gx

#endif
