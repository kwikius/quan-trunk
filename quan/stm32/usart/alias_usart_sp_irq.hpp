#ifndef QUAN_STM32_USART_ALIAS_USART_SP_IRQ_HPP_INCLUDED
#define QUAN_STM32_USART_ALIAS_USART_SP_IRQ_HPP_INCLUDED
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
