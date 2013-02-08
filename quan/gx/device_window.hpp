#ifndef QUAN_GX_DEVICE_WINDOW_HPP_INCLUDED
#define QUAN_GX_DEVICE_WINDOW_HPP_INCLUDED

#include <quan/two_d/vect.hpp>
#include <quan/length.hpp>
#include <quan/reciprocal_length.hpp>

namespace quan{ namespace gx{
  
   struct device_window{
      // current size of client area of pane in px
      virtual quan::two_d::vect<int>  get_size_in_px() const = 0;
      // current size of client area of pane in mm
      virtual quan::two_d::vect<quan::length::mm> get_size_in_mm() const = 0;

      quan::two_d::vect<quan::reciprocal_length::per_mm> get_px_per_mm() const
      {
           quan::two_d::vect<quan::length::mm> mm = get_size_in_mm();
           quan::two_d::vect<int> px = get_size_in_px();
           return quan::two_d::vect<quan::reciprocal_length::per_mm>{
               px.x/mm.x,
               px.y/mm.y
           };
      } 

      quan::two_d::vect<quan::length::mm> get_mm_per_px() const
      {
           quan::two_d::vect<quan::length::mm> mm = get_size_in_mm();
           quan::two_d::vect<int> px = get_size_in_px();
           return quan::two_d::vect<quan::length::mm>{
               mm.x/px.x,
               mm.y/px.y
           };
      }
      
      virtual ~device_window(){}
   };

}}

#endif
