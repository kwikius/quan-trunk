#ifndef QUAN_IMPLICIT_CAST_HPP_INCLUDED
#define QUAN_IMPLICIT_CAST_HPP_INCLUDED

// Copyright Andrew Little 2006-2007
#include <quan/config.hpp>
#include <quan/meta/identity.hpp>

namespace quan{
   
      template<typename T>
      QUAN_CONSTEXPR
      inline
      T implicit_cast(typename meta::identity<T>::type in)
      {
         return in;
      }
}
#endif
