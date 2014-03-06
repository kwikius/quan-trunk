#ifndef QUAN_STM32_USART_SETTINGS_HPP_INCLUDED
#define QUAN_STM32_USART_SETTINGS_HPP_INCLUDED

#include <quan/is_model_of.hpp>

namespace quan{ namespace stm32{ namespace usart{

/*
   The settings (esp baudrate should only be applied when usart is disabled
*/

   struct Setting; // Archetype

   template <bool Value> struct transmitter{};
   template <bool Value> struct receiver{};
   template <bool Value> struct synchronous_mode{};

   typedef synchronous_mode<true> synchronous;
   typedef synchronous_mode<false> asynchronous;

   struct parity{
         struct none;
         struct odd;
         struct even;
   };

   template <uint32_t Value> struct data_bits{};
   template <uint32_t BaudRate, bool Over8 = false > struct baud_rate{};

   template <uint32_t N, uint32_t D = 1> struct stop_bits{};
 
   template <bool B>
   struct cts{
       static constexpr bool value = B;
   };

   template <bool B>
   struct rts{
       static constexpr bool value = B;
   };

   namespace i_en {
     template <bool B> struct cts {};
     template <bool B> struct lbd {};
     template <bool B> struct txe {};
     template <bool B> struct tc {};
     template <bool B> struct rxne {};
     template <bool B> struct idle {};
     template <bool B> struct pe {};
     template <bool B> struct error {};
   }  
}}}

// make the settings all models of Setting
namespace quan{ namespace impl{

   template <bool B > struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::transmitter<B> 
   > : quan::meta::true_{};

   template <bool B > struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::receiver<B> 
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::synchronous_mode<B> 
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::parity::none
   > : quan::meta::true_{};
   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::parity::odd
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::parity::even
   > : quan::meta::true_{};

// only 8 or 9 bits available
   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::data_bits<9>
   > : quan::meta::true_{};

    template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::data_bits<8>
   > : quan::meta::true_{};


   template <uint32_t Value, bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::baud_rate<Value, B>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::stop_bits<1,2>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::stop_bits<1>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::stop_bits<3,2>
   > : quan::meta::true_{};

   template <> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::stop_bits<2>
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::rts<B>
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::cts<B>
   > : quan::meta::true_{};

   template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::cts<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::lbd<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::txe<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::tc<B>
   > : quan::meta::true_{};

  
   template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::rxne<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::idle<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::pe<B>
   > : quan::meta::true_{};

    template <bool B> struct is_model_of_impl<
      quan::stm32::usart::Setting,quan::stm32::usart::i_en::error<B>
   > : quan::meta::true_{};

}}

#endif // QUAN_STM32F4_USART_SETTINGS_HPP_INCLUDED
