#ifndef QUAN_GX_SIMPLE_DRAWING_HPP_INCLUDED
#define QUAN_GX_SIMPLE_DRAWING_HPP_INCLUDED

#include <vector>

#include <quan/gx/drawing.hpp>

namespace quan{ namespace gx{

   template <typename LengthType>
   struct simple_drawing : drawing<LengthType>{
      typedef LengthType length_type;
      typedef quan::two_d::vect<length_type> vect;
      simple_drawing(vect const & size, vect const & origin = quan::two_d::vect<length_type>{})
      :m_size(size),m_origin(origin){}
      vect get_size() const {return m_size;}
      vect& get_size_ref(){return m_size;}
      vect const & get_size_cref()const {return m_size;}
      // the origin of the drawing relative to dead center
      vect get_origin() const {return m_origin;}
      vect set_size(vect const & v) { this->m_size = v;}
      vect set_origin(vect const & v) { this->m_origin = v;}
      //vect & get_scale_ref(){ return m_scale;}
   private:
      vect m_size;
      vect m_origin;
   };

}}//quan::gx

#endif
