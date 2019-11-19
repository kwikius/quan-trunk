#ifndef QUAN_STM32_L4_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED
#define QUAN_STM32_L4_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED
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

#ifndef QUAN_STM32L4
#error dont include directly
#endif

#include <quan/stm32/tim/typedefs.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/bool/false.hpp>

/*
TIM1
TIM2
TIM6
TIM7  (not on STM32L412xx)
TIM15
TIM16
LPTIM
*/

namespace quan{ namespace stm32{ namespace tim{ namespace detail{

   template <typename TimerModule> struct has_cr2  : quan::meta::true_{};
   template <typename TimerModule> struct has_smcr  : quan::meta::true_{};
   // all have dier
   template <typename TimerModule> struct has_ccmr1  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccmr2  : quan::meta::false_{};
   template <typename TimerModule> struct has_ccmr3  : quan::meta::false_{};

   template <typename TimerModule> struct has_ccer  : quan::meta::true_{};
   template <typename TimerModule> struct has_rcr  : quan::meta::true_{};

   template <typename TimerModule> struct has_ccr1  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccr2  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccr3  : quan::meta::false_{};
   template <typename TimerModule> struct has_ccr4  : quan::meta::false_{};
   template <typename TimerModule> struct has_ccr5  : quan::meta::false_{};
   template <typename TimerModule> struct has_ccr6  : quan::meta::false_{};

   template <typename TimerModule> struct has_bdtr  : quan::meta::true_{};
   template <typename TimerModule> struct has_dcr  : quan::meta::true_{};
   template <typename TimerModule> struct has_dmar  : quan::meta::true_{};
   template <typename TimerModule> struct has_or1  : quan::meta::true_{};
   template <typename TimerModule> struct has_or2  : quan::meta::true_{};
   template <typename TimerModule> struct has_or3  : quan::meta::false_{};

   template <typename TimerModule> struct is_32_bit_timer : quan::meta::false_{};

   template<> struct is_32_bit_timer<quan::stm32::tim2> : quan::meta::true_{};
//cr2 1 default : true
 
// smcr defualt : true
   template<> struct has_smcr<quan::stm32::tim6>  : quan::meta::false_{};

#if QUAN_STM32_HAS_TIM7 
   template<> struct has_smcr<quan::stm32::tim7>  : quan::meta::false_{};
#endif

   template<> struct has_smcr<quan::stm32::tim16>  : quan::meta::false_{};

//ccmr1  default true
   template<> struct has_ccmr1<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_ccmr1<quan::stm32::tim7>  : quan::meta::false_{};
#endif
//ccmr2  default false
   template<> struct has_ccmr2<quan::stm32::tim1>  : quan::meta::true_{};
   template<> struct has_ccmr2<quan::stm32::tim2>  : quan::meta::true_{};

//ccer 1 default: true
   template<> struct has_ccer<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_ccer<quan::stm32::tim7>  : quan::meta::false_{};
#endif
//rcr 1 default : true
   template<> struct has_rcr<quan::stm32::tim2>  : quan::meta::false_{};
   template<> struct has_rcr<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_rcr<quan::stm32::tim7>  : quan::meta::false_{};
#endif
//ccr1  default : true
   template<> struct has_ccr1<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_ccr1<quan::stm32::tim7>  : quan::meta::false_{};
#endif
//ccr2 default : true
   template<> struct has_ccr2<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_ccr2<quan::stm32::tim7>  : quan::meta::false_{};
#endif
   template<> struct has_ccr2<quan::stm32::tim16>  : quan::meta::false_{};

//ccr3 0 default : false
   template<> struct has_ccr3<quan::stm32::tim1>  : quan::meta::true_{};
   template<> struct has_ccr3<quan::stm32::tim2>  : quan::meta::true_{};

// ccr4 default : false
   template<> struct has_ccr4<quan::stm32::tim1>  : quan::meta::true_{};
   template<> struct has_ccr4<quan::stm32::tim2>  : quan::meta::true_{};

// ccr5 default : false
   template<> struct has_ccr5<quan::stm32::tim1>  : quan::meta::true_{};
//ccr6 default : false
   template<> struct has_ccr6<quan::stm32::tim1>  : quan::meta::true_{};
//bdtr  default : true
   template<> struct has_bdtr<quan::stm32::tim2>  : quan::meta::false_{};
   template<> struct has_bdtr<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_bdtr<quan::stm32::tim7>  : quan::meta::false_{};
#endif

// dcr  default : true
   template<> struct has_dcr<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_dcr<quan::stm32::tim7>  : quan::meta::false_{};
#endif

//dmar default: true
   template<> struct has_dmar<quan::stm32::tim6>  : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_dmar<quan::stm32::tim7>  : quan::meta::false_{};
#endif

// or1 default true
   template<> struct has_or1<quan::stm32::tim6> : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_or1<quan::stm32::tim7> : quan::meta::false_{};
#endif

// or2 default true
   template<> struct has_or2<quan::stm32::tim6> : quan::meta::false_{};
#if QUAN_STM32_HAS_TIM7
   template<> struct has_or2<quan::stm32::tim7> : quan::meta::false_{};
#endif

// or3 default false
   template<> struct has_or1<quan::stm32::tim1> : quan::meta::true_{};

}}}}//quan::stm32::tim::detail


#endif // QUAN_STM32_L4_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED
