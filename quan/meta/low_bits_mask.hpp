#ifndef QUAN_META_LOW_BITS_MASK_HPP_INCLUDED
#define QUAN_META_LOW_BITS_MASK_HPP_INCLUDED
/*
 Copyright (c) 2006-2013 Andy Little 

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>
*/

#include <cstdint>
#include <quan/bit.hpp>

namespace quan{ namespace meta{

   template <uint32_t N> struct low_bits_mask;

     template<> struct low_bits_mask<0>{
          static const uint32_t value = 0;
     };

     template <uint32_t N> struct low_bits_mask{
        static const uint32_t value = quan::bit<uint32_t>(N-1) | low_bits_mask<N-1>::value;
     };

}} // quan::meta

#endif // QUAN_META_LOW_BITS_MASK_HPP_INCLUDED
