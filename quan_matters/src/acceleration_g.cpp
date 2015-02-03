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

//
 
 
 
//
// See QUAN_ROOT/quan_matters/index.html for documentation.

#ifndef QUAN_FIXED_QUANTITY_ACCELERATION_G_CPP_INCLUDED
#define QUAN_FIXED_QUANTITY_ACCELERATION_G_CPP_INCLUDED

#include <quan/acceleration.hpp>


namespace quan{
// gravitational constant S.I units

   template<>
    acceleration_<float>::m_per_s2 const
   acceleration_<float>::g 
   = acceleration_<float>::m_per_s2(9.80665f);

   template<>
   acceleration_<double>::m_per_s2 const
   acceleration_<double>::g
   = acceleration_<double>::m_per_s2(9.80665);

   template<>
   acceleration_<int>::m_per_s2 const
   acceleration_<int>::g
   = acceleration_<int>::m_per_s2(10);

}


#endif

