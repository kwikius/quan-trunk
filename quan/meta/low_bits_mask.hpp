#ifndef QUAN_META_LOW_BITS_MASK_HPP_INCLUDED
#define QUAN_META_LOW_BITS_MASK_HPP_INCLUDED

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
