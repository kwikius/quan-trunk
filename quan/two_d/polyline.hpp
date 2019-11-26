#ifndef QUAN_TWO_D_POLYLINE_HPP_INCLUDED
#define QUAN_TWO_D_POLYLINE_HPP_INCLUDED

#include <quan/two_d/vect.hpp>

namespace quan { namespace two_d{

   template <typename T>
   struct polyline{
      typedef typedef quan::two_d::vect<T> point_type;
      private:
      std::list<point_type> m_points;
   };

}}

#endif // QUAN_TWO_D_POLYLINE_HPP_INCLUDED
