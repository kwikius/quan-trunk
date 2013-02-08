#ifndef QUAN_STM32F4_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED
#define QUAN_STM32F4_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED

#include <quan/stm32f4/tim_typedefs.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/bool/false.hpp>

namespace quan{ namespace stm32f4{ namespace tim{ namespace detail{

   template <typename TimerModule> struct has_cr2  : quan::meta::true_{};
   template <typename TimerModule> struct has_smcr  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccmr1  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccmr2  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccer  : quan::meta::true_{};
   template <typename TimerModule> struct has_rcr  : quan::meta::false_{};

   template <typename TimerModule> struct has_ccr1  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccr2  : quan::meta::true_{};
   template <typename TimerModule> struct has_ccr3  : quan::meta::false_{};
   template <typename TimerModule> struct has_ccr4  : quan::meta::false_{};
   template <typename TimerModule> struct has_bdtr  : quan::meta::false_{};
   template <typename TimerModule> struct has_dcr  : quan::meta::false_{};
   template <typename TimerModule> struct has_dmar  : quan::meta::false_{};
   template <typename TimerModule> struct has_or_  : quan::meta::true_{};

   template <typename TimerModule> struct is_32_bit_timer : quan::meta::false_{};

   template<> struct is_32_bit_timer<quan::stm32f4::tim2> : quan::meta::true_{};
   template<> struct is_32_bit_timer<quan::stm32f4::tim5> : quan::meta::true_{};

   template<> struct has_cr2<quan::stm32f4::tim10> : quan::meta::false_{};
   template<> struct has_cr2<quan::stm32f4::tim11> : quan::meta::false_{};
   template<> struct has_cr2<quan::stm32f4::tim13> : quan::meta::false_{};
   template<> struct has_cr2<quan::stm32f4::tim14> : quan::meta::false_{};

   template<> struct has_smcr<quan::stm32f4::tim6>  : quan::meta::false_{};
   template<> struct has_smcr<quan::stm32f4::tim7>  : quan::meta::false_{};
   template<> struct has_smcr<quan::stm32f4::tim10>  : quan::meta::false_{};
   template<> struct has_smcr<quan::stm32f4::tim11>  : quan::meta::false_{};
   template<> struct has_smcr<quan::stm32f4::tim13>  : quan::meta::false_{};
   template<> struct has_smcr<quan::stm32f4::tim14>  : quan::meta::false_{};

   template<> struct has_ccmr1<quan::stm32f4::tim6>  : quan::meta::false_{};
   template<> struct has_ccmr1<quan::stm32f4::tim7>  : quan::meta::false_{};

   template<> struct has_ccmr2<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_ccmr2<quan::stm32f4::tim2>  : quan::meta::true_{};
   template<> struct has_ccmr2<quan::stm32f4::tim3>  : quan::meta::true_{};
   template<> struct has_ccmr2<quan::stm32f4::tim4>  : quan::meta::true_{};
   template<> struct has_ccmr2<quan::stm32f4::tim5>  : quan::meta::true_{};
   template<> struct has_ccmr2<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_ccer<quan::stm32f4::tim6>  : quan::meta::false_{};
   template<> struct has_ccer<quan::stm32f4::tim7>  : quan::meta::false_{};

   template<> struct has_rcr<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_rcr<quan::stm32f4::tim2>  : quan::meta::true_{};
   template<> struct has_rcr<quan::stm32f4::tim3>  : quan::meta::true_{};
   template<> struct has_rcr<quan::stm32f4::tim4>  : quan::meta::true_{};
   template<> struct has_rcr<quan::stm32f4::tim5>  : quan::meta::true_{};
   template<> struct has_rcr<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_ccr1<quan::stm32f4::tim6>  : quan::meta::false_{};
   template<> struct has_ccr1<quan::stm32f4::tim7>  : quan::meta::false_{};

   template<> struct has_ccr2<quan::stm32f4::tim6>  : quan::meta::false_{};
   template<> struct has_ccr2<quan::stm32f4::tim7>  : quan::meta::false_{};
   template<> struct has_ccr2<quan::stm32f4::tim10>  : quan::meta::false_{};
   template<> struct has_ccr2<quan::stm32f4::tim11>  : quan::meta::false_{};
   template<> struct has_ccr2<quan::stm32f4::tim13>  : quan::meta::false_{};
   template<> struct has_ccr2<quan::stm32f4::tim14>  : quan::meta::false_{};

   template<> struct has_ccr3<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_ccr3<quan::stm32f4::tim2>  : quan::meta::true_{};
   template<> struct has_ccr3<quan::stm32f4::tim3>  : quan::meta::true_{};
   template<> struct has_ccr3<quan::stm32f4::tim4>  : quan::meta::true_{};
   template<> struct has_ccr3<quan::stm32f4::tim5>  : quan::meta::true_{};
   template<> struct has_ccr3<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_ccr4<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_ccr4<quan::stm32f4::tim2>  : quan::meta::true_{};
   template<> struct has_ccr4<quan::stm32f4::tim3>  : quan::meta::true_{};
   template<> struct has_ccr4<quan::stm32f4::tim4>  : quan::meta::true_{};
   template<> struct has_ccr4<quan::stm32f4::tim5>  : quan::meta::true_{};
   template<> struct has_ccr4<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_bdtr<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_bdtr<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_dcr<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_dcr<quan::stm32f4::tim2>  : quan::meta::true_{};
   template<> struct has_dcr<quan::stm32f4::tim3>  : quan::meta::true_{};
   template<> struct has_dcr<quan::stm32f4::tim4>  : quan::meta::true_{};
   template<> struct has_dcr<quan::stm32f4::tim5>  : quan::meta::true_{};
   template<> struct has_dcr<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_dmar<quan::stm32f4::tim1>  : quan::meta::true_{};
   template<> struct has_dmar<quan::stm32f4::tim2>  : quan::meta::true_{};
   template<> struct has_dmar<quan::stm32f4::tim3>  : quan::meta::true_{};
   template<> struct has_dmar<quan::stm32f4::tim4>  : quan::meta::true_{};
   template<> struct has_dmar<quan::stm32f4::tim5>  : quan::meta::true_{};
   template<> struct has_dmar<quan::stm32f4::tim8>  : quan::meta::true_{};

   template<> struct has_or_<quan::stm32f4::tim1> : quan::meta::false_{};
   template<> struct has_or_<quan::stm32f4::tim6> : quan::meta::false_{};
   template<> struct has_or_<quan::stm32f4::tim7> : quan::meta::false_{};
   template<> struct has_or_<quan::stm32f4::tim8> : quan::meta::false_{};
   template<> struct has_or_<quan::stm32f4::tim9> : quan::meta::false_{};
   template<> struct has_or_<quan::stm32f4::tim12> : quan::meta::false_{};

}}}}//quan::stm32f4::tim::detail


#endif // QUAN_STM32F4_TIM_DETAIL_HAS_PERIPH_REG_XX_HPP_INCLUDED
