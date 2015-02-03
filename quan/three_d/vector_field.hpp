#ifndef QUAN_THREE_D_VECTOR_FIELD_HPP_INCLUDED
#define QUAN_THREE_D_VECTOR_FIELD_HPP_INCLUDED
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

#include <quan/three_d/vect.hpp>

namespace quan{ namespace three_d{

   template <typename Vect,typename Pos>
   struct vector_field{
      typedef vect<Vect> vect_type;
      typedef vect<Pos> pos_type;
      vector_field(vect_type const & vect_in,pos_type const & pos_in)
      : vect(vect_in),pos(pos_in){}
      vector_field(){}
      vect_type vect;
      pos_type pos;
      
   };

   template <typename Vect,typename Pos>
   inline
   vector_field<
      typename quan::meta::binary_op<
         Vect, quan::meta::times,Pos
      >::type,
      Pos
   >
   get_moment(vector_field<Vect,Pos> const & v)
   {
   
      typedef vector_field<
         typename quan::meta::binary_op<
            Vect, quan::meta::times,Pos
         >::type,
         Pos   
      > vf;

      typedef vect< 
         typename quan::meta::binary_op<
            Vect, quan::meta::times,Pos
         >::type 
      > vect_type;

      typedef vect<Pos> pos_type;

      return vf(
         cross_product(v.pos,v.vect),
         pos_type()
      );
   }
}}

#endif

