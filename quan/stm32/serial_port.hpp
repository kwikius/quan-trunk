#ifndef QUAN_STM32_SERIAL_PORT_HPP_INCLUDED
#define QUAN_STM32_SERIAL_PORT_HPP_INCLUDED

#include <type_traits>

#include <cstdint>
#include <cstring>

#include <quan/meta/if.hpp>
#include <quan/meta/or.hpp>
#include <quan/meta/and.hpp>
#include <quan/meta/bool.hpp>
#include <quan/concepts/port.hpp>

#include <quan/utility/fifo.hpp>

#include <quan/stm32/config.hpp>
#include <quan/stm32/usart.hpp>
#include <quan/stm32/gpio.hpp>
#include <quan/stm32/usart/detail/get_irq_number.hpp>
#include <quan/stm32/usart/get_alternate_function.hpp>

/*
 TODO
 add specialisations or options such that if tx or Rx BufferSize is 0 Then its rxonly or txonly etc
*/

namespace quan{ namespace stm32{

   namespace usart{
      template <typename SerialPort> void irq_handler();
   }

   template <
      typename Usart,
      size_t TxBufSize, 
      size_t RxBufSize, 
      typename TxPin, 
      typename RxPin
   >
   struct serial_port{

      typedef Usart usart_type;
      typedef char char_type;
      typedef quan::fifo<char_type,TxBufSize,true> tx_fifo_type;
      typedef quan::fifo<char_type,RxBufSize,true> rx_fifo_type;

      typedef TxPin tx_pin_type;
      typedef RxPin rx_pin_type;
  // private:

      friend void quan::stm32::usart::irq_handler<serial_port>();
      static constexpr uint8_t usart_cr1_rxneie = 5; //(RXNEIE)
      static constexpr uint8_t usart_cr1_txeie = 7; //(TXEIE)
#if defined QUAN_STM32F4
      static constexpr uint8_t usart_sr_rxne = 5;
      static constexpr uint8_t usart_sr_txe = 7;

#else
   #if defined QUAN_STM32F0
      static constexpr uint8_t usart_isr_rxne = 5;
      static constexpr uint8_t usart_isr_txe = 7;
   #else
      #error processor undefined 
   #endif
#endif
      static void enable_rxneie()
      {
#if (QUAN_STM32_HAS_BITBANDING)  
         usart_type::get()->cr1. template bb_setbit<usart_cr1_rxneie>();
#else
         usart_type::get()->cr1. template setbit<usart_cr1_rxneie>(); // bit(5)
#endif
      }

      static void disable_rxneie()
      {
#if (QUAN_STM32_HAS_BITBANDING)  
         usart_type::get()->cr1. template bb_clearbit<usart_cr1_rxneie>();
#else
         usart_type::get()->cr1. template clearbit<usart_cr1_rxneie>(); // bit(5)
#endif
      }

      static void enable_txeie()
      {
#if QUAN_STM32_HAS_BITBANDING 
         usart_type::get()->cr1. template bb_setbit<usart_cr1_txeie>();
#else
         usart_type::get()->cr1. template setbit<usart_cr1_txeie>(); // bit(7)
#endif
      }

      static void disable_txeie()
      {
#if  QUAN_STM32_HAS_BITBANDING  
         usart_type::get()->cr1. template bb_clearbit<usart_cr1_txeie>();
#else
         usart_type::get()->cr1. template clearbit<usart_cr1_txeie>(); // bit(7)
#endif
      }

      static bool ll_tx_reg_empty()
      {
#if defined QUAN_STM32F4
         return  usart_type::get()->sr. template bb_getbit<usart_sr_txe>() ; 
#else
#if defined QUAN_STM32F0
         return  usart_type::get()->isr. template getbit<usart_isr_txe>() ; //bit(7)
#else
#error processor undefined 
#endif
#endif
      }

      static void ll_put( char ch)
      {
#if defined QUAN_STM32F4
         usart_type::get()->dr = ch;
#else
#if defined QUAN_STM32F0
         usart_type::get()->tdr = ch;
#else
#error processor undefined 
#endif
#endif
      }

      static bool ll_rx_reg_full()
      {
#if defined QUAN_STM32F4
        return usart_type::get()->sr. template bb_getbit<usart_sr_rxne>(); 
#else
#if defined QUAN_STM32F0
        return  usart_type::get()->isr. template getbit<usart_isr_rxne>() ; // bit(5)
#else
#error processor undefined 
#endif
#endif
      }

      static char ll_get()
      {
#if defined QUAN_STM32F4
        return static_cast<char>(usart_type::get()->dr);
#else
#if defined QUAN_STM32F0
        return static_cast<char>(usart_type::get()->rdr);
#else
#error processor undefined 
#endif
#endif
      }

      static bool ll_rxneie_is_enabled()
      {
#if QUAN_STM32_HAS_BITBANDING
         return usart_type::get()->cr1.template bb_getbit<usart_cr1_rxneie>();
#else
         return usart_type::get()->cr1.template getbit<usart_cr1_rxneie>(); // bit(5)
#endif
      }

    static bool ll_txeie_is_enabled()
    {
#if QUAN_STM32_HAS_BITBANDING
      return usart_type::get()-> cr1.template bb_getbit<usart_cr1_txeie>();
#else
      return usart_type::get()->cr1.template getbit<usart_cr1_txeie>(); // bit(7)
#endif

   }
   public:
     // add priority
     // baudrate etc
      static void init() 
      {
         m_tx_fifo.init(); 
         m_rx_fifo.init();

         quan::stm32::module_reset<usart_type>();

         quan::stm32::module_enable<usart_type>();

         setup_TxPin();
         setup_RxPin();
// these settings must be applied with usart disabled
         apply<
            usart_type
            ,usart::asynchronous
            ,usart::transmitter<true>
            ,usart::receiver<true>
            ,usart::baud_rate<9600,false>
            ,usart::parity::none
            ,usart::data_bits<8>
            ,usart::stop_bits<1>
            ,usart::rts<false>
            ,usart::cts<false>
            ,usart::i_en::cts<false>
            ,usart::i_en::lbd<false>
            ,usart::i_en::txe<false>
            ,usart::i_en::tc<false>
            ,usart::i_en::rxne<false>
            ,usart::i_en::idle<false>
            ,usart::i_en::pe<false>
            ,usart::i_en::error<false>
         >();

         NVIC_EnableIRQ(quan::stm32::usart::detail::get_irq_number<usart_type>::value);

   // reset the status reg
#if defined QUAN_STM32F4
         usart_type::get()->sr = 0;
#else
#if defined QUAN_STM32F0
     // do we need to reset?
#endif
#endif
         enable_rxneie();

         enable<usart_type>();
      }

       // To set or clear Over consult data sheet
      // n.b usart must be disabled first
      template <uint32_t Baud, bool Over>
      static void set_baudrate()
      {
          // read enabled bit?
         quan::stm32::apply<usart_type,usart::baud_rate<Baud,Over> >();
      }

      static void set_irq_priority(uint32_t priority)
      {
         NVIC_SetPriority(quan::stm32::usart::detail::get_irq_number<usart_type>::value,priority);
      }

      static void put( char ch)
      {
         disable_txeie();
         m_tx_fifo.put(ch);
         enable_txeie();
      }

      static void write(const char* str)
      {
         for ( size_t i = 0, len = strlen(str); i < len; ++i) {
            serial_port::put(str[i]);
         }
      }

      static void write(const char* str, size_t len)
      {
         for ( size_t i = 0; i < len; ++i) {
           serial_port::put(str[i]);
         }
      }

      static uint32_t in_avail()
      {

         disable_rxneie();
         size_t result =  m_rx_fifo.num_in_buffer();
         enable_rxneie();

         return result;
      }

      static char get()
      {
         char result = '\0';
         disable_rxneie();
         if (!m_rx_fifo.is_empty()){
            result = m_rx_fifo.get();
         }
         enable_rxneie();
         return result;
      }
    
   private:

     friend void quan::stm32::usart::irq_handler<serial_port>();
     static tx_fifo_type m_tx_fifo;
     static rx_fifo_type m_rx_fifo;

     typedef typename quan::stm32::get_alternate_function<
         TxPin,usart_type,quan::stm32::usart::tx_pin
     >::type tx_gpio_af_type;

     static_assert(!std::is_same<tx_gpio_af_type,quan::undefined>::value,"tx pin invalid for alternate function");
      typedef typename quan::stm32::get_alternate_function<
         RxPin,usart_type,quan::stm32::usart::rx_pin
     >::type rx_gpio_af_type;

     static_assert(!std::is_same<rx_gpio_af_type,quan::undefined>::value,"rx pin invalid for alternate function");

      static void setup_TxPin()
      {
         module_enable<typename TxPin::port_type>();

         apply<
            TxPin             
            ,tx_gpio_af_type         
            ,gpio::otype::push_pull  
            ,gpio::pupd::none   
            ,gpio::ospeed::slow       
         >();
      }   

      static void setup_RxPin()
      {
         module_enable<typename RxPin::port_type>();

         apply<
            RxPin
            ,rx_gpio_af_type
            ,gpio::pupd::pull_up
            ,gpio::ospeed::slow 
         >();
      }

      serial_port() = delete;
      serial_port(const serial_port &) = delete;
      serial_port operator = (const serial_port &) = delete;
   };

   template <typename Usart,size_t TxBufSize, size_t RxBufSize, typename TxPin, typename RxPin>
   typename serial_port<Usart,TxBufSize,RxBufSize,TxPin,RxPin>::tx_fifo_type 
   serial_port<Usart,TxBufSize,RxBufSize,TxPin,RxPin>::m_tx_fifo;

   template <typename Usart,size_t TxBufSize, size_t RxBufSize, typename TxPin, typename RxPin>
   typename serial_port<Usart,TxBufSize,RxBufSize,TxPin,RxPin>::rx_fifo_type 
   serial_port<Usart,TxBufSize,RxBufSize,TxPin,RxPin>::m_rx_fifo;

}}

namespace quan{ namespace impl{

   template <typename Usart,size_t TxBufSize, size_t RxBufSize, typename TxPin, typename RxPin>
   struct is_model_of_impl<
   quan::StaticPort,
      quan::stm32::serial_port<Usart,TxBufSize,RxBufSize,TxPin,RxPin> 
   >: quan::meta::true_{};

}}

#endif // QUAN_STM32_SERIAL_PORT_HPP_INCLUDED
