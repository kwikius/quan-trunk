
#if ! defined __MBED__
#define QUAN_STM32F4
//#define QUAN_STM32_SYSCLK_Hz 168000000
#define QUAN_STM32_SYSCLK_Hz 84000000

#include <quan/stm32/f4/detail/system_pll_constants.hpp>

typedef quan::stm32::detail::system_pll_constants pll_constants;

constexpr uint32_t get_pllm(){ return pll_constants::pllm;}
constexpr uint32_t get_plln(){ return pll_constants::plln;}
constexpr uint32_t get_pllp(){ return pll_constants::pllp;}
constexpr uint32_t get_pllq(){ return pll_constants::pllq;}

constexpr uint32_t get_ahb1_divider() { return QUAN_STM32_AHB1_DIVISOR;}
constexpr uint32_t get_ahb2_divider() { return QUAN_STM32_AHB2_DIVISOR;}

constexpr uint32_t get_ahb3_divider() { return QUAN_STM32_AHB3_DIVISOR;}

constexpr uint32_t get_apb1_divider() { return QUAN_STM32_APB1_DIVISOR;}
constexpr uint32_t get_apb2_divider() { return QUAN_STM32_APB2_DIVISOR;}

#include <iostream>

int main()
{
  std::cout << "pllm = " << get_pllm() <<'\n';
  std::cout << "plln = " << get_plln() <<'\n';
  std::cout << "pllp = " << get_pllp() <<'\n';
  std::cout << "pllq = " << get_pllq() <<'\n';

  std::cout << "ahb1_divisor = " << get_ahb1_divider() <<'\n';
  std::cout << "ahb2_divisor = " << get_ahb2_divider() <<'\n';
  std::cout << "ahb3_divisor = " << get_ahb3_divider() <<'\n';
  std::cout << "apb1_divisor = " << get_apb1_divider() <<'\n';
  std::cout << "apb2_divisor = " << get_apb2_divider() <<'\n';
}
#endif
