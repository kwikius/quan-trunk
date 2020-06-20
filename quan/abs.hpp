#ifndef QUAN_ABS_HPP_INCLUDED
#define QUAN_ABS_HPP_INCLUDED

#include <type_traits>

namespace quan{

   template<typename T>
   constexpr inline
   typename quan::where_<std::is_arithmetic<T> ,T>::type
   abs(T const & in)
   {
      return (in >= T{0}) ? in:-in;
   }
}

#endif // QUAN_ABS_HPP_INCLUDED
