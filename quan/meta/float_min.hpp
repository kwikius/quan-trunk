#ifndef QUAN_META_FLOAT_MIN_HPP_INCLUDED
#define QUAN_META_FLOAT_MIN_HPP_INCLUDED

/*
 largest negative number
*/
#include <quan/config.hpp>
#ifndef __AVR__
#include <cfloat>
#else
  #include <float.h>
#endif

namespace quan{ namespace meta{

      template<typename T> struct float_min;

      template<> struct float_min<float>{
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         float operator() ()const
         {
            return -FLT_MAX;
         }
      };

       template<> struct float_min<double>{
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         double operator() ()const
         {
            return -DBL_MAX;
         }
      };

}}


#endif // QUAN_META_FLOAT_MIN_HPP_INCLUDED
