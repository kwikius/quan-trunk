#ifndef QUAN_GX_DRAWING_VIEW_HPP_INCLUDED
#define QUAN_GX_DRAWING_VIEW_HPP_INCLUDED

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
