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
 along with this program. If not, see http://www.gnu.org/licenses.
*/
//

#if ! defined __MBED__
#include <iostream>

#define QUAN_STM32F4
#include <quan/stm32/config.hpp>
#include <quan/stm32/usart/detail/get_baud_rate_values.hpp>
#include <quan/stm32/usart/typedefs.hpp>
#include <quan/stm32/sys_freq.hpp>

int main()
{
  constexpr bool over8 = true;
  constexpr uint32_t baudrate = 9600;
  typedef quan::stm32::usart1 usart;
  
   constexpr uint32_t clock_speed = quan::stm32::get_bus_frequency<
   quan::stm32::detail::get_bus<usart>::type
   >();

   std::cout << "clock speed = " << clock_speed <<'\n';

   typedef quan::stm32::usart::detail::get_baud_rate_values<usart,9600,over8> baud ;

   std::cout << "baud reg = " << baud::value <<'\n';


   uint32_t DIV_Fraction = over8 ?  baud::value & 0x7 : baud::value & 0xF;
   uint32_t DIV_Mantissa =  (baud::value & 0xFFF0) >> 4;

   double UsartDiv = DIV_Mantissa + static_cast<double>(DIV_Fraction)/ (over8?8:16);

   double baudout = static_cast<double>(clock_speed) / ( 8 * (2 - (over8?1:0)) * UsartDiv);

   std::cout << "baud = " << baudout <<'\n';

}

#if 0
#include <quan/stm32f4/detail/system_pll_constants.hpp>
int main()
{
   uint32_t const hse_value = 8000000;
   auto pllm = quan::stm32f4::detail::system_pll_constants::pllm;
   auto plln = quan::stm32f4::detail::system_pll_constants::plln;
   auto pllq = quan::stm32f4::detail::system_pll_constants::pllq;
   auto pllp = quan::stm32f4::detail::system_pll_constants::pllp;

   std::cout << "pllm = "<< pllm <<'\n';
   std::cout << "plln = "<< plln <<'\n';


   // PLL_VCO = (HSE_VALUE or HSI_VALUE / PLL_M) * PLL_N 

   uint32_t const pll_vco = (hse_value / pllm ) * plln;


// plln is for main clk output
   std::cout << "pllp = "<< pllp <<'\n';
   uint32_t main_clk = pll_vco / pllp;
   std::cout << "main_clk = " << main_clk <<'\n';

// pllq is for USB otg clk etc
   std::cout << "pllq = "<< pllq <<'\n';
   uint32_t usb_clk = pll_vco / pllq;

   std::cout << "usb_clk = " << usb_clk <<'\n';

   std::cout << "pll_vco = " << pll_vco <<'\n';
 
}

#endif
#endif

