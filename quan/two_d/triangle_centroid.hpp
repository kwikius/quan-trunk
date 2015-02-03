#ifndef QUAN_TWO_D_TRIANGLE_CENTROID_HPP_INCLUDED
#define QUAN_TWO_D_TRIANGLE_CENTROID_HPP_INCLUDED
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

/*
 centroid or centre of area of a triangle
*/

namespace quan{
namespace two_d{

    template <typename T>
    inline
    vect<T> 
    triangle_centroid(vect<T> const & p1, vect<T> const & p2, vect<T> const & p3)
   {
      return (p1 + p2 + p3) / 3;
   }

}}

#endif // QUAN_TWO_D_TRIANGLE_CENTROID_HPP_INCLUDED
