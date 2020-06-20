#ifndef QUAN_SIGN_HPP_INCLUDED
#define QUAN_SIGN_HPP_INCLUDED

namespace quan{

   template <typename T>
   constexpr inline
   int sign( T const & v)
   {
      return (v >= T{0}) ? 1: -1;
   }

} // quan

#endif // QUAN_SIGN_HPP_INCLUDED
