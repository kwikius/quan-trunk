#ifndef QUAN_THREE_D_OUT_VECTOR_FIELD_HPP_INCLUDED
#define QUAN_THREE_D_OUT_VECTOR_FIELD_HPP_INCLUDED
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

#include <quan/three_d/vector_field.hpp>

namespace quan{namespace three_d{

    template<typename Vect,typename Pos>
    inline std::ostream &
    operator << (std::ostream & os, vector_field<Vect,Pos> const & in)
   {
      os << '{' << in.pos << ',' << in.vect << '}';
      return os;
   }

}}

#endif
