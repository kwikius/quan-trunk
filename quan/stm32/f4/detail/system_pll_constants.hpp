#ifndef QUAN_STM32_F4_SYSTEM_PLL_CONSTANTS_HPP_INCLUDED
#define QUAN_STM32_F4_SYSTEM_PLL_CONSTANTS_HPP_INCLUDED
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

// NB This is not quite same formula as in refman (order of division is different), 
// but if you read the refman docs it makes sense. Input to pll is a division of input clk then multiplied
// also appears this way in startup source
// pll_vco = (QUAN_STM32F4_SOURCE_CLOCK_Hz/ pllm) * plln 
// pllm = QUAN_STM32F4_SOURCE_CLOCK_Hz / QUAN_STM32F4_PLL_VCO_INPUT_Hz where 2<= pllm <= 63 
// pll_vco =  QUAN_STM32F4_SYSCLK_Hz * pllp where pllp = 2 or 4 or 6 or 8, and 64 MHz <= pll_vco <= 432 MHz 
// plln = pll_vco / QUAN_STM32F4_PLL_VCO_INPUT_Hz; where 64 <= plln <= 432 

#include <quan/stm32/f4/config.hpp>

#include <cstdint>
#include <quan/undefined.hpp>
#include <quan/meta/eval_if.hpp>
#include <quan/meta/identity.hpp>
#include <quan/meta/gcd.hpp>

namespace quan { namespace stm32{ namespace detail{
#if 0
   template <uint32_t N>
   struct system_pll_constants_impl;

   //out of range specialisation
   template <>
   struct system_pll_constants_impl<10>{
      typedef quan::undefined type;
   };

   struct derive_pll_vco_input{

      template <uint32_t V ,uint32_t D=1>
      struct halve_if_gt
      {
          static constexpr uint32_t value = V / D ;
          static_assert( (V % D) == 0 , "failure in division");
          typedef typename quan::meta::eval_if_c< 
               (value <=2000000), quan::meta::identity<halve_if_gt>,
                halve_if_gt<V,( D * 2 )>
          >::type type;
      };
     static constexpr uint32_t value = halve_if_gt<
         quan::meta::gcd<uint32_t,QUAN_STM32_SOURCE_CLOCK_Hz,QUAN_STM32_SYSCLK_Hz>::value
     >::type::value;
   };
  
   template <uint32_t N>
   struct system_pll_constants_impl{
      static constexpr uint32_t pll_vco_in = derive_pll_vco_input::value;
      static_assert( ( pll_vco_in >= 1000000) && (pll_vco_in <= 2000000),
      "pll_vco_in must be between 1000000 and 2000000");

      static constexpr uint32_t pllp = N;
      static constexpr uint32_t pll_vco = static_cast<uint32_t>(QUAN_STM32_SYSCLK_Hz) * pllp;

      static constexpr uint32_t plln = pll_vco / pll_vco_in;
      // recurse through pllp of 2,4,6,8 if necessary
      typedef typename quan::meta::eval_if_c<
         ( (pll_vco >= 64000000) && (pll_vco <= 432000000) && (plln >= 64) && ( plln <= 432))
        ,quan::meta::identity<system_pll_constants_impl<N> >
        ,system_pll_constants_impl<N+2>
      >::type type ;
      static_assert( !std::is_same<type,quan::undefined>::value,"failed to terminate pll calculation, check input define values"); 
   };

   struct system_pll_constants : system_pll_constants_impl<2>::type{

      static constexpr uint32_t  pllm = static_cast<uint32_t>(QUAN_STM32_SOURCE_CLOCK_Hz) / pll_vco_in;

      static_assert( (pllm >= 2 ) && (pllm <= 63) ,"pllm out of range");

      // sanity check
      static_assert(static_cast<uint32_t>(QUAN_STM32_SYSCLK_Hz) == ((static_cast<uint32_t>(QUAN_STM32_SOURCE_CLOCK_Hz) / pllm) * plln ) / pllp ,
         "pll calculation failed, check input defines");
      typedef system_pll_constants type;
      
      static constexpr uint32_t pllq = pll_vco / 48000000;
      static_assert( (pll_vco % 48000000) == 0 , "pll calc usb clock remainder in division");
      static_assert( (pllq >= 2) && (pllq <= 15) ,"pllq out of range");
   };
#else
   #if QUAN_STM32_SOURCE_CLOCK_Hz == 8000000
      #if QUAN_STM32_SYSCLK_Hz == 168000000
         struct system_pll_constants {
            static constexpr uint32_t pllm = 4;
            static constexpr uint32_t plln = 168;
            static constexpr uint32_t pllp = 2;
            static constexpr uint32_t pllq = 7;
         };
     #elif QUAN_STM32_SYSCLK_Hz == 96000000
        struct system_pll_constants {
            static constexpr uint32_t pllm = 7;
            static constexpr uint32_t plln = 336;
            static constexpr uint32_t pllp = 4;
            static constexpr uint32_t pllq = 8;
         };
     #elif  QUAN_STM32_SYSCLK_Hz == 84000000
        struct system_pll_constants {
            static constexpr uint32_t pllm = 4;
            static constexpr uint32_t plln = 168;
            static constexpr uint32_t pllp = 4;
            static constexpr uint32_t pllq = 7;
        };
     #elif QUAN_STM32_SYSCLK_Hz == 72000000
        struct system_pll_constants {
            static constexpr uint32_t pllm = 4;
            static constexpr uint32_t plln = 72;
            static constexpr uint32_t pllp = 2;
            static constexpr uint32_t pllq = 3;
         };
     #else
     #endif
   #endif
#endif

}}} // quan::stm32::detail


#endif // QUAN_STM32_F4_SYSTEM_PLL_CONSTANTS_HPP_INCLUDED
