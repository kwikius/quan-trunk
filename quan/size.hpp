#ifndef QUAN_SIZE_HPP_INCLUDED
#define QUAN_SIZE_HPP_INCLUDED

#include <cstddef>

namespace quan{

   template <typename T>
   inline
   constexpr auto size( const T& v ) -> decltype(v.size())
   {
      return v.size();
   }

   template <typename T, size_t N>
   inline
   constexpr 
   std::size_t 
   size( const T (&arr)[N] ) noexcept 
   {
      return N;
   }

}

#endif // QUAN_SIZE_HPP_INCLUDED
