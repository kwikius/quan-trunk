#ifndef QUAN_MINMAXPAIR_HPP_INCLUDED
#define QUAN_MINMAXPAIR_HPP_INCLUDED
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

#include <quan/config.hpp>
#include <quan/meta/binary_op.hpp>

namespace quan{ 

   template <typename Min, typename Max = Min>
   struct minmaxpair{
      minmaxpair(Min const & min_in, Max const & max_in)
      : min(min_in), max(max_in){}
      minmaxpair(){}
      Min min;
      Max max;
   };
   
   template <typename MinL, typename MaxL, typename MinR, typename MaxR>
   inline
   minmaxpair<
      typename quan::meta::binary_op<
         MinL,quan::meta::minus,MinR
      >::type,
       typename quan::meta::binary_op<
         MaxL,quan::meta::minus,MaxR
      >::type
   >
   operator -(minmaxpair<MinL,MaxL> const & lhs, minmaxpair<MinR,MaxR> const & rhs)
   { 
      typedef minmaxpair<
          typename quan::meta::binary_op<MinL,quan::meta::minus,MinR >::type,
          typename quan::meta::binary_op<MaxL,quan::meta::minus,MaxR>::type
      > result_type;
     return result_type(lhs.min - rhs.min,lhs.max- rhs.max);
   }
   
}

#endif
