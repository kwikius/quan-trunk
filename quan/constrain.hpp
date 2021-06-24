#ifndef QUAN_CONSTRAIN_HPP_INCLUDED
#define QUAN_CONSTRAIN_HPP_INCLUDED

#include <quan/implicit_cast.hpp>
/*
 Copyright (c) 2003-2021 Andy Little.

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

namespace quan{

   template <typename T, typename Tmin, typename Tmax>
   inline constexpr T constrain(T const & val, Tmin const & min_val, Tmax const & max_val)
   {
      return (val >= max_val)
         ? implicit_cast<T>(max_val)
         :(( val <= min_val)? implicit_cast<T>(min_val): val)
      ;
   }

} // quan

#endif // QUAN_CONSTRAIN_HPP_INCLUDED
