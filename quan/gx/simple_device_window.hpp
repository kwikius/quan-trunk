#ifndef QUAN_GX_SIMPLE_DEVICE_WINDOW_HPP_INCLUDED
#define QUAN_GX_SIMPLE_DEVICE_WINDOW_HPP_INCLUDED
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

#include <quan/gx/device_window.hpp>

namespace quan{ namespace gx{
  
   struct simple_device_window : device_window{
      simple_device_window()
      :m_size_px{ 1,1 }
      ,m_size_mm{quan::length::mm{1},quan::length::mm{1}}
      {}
      // current size of client area of pane in px
      quan::two_d::vect<int>  get_size_in_px() const 
      { return m_size_px;}
      // current size of client area of pane in mm
      quan::two_d::vect<quan::length::mm> get_size_in_mm() const 
      { return m_size_mm; }
   //public
      quan::two_d::vect<int> m_size_px;
      quan::two_d::vect<quan::length::mm> m_size_mm;
   };

}}

#endif
