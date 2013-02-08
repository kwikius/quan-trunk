
#ifndef QUAN_GX_DRAWING_HPP_INCLUDED
#define QUAN_GX_DRAWING_HPP_INCLUDED

#include <quan/two_d/vect.hpp>

namespace quan{ namespace gx{

   template <typename LengthType>
   struct drawing{
      virtual ~drawing(){}
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      virtual vect& get_size_ref()=0;
      virtual vect const & get_size_cref()const=0;
      // the x, y dimensions of the drawing
      virtual vect get_size() const =0;
      // the origin of the drawing relative to dead center
      virtual vect get_origin() const =0;
   };

}}//quan::gx

#endif
