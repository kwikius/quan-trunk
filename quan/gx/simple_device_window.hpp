#ifndef QUAN_GX_SIMPLE_DEVICE_WINDOW_HPP_INCLUDED
#define QUAN_GX_SIMPLE_DEVICE_WINDOW_HPP_INCLUDED

#include <quan/gx/device_window.hpp>

namespace quan{ namespace gx{
  
   struct simple_device_window : device_window{
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
