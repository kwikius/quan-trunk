#ifndef QUAN_STM32_USART_ALIAS_USART_SP_IRQ_HPP_INCLUDED
#define QUAN_STM32_USART_ALIAS_USART_SP_IRQ_HPP_INCLUDED

#define QUAN_STM32_ALIAS_USART_SP_IRQ(SerialPort,N) \
extern "C" void USART ## N ## _IRQHandler() __attribute__ ((interrupt ("IRQ"))); \
extern "C" void USART ## N ## _IRQHandler() \
{ \
   static_assert( \
   std::is_same< \
      SerialPort ::usart_type,quan::stm32::usart ## N \
   >::value \
   ,"invalid usart for serial_port irq"); \
   quan::stm32::usart::irq_handler<SerialPort>(); \
}

#endif // QUAN_STM32_USART_ALIAS_USART_SP_IRQ_HPP_INCLUDED
