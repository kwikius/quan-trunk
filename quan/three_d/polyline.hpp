#ifndef QUAN_THREE_D_POLYLINE_HPP_INCLUDED
#define QUAN_THREE_D_POLYLINE_HPP_INCLUDED
#if (defined _MSC_VER) && (_MSC_VER >= 1200)
#  pragma once
#endif

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
 
#include <vector>
#include <list>
#include <quan/three_d/vect.hpp>

namespace quan{namespace three_d{

   template <typename T>
   struct polyline{
      typedef typedef quan::three_d::vect<double> point_type;
      private:
      std::list<point_type> m_points;
   };

}}}///quan::three_d


#endif
