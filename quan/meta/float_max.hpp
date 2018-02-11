#ifndef QUAN_META_FLOAT_MAX_HPP_INCLUDED
#define QUAN_META_FLOAT_MAX_HPP_INCLUDED
/*
 Copyright (c) 2003-2014 Andy Little.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see http://www.gnu.org/licenses./
 */

/*
 largest negative number
*/
#include <quan/config.hpp>
#ifndef QUAN_AVR_NO_CPP_STDLIB
#include <cfloat>
#else
  #include <float.h>
#endif

namespace quan{ namespace meta{

      template<typename T> struct float_max;

      template<> struct float_max<float>{
          static constexpr float value = FLT_MAX;
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         float operator() ()const
         {
            return FLT_MAX;
         }
      };

       template<> struct float_max<double>{
         static constexpr double value = DBL_MAX;
#ifdef QUAN_HAS_CONSTEXPR
constexpr
#endif
         double operator() ()const
         {
            return DBL_MAX;
         }
      };

}}


#endif // QUAN_META_FLOAT_MIN_HPP_INCLUDED
