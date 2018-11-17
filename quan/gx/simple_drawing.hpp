#ifndef QUAN_GX_SIMPLE_DRAWING_HPP_INCLUDED
#define QUAN_GX_SIMPLE_DRAWING_HPP_INCLUDED
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
      void set_size(vect const & v) { this->m_size = v;}
      void set_origin(vect const & v) { this->m_origin = v;}
      //vect & get_scale_ref(){ return m_scale;}
   private:
      vect m_size;
      vect m_origin;
   };

}}//quan::gx

#endif
