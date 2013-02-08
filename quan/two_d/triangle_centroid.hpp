#ifndef QUAN_TWO_D_TRIANGLE_CENTROID_HPP_INCLUDED
#define QUAN_TWO_D_TRIANGLE_CENTROID_HPP_INCLUDED

#include <quan/two_d/vect.hpp>

/*
 centroid or centre of area of a triangle
*/

namespace quan{
namespace two_d{

    template <typename T>
    inline
    vect<T> 
    triangle_centroid(vect<T> const & p1, vect<T> const & p2, vect<T> const & p3)
   {
      return (p1 + p2 + p3) / 3;
   }

}}

#endif // QUAN_TWO_D_TRIANGLE_CENTROID_HPP_INCLUDED
