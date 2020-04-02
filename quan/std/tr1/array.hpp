#ifndef QUAN_STD_TR1_ARRAY_HPP_INCLUDED
#define QUAN_STD_TR1_ARRAY_HPP_INCLUDED

#include <quan/config.hpp>

#if defined QUAN_USE_QUAN_STD_TR1

namespace std{

   template<typename T, unsigned int N>
   struct array{
      static constexpr unsigned int size() { return N;}
      template <typename ... Args>
      constexpr array( Args const & ... args)
      : m_array{args...}{}
      template <typename ... Args>
      constexpr array( Args && ... args)
      : m_array{args...}{}
      T & operator[](int i) { return m_array[i];}
      constexpr T const & operator[](int i)const { return m_array[i];}
      T m_array[N];
   };

}// std

#else
#include <array>
#endif

#endif // QUAN_STD_TR1_ARRAY_HPP_INCLUDED
