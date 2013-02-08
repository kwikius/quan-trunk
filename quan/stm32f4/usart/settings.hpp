#ifndef QUAN_STM32F4_USART_SETTINGS_HPP_INCLUDED
#define QUAN_STM32F4_USART_SETTINGS_HPP_INCLUDED

#include <quan/is_model_of.hpp>
#include <quan/meta/bool/true.hpp>
#include <quan/meta/push_back.hpp>
#include <quan/stm32f4/detail/make_boolean_action.hpp>
#include <quan/stm32f4/detail/periph_reg_actions.hpp>
#include <quan/undefined.hpp>
#include <quan/stm32f4/usart/detail/get_bus.hpp>
#include <quan/stm32f4/usart/detail/get_baud_rate_values.hpp>

namespace quan{ namespace stm32f4{ namespace usart{

   struct Setting; // Concept

   namespace detail{

      template <typename S>
      struct setting_to_actions;

   }

   template <bool Value> struct transmitter{};

   namespace detail{
      // action true =  cr1 |= TE  where TE = bit(3)
      // action false  = cr1 &= ~RE
      template <bool Value>
      struct setting_to_actions<quan::stm32f4::usart::transmitter<Value> >{

         template <typename ListOfActions,typename U> struct apply{
            typedef typename quan::stm32f4::detail::make_boolean_action<
               Value, typename U::cr1_type,3
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };
   }//detail
  
   template <bool Value> struct receiver{};

   namespace detail{
      // action true =  cr1 |= RE  where RE = bit(2)
      // action false  = cr1 &= ~RE
      template <bool Value>
      struct setting_to_actions<quan::stm32f4::usart::receiver<Value> >{

          template <typename ListOfActions,typename U> struct apply{
             typedef typename quan::stm32f4::detail::make_boolean_action<
                 Value, typename U::cr1_type,2
             >::type action_type;
             typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };
   }

   template <bool Value> struct synchronous_mode{};
   typedef synchronous_mode<true> synchronous;
   typedef synchronous_mode<false> asynchronous;

   namespace detail{
      // action true cr2  |= clken  CLKEN = bit(11)
      // action false cr2 &= ~ CLKEN
      template <bool Value>
      struct setting_to_actions<quan::stm32f4::usart::synchronous_mode<Value> >{

         template <typename ListOfActions,typename U> struct apply{
            typedef typename quan::stm32f4::detail::make_boolean_action<
               Value, typename U::cr2_type,11
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

   }
  
   struct parity{

         struct none;
         struct odd;
         struct even;
   };

   namespace detail{
   /*
    cr1 PCE  0 = parity control disabled 1 enambled bit(10)
    pdd parity PS = 1, even == 0 PS = bit(9)
   */
      template<> 
      struct setting_to_actions<quan::stm32f4::usart::parity::none> {

         template <typename ListOfActions,typename U> struct apply {
            typedef typename quan::stm32f4::detail::make_boolean_action<
               false, typename U::cr1_type,10
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };

      };

      template<> 
      struct setting_to_actions<quan::stm32f4::usart::parity::odd> {
         template <typename ListOfActions,typename U> struct apply{
           typedef typename U::value_type value_type;
           static constexpr value_type mask_value = quan::bit<value_type>(10) | quan::bit<value_type>(9);
           typedef quan::stm32f4::detail::periph_reg_action<typename U::cr1_type,quan::meta::bit_or,mask_value> action_type;
           typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

      template<> 
      struct setting_to_actions<quan::stm32f4::usart::parity::even>{
         template <typename ListOfActions,typename U> struct apply{
            typedef typename U::value_type value_type;
            typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::cr1_type,quan::meta::bit_or,quan::bit<value_type>(10)
            > or_action_type;
            typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::cr1_type,quan::meta::bit_and,~quan::bit<value_type>(9)
            > and_action_type;
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;;
            typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
         };
       };

   }//detail

   template <uint32_t Value> struct data_bits{};

   namespace detail{
      //cr1 M ( bit(12)  0 = 8 bits , 1 = 9 bits
      template<> 
      struct setting_to_actions<quan::stm32f4::usart::data_bits<8> >{
             template <typename ListOfActions,typename U> struct apply {
            typedef typename quan::stm32f4::detail::make_boolean_action<
               false, typename U::cr1_type,12
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

      template<> 
      struct setting_to_actions<quan::stm32f4::usart::data_bits<9> >{
             template <typename ListOfActions,typename U> struct apply {
            typedef typename quan::stm32f4::detail::make_boolean_action<
               true, typename U::cr1_type,12
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };
   }

   template <uint32_t BaudRate, bool Over8 = false > struct baud_rate{};
   namespace detail{

      template <uint32_t BaudRate, bool Over8>
      struct setting_to_actions<quan::stm32f4::usart::baud_rate<BaudRate,Over8> >{

         template <typename ListOfActions,typename U> struct apply {

            typedef typename quan::stm32f4::detail::make_boolean_action<
               Over8, typename U::cr1_type,15
            >::type over8_type;

            typedef quan::stm32f4::usart::detail::get_baud_rate_values<U,BaudRate,Over8> reg_values;
            typedef typename U::value_type value_type;

            static constexpr value_type mask = (reg_values::mantissa << 4) | reg_values::fraction ;
             typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::brr_type,quan::meta::equals,mask
            > action_type;

            typedef typename quan::meta::push_back<ListOfActions,over8_type>::type list1_type;
            typedef typename quan::meta::push_back<list1_type,action_type>::type type;

         };

      };
   }
   template <uint32_t N, uint32_t D = 1>
   struct stop_bits{
     // cr2 bits 13:12
       // can be one <1,2>, <1> , <3,2>  <2>
   };
   namespace detail{

/*
00: 1 Stop bit
01: 0.5 Stop bit
10: 2 Stop bits
11: 1.5 Stop bit

*/
      template <>
      struct setting_to_actions<quan::stm32f4::usart::stop_bits<1,2> >{
         // 0,1
         template <typename ListOfActions,typename U> struct apply{
            typedef typename U::value_type value_type;
            typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_or,quan::bit<value_type>(12)
            > or_action_type;
            typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_and,~quan::bit<value_type>(13)
            > and_action_type;
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;;
            typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
         };
      };

      template <>
      struct setting_to_actions<quan::stm32f4::usart::stop_bits<1> >{
         //0,0
         template <typename ListOfActions,typename U> struct apply{
           typedef typename U::value_type value_type;
           static constexpr value_type mask_value = ~(quan::bit<value_type>(12) | quan::bit<value_type>(13));
           typedef quan::stm32f4::detail::periph_reg_action<typename U::cr2_type,quan::meta::bit_and,mask_value> action_type;
           typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

      template <>
      struct setting_to_actions<quan::stm32f4::usart::stop_bits<3,2> >{
         //1,1
          template <typename ListOfActions,typename U> struct apply{
           typedef typename U::value_type value_type;
           static constexpr value_type mask_value = (quan::bit<value_type>(12) | quan::bit<value_type>(13));
           typedef quan::stm32f4::detail::periph_reg_action<typename U::cr2_type,quan::meta::bit_or,mask_value> action_type;
           typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

      template <>
      struct setting_to_actions<quan::stm32f4::usart::stop_bits<2> >{
         // 0,1
         template <typename ListOfActions,typename U> struct apply{
            typedef typename U::value_type value_type;
            typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_or,quan::bit<value_type>(13)
            > or_action_type;
            typedef typename quan::stm32f4::detail::periph_reg_action<
               typename U::cr2_type,quan::meta::bit_and,~quan::bit<value_type>(12)
            > and_action_type;
            typedef typename quan::meta::push_back<ListOfActions,or_action_type>::type list_of_actions1_type;;
            typedef typename quan::meta::push_back<list_of_actions1_type,and_action_type>::type type;
         };
      };

   }

   template <bool B>
   struct rts{
       static constexpr bool value = B;
   };

   namespace detail{
         
      template <bool Value>
      struct setting_to_actions<quan::stm32f4::usart::rts<Value> >{

         template <typename ListOfActions,typename U> struct apply{
            typedef typename quan::stm32f4::detail::make_boolean_action<
               Value, typename U::cr3_type,8
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

   } 

   template <bool B>
   struct cts{
       static constexpr bool value = B;
   };

    namespace detail{
         
      template <bool Value>
      struct setting_to_actions<quan::stm32f4::usart::cts<Value> >{

         template <typename ListOfActions,typename U> struct apply{
            typedef typename quan::stm32f4::detail::make_boolean_action<
               Value, typename U::cr3_type,9
            >::type action_type;
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;
         };
      };

   } 

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

   namespace detail{

     #define QUAN_STM32F4_SETTING_TO_ACTION(Struct, Register, Bit) \
      template <bool Value>\
      struct setting_to_actions<quan::stm32f4::usart::i_en:: Struct <Value> >{\
         template <typename ListOfActions,typename U> struct apply{\
            typedef typename quan::stm32f4::detail::make_boolean_action<\
               Value, typename U:: Register ## _type, Bit \
            >::type action_type;\
            typedef typename quan::meta::push_back<ListOfActions,action_type>::type type;\
         };\
      };

      QUAN_STM32F4_SETTING_TO_ACTION(cts   , cr3,10)
      QUAN_STM32F4_SETTING_TO_ACTION(lbd   , cr2, 6)
      QUAN_STM32F4_SETTING_TO_ACTION(txe   , cr1,7)
      QUAN_STM32F4_SETTING_TO_ACTION(tc    , cr1,6)
      QUAN_STM32F4_SETTING_TO_ACTION(rxne  , cr1,5)
      QUAN_STM32F4_SETTING_TO_ACTION(idle  , cr1,4)
      QUAN_STM32F4_SETTING_TO_ACTION(pe    , cr1,8)
      QUAN_STM32F4_SETTING_TO_ACTION(error , cr3,0)

     #undef QUAN_STM32F4_SETTING_TO_ACTION
   }
       
}}}

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
