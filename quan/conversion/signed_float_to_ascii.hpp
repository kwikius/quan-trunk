#ifndef QUAN_CONVERSION_SIGNED_FLOAT_TO_ASCII_HPP_INCLUDED
#define QUAN_CONVERSION_SIGNED_FLOAT_TO_ASCII_HPP_INCLUDED

#include <quan/conversion/float_to_ascii.hpp>

namespace quan{

   template <uint32_t NumDecimals>
   inline constexpr size_t get_signed_float_to_ascii_buf_size()
   {
      return get_float_to_ascii_buf_size<NumDecimals>() + 1U;
   }

   
   template <uint8_t Decimals>
   inline int32_t signed_float_to_ascii (double const & in, char* outbuf)
   {
      double abs_in = std::abs(in);
      outbuf[0] = (in >= 0.0) ? ' ': '-';
      return float_to_ascii<Decimals>(abs_in,outbuf + 1);
   }
}


#endif // QUAN_CONVERSION_SIGNED_FLOAT_TO_ASCII_HPP_INCLUDED
