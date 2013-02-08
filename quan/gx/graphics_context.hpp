#ifndef  QUAN_GX_GRAPHICS_CONTEXT_HPP_INCLUDED
#define  QUAN_GX_GRAPHICS_CONTEXT_HPP_INCLUDED

// Copyright Andrew Little 2008

// See QUAN_ROOT/quan_matters/index.html for documentation.

#include <quan/gx/primitives/simple_line.hpp>
#include <quan/gx/primitives/polyline.hpp>
#include <quan/gx/primitives/box.hpp>
#include <quan/gx/primitives/simple_text.hpp>
#include <quan/gx/primitives/circle.hpp>
#include <quan/gx/static_rgb_color.hpp>

#include <quan/two_d/vect.hpp>

namespace quan{ namespace gx{

   template <typename LengthType>
   struct graphics_context{
 
      graphics_context(){}
      virtual ~graphics_context(){}
      typedef LengthType length_type;

      virtual void draw_line(primitives::simple_line<length_type> const & ) const= 0;
      virtual void draw_polyline(primitives::polyline<length_type> const & ) const= 0;
      virtual void draw_box(primitives::box<length_type> const & ) const= 0;
      virtual void draw_text(primitives::simple_text<length_type> const & ) const= 0;
      virtual void draw_circle(primitives::circle<length_type> const & ) const= 0;

   };

}}

#endif
