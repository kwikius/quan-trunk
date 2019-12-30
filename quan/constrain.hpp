#ifndef QUAN_CONSTRAIN_HPP_INCLUDED
#define QUAN_CONSTRAIN_HPP_INCLUDED
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

namespace quan{

   template <typename T>
   inline constexpr T constrain(T const & val, T const & min_val, T const & max_val)
   {
#if 1
   return (val >= max_val )
      ? max_val
      :(( val <= min_val)? min_val: val)
   ;
#else
      if ( val > max_val){
         return max_val;
      }else{
         if ( val < min_val){
            return min_val;
         }else{
            return val;
         }
      }
#endif
   }

} // quan

#endif // QUAN_CONSTRAIN_HPP_INCLUDED
