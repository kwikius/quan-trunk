#ifndef QUAN_STM32_USART_SETTINGS_HPP_INCLUDED
#define QUAN_STM32_USART_SETTINGS_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/push_back.hpp>

namespace quan{ namespace impl{

   template <bool B > struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::transmitter<B> 
   > : quan::meta::true_{};

   template <bool B > struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::receiver<B> 
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::synchronous_mode<B> 
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::parity::none
   > : quan::meta::true_{};
   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::parity::odd
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::parity::even
   > : quan::meta::true_{};

// only 8 or 9 bits available
   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::data_bits<9>
   > : quan::meta::true_{};

    template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::data_bits<8>
   > : quan::meta::true_{};


   template <uint32_t Value, bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::baud_rate<Value, B>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::stop_bits<1,2>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::stop_bits<1>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::stop_bits<3,2>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::stop_bits<2>
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::rts<B>
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::cts<B>
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::cts<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::lbd<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::txe<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::tc<B>
   > : quan::meta::true_{};

  
   template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::rxne<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::idle<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::pe<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32f4::usart::Setting,quan::stm32f4::usart::i_en::error<B>
   > : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_USART_SETTINGS_HPP_INCLUDED
