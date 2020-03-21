
#if ! defined __MBED__
#define QUAN_STM32F4
//#define QUAN_STM32_SYSCLK_Hz 168000000
#define QUAN_STM32_SYSCLK_Hz 72000000

#include <quan/stm32/f4/detail/system_pll_constants.hpp>
#include <quan/stm32/sys_freq.hpp>
#include <quan/stm32/get_module_bus_frequency.hpp>
#include <quan/time.hpp>
#include <quan/frequency.hpp>
#include <quan_matters/test/test.hpp>

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


int errors = 0;

/*
  testing reduced frequency 
*/

int main()
{
 # if 0
   std::cout << "pllm = " << get_pllm() <<'\n';
   std::cout << "plln = " << get_plln() <<'\n';
   std::cout << "pllp = " << get_pllp() <<'\n';
   std::cout << "pllq = " << get_pllq() <<'\n';
#endif 

   uint32_t constexpr hse_value = QUAN_STM32_SOURCE_CLOCK_Hz;
   //std::cout << "HSE = " << hse_value <<'\n';
   uint32_t constexpr target_sysclk = QUAN_STM32_SYSCLK_Hz;

   uint32_t constexpr pll_vco = (hse_value / get_pllm() ) * get_plln();
   uint32_t constexpr sys_clk = pll_vco / get_pllp();
   uint32_t constexpr usb_clock = pll_vco / get_pllq();

   QUAN_CHECK( sys_clk == target_sysclk)

   QUAN_CHECK( usb_clock == 48000000)

   uint32_t const expected_ahb1_freq = target_sysclk;
   QUAN_CHECK(quan::stm32::get_bus_frequency<quan::stm32::detail::ahb1>() == expected_ahb1_freq);

   uint32_t const expected_ahb2_freq = target_sysclk;
   QUAN_CHECK(quan::stm32::get_bus_frequency<quan::stm32::detail::ahb2>() == expected_ahb2_freq);

   uint32_t const expected_ahb3_freq = target_sysclk;
   QUAN_CHECK(quan::stm32::get_bus_frequency<quan::stm32::detail::ahb3>() == expected_ahb3_freq);

   uint32_t const expected_apb1_freq = quan::stm32::get_bus_frequency<quan::stm32::detail::apb1>();
   QUAN_CHECK(expected_apb1_freq == sys_clk / 4); 
   
   uint32_t expected_apb2_freq = quan::stm32::get_bus_frequency<quan::stm32::detail::apb2>();
   QUAN_CHECK(expected_apb2_freq == sys_clk / 2);

   
   EPILOGUE
}

#endif
