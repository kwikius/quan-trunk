#ifndef ARM_MOTOR1_SERIAL_PORT_HPP_INCLUDED
#define ARM_MOTOR1_SERIAL_PORT_HPP_INCLUDED

#include <cstdint>

#include <quan/stm32f4/usart.hpp>
#include <quan/stm32f4/gpio.hpp>
#include <quan/stm32f4/usart/get_irq_num.hpp>

#include <cstring>
#include <quan/utility/fifo.hpp>
#include <type_traits>
#include <quan/meta/if.hpp>
#include <quan/concepts/port.hpp>

/*
 TODO
 add specialisations or options such that if tx or Rx BufferSize is 0 Then its rxonly or txonly etc
*/

namespace quan{ namespace stm32f4{

 namespace usart{
     template <typename SerialPort> void irq_handler();
 }

   template <typename Usart,size_t TxBufSize, size_t RxBufSize, typename TxPin, typename RxPin>
   struct serial_port{

     typedef Usart usart_type;
     typedef char char_type;
     typedef quan::fifo<char_type,TxBufSize> tx_fifo_type;
     typedef quan::fifo<char_type,RxBufSize> rx_fifo_type;

     typedef TxPin tx_pin_type;
     typedef RxPin rx_pin_type;
     
     // add priority
     // baudrate etc
    static void init() 
   {

      m_tx_fifo.init(); 
      m_rx_fifo.init();

      module_reset<usart_type>();

      module_enable<usart_type>();

      setup_TxPin();
      setup_RxPin();

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

      NVIC_EnableIRQ(quan::stm32f4::usart::get_irq_number<usart_type>());
      usart_type::get()->sr =0;
      
      usart_type::get()->cr1. template bb_setbit<5>();//(RXNEIE)
      enable<usart_type>();
    }

    template <uint32_t Baud, bool Over>
    static void set_baudrate()
    {
          apply<usart_type,usart::baud_rate<Baud,Over> >();
    }
    static void set_irq_priority(uint32_t priority)
    {
         NVIC_SetPriority(quan::stm32f4::usart::get_irq_number<usart_type>(),priority);
    }
    static void put( char ch)
    {
       usart_type::get()->cr1.template bb_clearbit<7>(); // (TXEIE)
       m_tx_fifo.put(ch);
       usart_type::get()->cr1. template bb_setbit<7>(); // (TXEIE)

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
      usart_type::get()->cr1. template bb_clearbit<5>();//(RXNEIE)
      size_t result =  m_rx_fifo.num_in_buffer();
      usart_type::get()->cr1. template bb_setbit<5>();//(RXNEIE)
      return result;
    }
    static char get()
    {
      char result = '\0';
      usart_type::get()->cr1. template bb_clearbit<5>();//(RXNEIE)
      if (!m_rx_fifo.is_empty()){
        result = m_rx_fifo.get();
      }
      usart_type::get()->cr1. template bb_setbit<5>();//(RXNEIE)
      return result;
    }
    
    
   private:

     friend void quan::stm32f4::usart::irq_handler<serial_port>();
     static tx_fifo_type m_tx_fifo;
     static rx_fifo_type m_rx_fifo;

      typedef typename quan::meta::if_<
         std::is_same<usart_type,uart4>
         ,gpio::mode::af8
         ,gpio::mode::af7
      >::type gpio_af_type;

      static void setup_TxPin()
      {
         module_enable<typename TxPin::port_type>();

         apply<
            TxPin,              
            gpio_af_type,          
            gpio::otype::push_pull,  
            gpio::pupd::none,        
            gpio::ospeed::slow       
         >();
      }   

      static void setup_RxPin()
      {
           module_enable<typename RxPin::port_type>();

           apply<
            RxPin
            ,gpio_af_type
           , gpio::pupd::pull_up
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
      quan::stm32f4::serial_port<Usart,TxBufSize,RxBufSize,TxPin,RxPin> 
   >: quan::meta::true_{};

}}


#endif // ARM_MOTOR1_SERIAL_PORT_HPP_INCLUDED
