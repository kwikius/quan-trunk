#ifndef QUAN_META_GET_NUME_DENOM_FUNCTIONS_HPP_INCLUDED
#define QUAN_META_GET_NUME_DENOM_FUNCTIONS_HPP_INCLUDED
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

#include <quan/meta/rational.hpp>

namespace quan{ namespace meta{

   template <int64_t N, int64_t D>
   inline
   int64_t get_numerator(rational<N,D>)
   {
      return numerator<rational<N,D> >::value;
   }
   template <int64_t N, int64_t D>
   inline
   int64_t get_denominator(rational<N,D>)
   {
      return denominator<rational<N,D> >::value;
   }
   
}}//quan::meta

#endif
