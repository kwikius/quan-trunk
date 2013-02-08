#ifndef QUAN_THREE_D_OUT_VECTOR_FIELD_HPP_INCLUDED
#define QUAN_THREE_D_OUT_VECTOR_FIELD_HPP_INCLUDED

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
