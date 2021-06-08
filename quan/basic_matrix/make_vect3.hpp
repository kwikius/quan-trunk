#ifndef QUAN_BASIC_MATRIX_MAKE_VECT3_HPP_INCLUDED
#define QUAN_BASIC_MATRIX_MAKE_VECT3_HPP_INCLUDED

#include <quan/basic_matrix/basic_matrix.hpp>
#include <quan/three_d/make_vect.hpp>

namespace quan{

    template <typename T>
    inline constexpr
    quan::three_d::vect<T> 
    make_vect3(basic_matrix<1,3,T> const & m)
    {
       return {m.at(0,0),m.at(0,1),m.at(0,2)};
    }

}

#endif // QUAN_BASIC_MATRIX_MAKE_VECT3_HPP_INCLUDED
